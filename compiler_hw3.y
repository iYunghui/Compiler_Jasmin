/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    int isAssign = 0;
    int isArray = 0;
    int address = 0;
    int label = 0;
    int scope_level = 0, next_level = 1;
    struct SymbolTable table[100];
    char *TYPE = "";
    char *PrintType = "";
    char *literal_type = "";
    char *ELEMENT = "-";
    char *assign_operation = "";
    char *id = "";
    FILE *jasmin_file;

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(char* name, char* type, int level);
    static void insert_symbol();
    static void lookup_symbol(char* name, char* type);
    static char* type_symbol(char* name, char* type);
    static void cast_symbol();
    static void dump_symbol(int level);

    static void jasmin_label(char* type, char* op);

    /* Global variables */
    int HAS_ERROR = 0;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    char *id_val;
    char *type_val;
    /* ... */
}

/* Token without return */
%token VAR
%token PRINT PRINTLN IF ELSE FOR
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token INC DEC GEQ LEQ EQL NEQ LAND LOR
%token NEWLINE

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <id_val> IDENT
%token <s_val> STRING_LIT
%token <s_val> BOOL_LIT
%token <type_val> INT
%token <type_val> FLOAT
%token <type_val> STRING
%token <type_val> BOOL

%left '+' '-'
%left '*' '/' '%'

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Literal MultiplicationExpr UnaryExpr AdditionExpr Operand PrimaryExpr ComparisonExpr
%type <s_val> Type LogicalOrExpr LogicalAndExpr Expression ConversionExpr

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList  
;

StatementList
    : StatementList Statement 
    | Statement               
;

Statement
    : DeclarationStmt NEWLINE
    | SimpleStmt NEWLINE
    | Block NEWLINE
    | IfStmt NEWLINE
    | ForStmt NEWLINE
    | PrintStmt NEWLINE
    | NEWLINE
;

DeclarationStmt
    : VAR IDENT Type '=' Expression { isAssign = 1;
                                      create_symbol($2, TYPE, scope_level);
                                      literal_type = ""; }
    | VAR IDENT Type                { create_symbol($2, TYPE, scope_level);
                                      literal_type = ""; }
;

ExpressionStmt
    : Expression
;

IncDecStmt
    : Expression INC { printf("INC\n"); 
                       if(strcmp($1, "int32")==0 || strcmp($1, "li_int32")==0) {
                           fprintf(jasmin_file, "ldc 1\n");
                           fprintf(jasmin_file, "iadd\n");
                       }
                       else {
                           fprintf(jasmin_file, "ldc 1.0\n");
                           fprintf(jasmin_file, "fadd\n"); 
                       }
                       isAssign = 1;
                       lookup_symbol(id, ""); 
                       isAssign = 0;}
    | Expression DEC { printf("DEC\n");
                       if(strcmp($1, "int32")==0 || strcmp($1, "li_int32")==0) {
                           fprintf(jasmin_file, "ldc 1\n");
                           fprintf(jasmin_file, "isub\n");
                       }
                       else {
                           fprintf(jasmin_file, "ldc 1.0\n");
                           fprintf(jasmin_file, "fsub\n"); 
                       }
                       isAssign = 1;
                       lookup_symbol(id, ""); 
                       isAssign = 0;}
;

Block
    : '{' '}'
	| '{' Block_list '}' { dump_symbol(scope_level); 
                           scope_level--; 
                           next_level--; }
;

Block_list
    : Block_item { scope_level = next_level; next_level++; }
	| Block_list Block_item
;

Block_item
    : Statement
;

IfStmt
    : IF Condition Block ELSE IfStmt
    | IF Condition Block ELSE Block
    | IF Condition Block
;

Condition
    : Expression { if(strcmp($1, "bool")!=0) {
                       printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, $1); 
                       HAS_ERROR = 1;
                   }
                 }
;

ForStmt
    : FOR Condition Block
    | FOR ForClause Block
;

ForClause
    : InitStmt ';' Condition ';' PostStmt
;

InitStmt
    : SimpleStmt
;

PostStmt
    : SimpleStmt
;

SimpleStmt
    : ExpressionStmt
    | IncDecStmt
;

PrintStmt
    : PRINT '(' Expression ')'   { printf("PRINT %s\n", PrintType);
                                   if(strcmp($3, "li_int32")==0) 
                                       $3 = "int32";
                                   fprintf(jasmin_file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                   fprintf(jasmin_file, "swap\n");
                                   if(strcmp(PrintType, "int32")==0)
                                       fprintf(jasmin_file, "invokevirtual java/io/PrintStream/print(I)V\n");
                                   else if(strcmp(PrintType, "float32")==0)
                                       fprintf(jasmin_file, "invokevirtual java/io/PrintStream/print(F)V\n");
                                   else if(strcmp(PrintType, "string")==0)
                                       fprintf(jasmin_file, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                   else if(strcmp(PrintType, "bool")==0)
                                       fprintf(jasmin_file, "invokevirtual java/io/PrintStream/print(Z)V\n");}
    | PRINTLN '(' Expression ')' { printf("PRINTLN %s\n", PrintType);
                                   if(strcmp($3, "li_int32")==0) 
                                       $3 = "int32";
                                   fprintf(jasmin_file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                   fprintf(jasmin_file, "swap\n");
                                   if(strcmp(PrintType, "int32")==0)
                                       fprintf(jasmin_file, "invokevirtual java/io/PrintStream/println(I)V\n");
                                   else if(strcmp(PrintType, "float32")==0)
                                       fprintf(jasmin_file, "invokevirtual java/io/PrintStream/println(F)V\n");
                                   else if(strcmp(PrintType, "string")==0)
                                       fprintf(jasmin_file, "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                   else if(strcmp(PrintType, "bool")==0)
                                       fprintf(jasmin_file, "invokevirtual java/io/PrintStream/println(Z)V\n");}
;

UnaryExpr
    : PrimaryExpr   { $$ = $1; }
    | '+' UnaryExpr { $$ = $2; 
                      printf("POS\n");}
    | '-' UnaryExpr { $$ = $2; printf("NEG\n"); 
                      if(strcmp($2, "li_int32")==0)
                          $2 = "int32";
                      if(strcmp($2, "int32")==0)
                          fprintf(jasmin_file, "ineg\n");
                      else
                          fprintf(jasmin_file, "fneg\n");}
    | '!' UnaryExpr { $$ = $2; printf("NOT\n"); 
                      fprintf(jasmin_file, "iconst_1\n");
                      fprintf(jasmin_file, "ixor\n");
                      }
;

PrimaryExpr
    : Operand            { $$ = $1; }
    | IndexExpr          { $$ = ""; }
    | ConversionExpr     { $$ = $1; }
    | '(' Expression ')' { $$ = ""; }
;

Operand
    : Literal { $$ = $1; }
    | IDENT   { id = strdup(yylval.id_val); $$ = type_symbol(id, "");
                if(strcmp(TYPE, "array") != 0)
                    lookup_symbol(yylval.id_val, ""); }
;

Literal
    : INT_LIT            { $$ = "li_int32"; 
                           printf("INT_LIT %d\n", $1); 
                           PrintType = "int32"; 
                           literal_type = "I"; 
                           fprintf(jasmin_file, "ldc %d\n", $1);}
    | FLOAT_LIT          { $$ = "float32"; 
                           printf("FLOAT_LIT %f\n", $1);
                           PrintType = "float32"; 
                           literal_type = "F";
                           fprintf(jasmin_file, "ldc %f\n", $1);}
    | '"' STRING_LIT '"' { $$ = "string"; 
                           printf("STRING_LIT %s\n", $2); 
                           PrintType = "string"; 
                           fprintf(jasmin_file, "ldc \"%s\"\n", $2);}
    | BOOL_LIT           { $$ = "bool"; 
                           printf("%s\n", $1); 
                           PrintType = "bool"; 
                           if(strcmp($1, "TRUE")==0) fprintf(jasmin_file, "iconst_1\n");
                           else if(strcmp($1, "FALSE")==0) fprintf(jasmin_file, "iconst_0\n");}
;

IndexExpr
    : PrimaryExpr '[' Expression ']' { PrintType = strdup(TYPE); isArray = 1; lookup_symbol(id, ""); }
;

ConversionExpr
    : Type '(' Expression ')' { cast_symbol(); $$ = $1; }
;

MultiplicationExpr
    : UnaryExpr { $$ = $1; 
                  if(isArray == 1) {
                      isArray = 2;
                      lookup_symbol(id, "");
                  }}
    | MultiplicationExpr '*' UnaryExpr  { $$ = $1; 
                                          if(strcmp($1, "li_int32")==0) 
                                              $1 = "int32"; 
                                          if(strcmp($3, "li_int32")==0) 
                                              $3 = "int32"; 
                                          printf("%s\n", "MUL"); 
                                          if(strcmp($1, "float32")==0 || strcmp($3, "float32")==0)
                                              fprintf(jasmin_file, "fmul\n");
                                          else
                                              fprintf(jasmin_file, "imul\n");}
    | MultiplicationExpr '/' UnaryExpr  { $$ = $1;  
                                          if(strcmp($1, "li_int32")==0) 
                                              $1 = "int32"; 
                                          if(strcmp($3, "li_int32")==0) 
                                              $3 = "int32"; 
                                          printf("%s\n", "QUO");
                                          if(strcmp($1, "float32")==0 || strcmp($3, "float32")==0)
                                              fprintf(jasmin_file, "fdiv\n");
                                          else
                                              fprintf(jasmin_file, "idiv\n");}
    | MultiplicationExpr '%' UnaryExpr  { $$ = $1; 
                                          if(strcmp($1, "li_int32")==0) 
                                              $1 = "int32"; 
                                          if(strcmp($3, "li_int32")==0) 
                                              $3 = "int32";  
                                          if(strcmp($1, "float32")==0 || strcmp($3, "float32")==0) {
                                              printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno); 
                                              HAS_ERROR = 1;
                                          }
                                          fprintf(jasmin_file, "irem\n");
                                          printf("%s\n", "REM"); }
;

AdditionExpr
    : MultiplicationExpr { $$ = $1; }
    | AdditionExpr '+' MultiplicationExpr  { $$ = $1; 
    printf("++%s\n", $1);
                                             if(strcmp($1, "li_int32")==0) 
                                                 $1 = "int32"; 
                                             if(strcmp($3, "li_int32")==0) 
                                                 $3 = "int32"; 
                                             if(strcmp($1, $3)!=0 && strcmp($1, "")!=0 && strcmp($3, "")!=0) {
                                                 printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, $1, $3); 
                                                 HAS_ERROR = 1;
                                             }
                                             if(strcmp($1, "float32")==0 || strcmp($3, "float32")==0)
                                                 fprintf(jasmin_file, "fadd\n");
                                             else
                                                 fprintf(jasmin_file, "iadd\n");
                                             printf("%s\n", "ADD"); }
    | AdditionExpr '-' MultiplicationExpr  { $$ = $1; 
                                             if(strcmp($1, "li_int32")==0) 
                                                 $1 = "int32"; 
                                             if(strcmp($3, "li_int32")==0) 
                                                 $3 = "int32";
                                             if(strcmp($1, $3)!=0 && strcmp($1, "")!=0 && strcmp($3, "")!=0) {
                                                 printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, $1, $3); 
                                                 HAS_ERROR = 1;
                                             }
                                             if(strcmp($1, "float32")==0 || strcmp($3, "float32")==0)
                                                 fprintf(jasmin_file, "fsub\n");
                                             else
                                                 fprintf(jasmin_file, "isub\n");
                                             printf("%s\n", "SUB"); }
;

ComparisonExpr
    : AdditionExpr { $$ = $1; }
    | ComparisonExpr EQL ComparisonExpr { $$ = "bool"; printf("%s\n", "EQL"); }
    | ComparisonExpr NEQ ComparisonExpr { $$ = "bool"; printf("%s\n", "NEQ"); }
    | ComparisonExpr '<' ComparisonExpr { $$ = "bool"; printf("%s\n", "LSS"); 
                                          if(strcmp($1, "float32")==0 || strcmp($3, "float32")==0)
                                              jasmin_label("float32", "<");
                                          else
                                              jasmin_label("int32", "<");}
    | ComparisonExpr LEQ ComparisonExpr { $$ = "bool"; printf("%s\n", "LEQ"); }
    | ComparisonExpr '>' ComparisonExpr { $$ = "bool"; printf("%s\n", "GTR");  
                                          if(strcmp($1, "float32")==0 || strcmp($3, "float32")==0)
                                              jasmin_label("float32", ">");
                                          else
                                              jasmin_label("int32", ">");}
    | ComparisonExpr GEQ ComparisonExpr { $$ = "bool"; printf("%s\n", "GEQ"); }
;

LogicalAndExpr
    : ComparisonExpr { $$ = $1; }
    | LogicalAndExpr LAND ComparisonExpr { $$ = $1; 
                                           if(strcmp($1, "li_int32")==0) 
                                               $1 = "int32"; 
                                           if(strcmp($3, "li_int32")==0) 
                                               $3 = "int32"; 
                                           if(strcmp($1, "int32")==0 || strcmp($3, "int32")==0) {
                                               printf("error:%d: invalid operation: (operator LAND not defined on int32)\n", yylineno); 
                                               HAS_ERROR = 1;
                                           }
                                           fprintf(jasmin_file, "iand\n");
                                           printf("%s\n", "LAND"); }
;

LogicalOrExpr
    : LogicalAndExpr { $$ = $1; }
    | LogicalOrExpr LOR LogicalAndExpr { $$ = $1; 
                                         if(strcmp($1, "li_int32")==0) 
                                             $1 = "int32"; 
                                         if(strcmp($3, "li_int32")==0) 
                                             $3 = "int32"; 
                                         if(strcmp($1, "int32")==0 || strcmp($3, "int32")==0) { 
                                             printf("error:%d: invalid operation: (operator LOR not defined on int32)\n", yylineno); 
                                             HAS_ERROR = 1;
                                         }
                                         fprintf(jasmin_file, "ior\n");
                                         printf("%s\n", "LOR"); }
;

Assign_op
    : '='        { assign_operation = "ASSIGN"; isArray = 0;}
    | ADD_ASSIGN { assign_operation = "ADD_ASSIGN"; isArray = 0;}
    | SUB_ASSIGN { assign_operation = "SUB_ASSIGN"; isArray = 0;}
    | MUL_ASSIGN { assign_operation = "MUL_ASSIGN"; isArray = 0;}
    | QUO_ASSIGN { assign_operation = "QUO_ASSIGN"; isArray = 0;}
    | REM_ASSIGN { assign_operation = "REM_ASSIGN"; isArray = 0;}
;

Expression
    : LogicalOrExpr { $$ = $1; }
    | IDENT Assign_op Expression     { printf("%s\n", assign_operation);
                                       if(strcmp($3, "li_int32")==0)
                                           $3 = "int32";
                                       if(strcmp(assign_operation, "ADD_ASSIGN") == 0) {
                                           lookup_symbol($1, "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp($3, "float32") == 0)
                                               fprintf(jasmin_file, "fadd\n");
                                           else if(strcmp($3, "int32") == 0)
                                               fprintf(jasmin_file, "iadd\n");
                                       }
                                       else if(strcmp(assign_operation, "SUB_ASSIGN") == 0) {
                                           lookup_symbol($1, "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp($3, "float32") == 0)
                                               fprintf(jasmin_file, "fsub\n");
                                           else if(strcmp($3, "int32") == 0)
                                               fprintf(jasmin_file, "isub\n");
                                       }
                                       else if(strcmp(assign_operation, "MUL_ASSIGN") == 0) {
                                           lookup_symbol($1, "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp($3, "float32") == 0)
                                               fprintf(jasmin_file, "fmul\n");
                                           else if(strcmp($3, "int32") == 0)
                                               fprintf(jasmin_file, "imul\n");
                                       }
                                       else if(strcmp(assign_operation, "QUO_ASSIGN") == 0) {
                                           lookup_symbol($1, "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp($3, "float32") == 0)
                                               fprintf(jasmin_file, "fdiv\n");
                                           else if(strcmp($3, "int32") == 0)
                                               fprintf(jasmin_file, "idiv\n");
                                       }
                                       else if(strcmp(assign_operation, "REM_ASSIGN") == 0) {
                                           lookup_symbol($1, "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp($3, "int32") == 0)
                                               fprintf(jasmin_file, "irem\n");
                                       }
                                       isAssign = 1; 
                                       lookup_symbol($1, "");
                                       isAssign = 0;}
    | UnaryExpr Assign_op Expression { $$ = $1; 
                                       if(strcmp($1, "li_int32")==0) {
                                           printf("error:%d: cannot assign to int32\n", yylineno); 
                                           HAS_ERROR = 1;
                                       }
                                       if(strcmp($1, "li_int32")==0) 
                                           $1 = "int32"; 
                                       if(strcmp($3, "li_int32")==0) 
                                           $3 = "int32"; 
                                       if(strcmp($1, $3)!=0 && strcmp($1, "")!=0 && strcmp($3, "")!=0) {
                                           printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, assign_operation, $1, $3); 
                                           HAS_ERROR = 1;
                                       }
                                       isArray = 0;
                                       isAssign = 1;
                                       lookup_symbol(id, "");
                                       isAssign = 0;
                                       printf("%s\n", assign_operation); }
;

Type
    : INT                     { $$ = $1; TYPE = strdup(yylval.type_val); }
    | FLOAT                   { $$ = $1; TYPE = strdup(yylval.type_val); }
    | STRING                  { $$ = $1; TYPE = strdup(yylval.type_val); }
    | BOOL                    { $$ = $1; TYPE = strdup(yylval.type_val); }
    | '[' Expression ']' Type { $$ = "array"; ELEMENT = strdup(yylval.type_val);}
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /* struct init */
    int i;
    for(i=0; i<100; i++) {
        table[i].index_length = 0;
    }

    /* Jasmin setup code */
    jasmin_file = fopen("hw3.j", "w");
    fprintf(jasmin_file, ".class public Main\n");
    fprintf(jasmin_file, ".super java/lang/Object\n");
    fprintf(jasmin_file, ".method public static main([Ljava/lang/String;)V\n");
    fprintf(jasmin_file, ".limit stack 100\n");
    fprintf(jasmin_file, ".limit locals 100\n\n");    

    yylineno = 0;
    yyparse();

    fprintf(jasmin_file, "return\n");
    fprintf(jasmin_file, ".end method\n");
    if(HAS_ERROR) {
        remove("hw3.j");
    }
    
    dump_symbol(0);
    printf("Total lines: %d\n", yylineno);
    fclose(jasmin_file);
    fclose(yyin);

    
    return 0;
}

static void create_symbol(char* name, char* type, int level) {
    int num = table[level].index_length;
    for(int i=0; i<num; i++) {
        if(strcmp(name, table[level].name[i])==0) {
            char error_message[1024];
            sprintf(error_message, "%s redeclared in this block. previous declaration at line %d", name, table[level].lineno[i]);
            yyerror(error_message);
            return;
        }
    }

    if(strcmp(ELEMENT,"-")!=0)
        type = "array";

    table[level].index[num] = num;
    table[level].index_length++;
    table[level].name[num] = strdup(name);
    table[level].type[num] = strdup(type);
    table[level].address[num] = address++;
    table[level].lineno[num] = yylineno;
    table[level].element_type[num] = strdup(ELEMENT);
    ELEMENT = "-";
    
    insert_symbol(table[level].name[num], level);
    if(isAssign == 0) {
        if(strcmp("int32", table[level].type[num]) == 0) {
            fprintf(jasmin_file, "ldc 0\n");
        }
        else if(strcmp("float32", table[level].type[num]) == 0) {
            fprintf(jasmin_file, "ldc 0.0\n");
        }
        else if(strcmp("bool", table[level].type[num]) == 0) {
            fprintf(jasmin_file, "iconst_0\n");
        } 
        else if(strcmp("string", table[level].type[num]) == 0) {
            fprintf(jasmin_file, "ldc \"\"\n");
        }        
    }

    if(strcmp("int32", table[level].type[num]) == 0)
        fprintf(jasmin_file, "istore %d\n", table[level].address[num]);
    else if(strcmp("float32", table[level].type[num]) == 0)
        fprintf(jasmin_file, "fstore %d\n", table[level].address[num]);
    else if(strcmp("bool", table[level].type[num]) == 0)
        fprintf(jasmin_file, "istore %d\n", table[level].address[num]);
    else if(strcmp("array", table[level].type[num]) == 0) {
        if(strcmp("int32", table[level].element_type[num]) == 0)
            fprintf(jasmin_file, "newarray int\n");
        else if(strcmp("float32", table[level].element_type[num]) == 0)
            fprintf(jasmin_file, "newarray float\n");
        fprintf(jasmin_file, "astore %d\n", table[level].address[num]);
    }

    isAssign = 0;
}

static void insert_symbol(char* name, int level) {
    printf("> Insert {%s} into symbol table (scope level: %d)\n", name, level);
}

static void lookup_symbol(char* name, char* type) {
    int i,j;
    int num;

    for(i=scope_level; i>=0; i--) {
        num = table[i].index_length;
        for(j=0; j<num; j++) {
            if(strcmp(name, table[i].name[j])==0 && (strcmp(type, table[i].type[j])==0 || strcmp(type, "")==0)) {
                printf("IDENT (name=%s, address=%d)\n", name, table[i].address[j]);
                if(isAssign==0 && isArray==0) {
                    if(strcmp("int32", table[i].type[j]) == 0)
                        fprintf(jasmin_file, "iload %d\n", table[i].address[j]);
                    else if(strcmp("float32", table[i].type[j]) == 0)
                        fprintf(jasmin_file, "fload %d\n", table[i].address[j]);
                    else if(strcmp("bool", table[i].type[j]) == 0)
                        fprintf(jasmin_file, "iload %d\n", table[i].address[j]);
                    else if(strcmp("array", table[i].type[j]) == 0)
                        fprintf(jasmin_file, "aload %d\n", table[i].address[j]);
                }
                else if(isAssign==0 && isArray==2) {
                    if(strcmp("array", table[i].type[j]) == 0) {
                        if(strcmp("int32", table[i].element_type[j]) == 0)
                            fprintf(jasmin_file, "iaload\n");
                        else if(strcmp("float32", table[i].element_type[j]) == 0)
                            fprintf(jasmin_file, "faload\n");
                    }
                }
                else if(isArray == 0) {
                    if(strcmp("int32", table[i].type[j]) == 0)
                        fprintf(jasmin_file, "istore %d\n", table[i].address[j]);
                    else if(strcmp("float32", table[i].type[j]) == 0)
                        fprintf(jasmin_file, "fstore %d\n", table[i].address[j]);
                    else if(strcmp("bool", table[i].type[j]) == 0)
                        fprintf(jasmin_file, "istore %d\n", table[i].address[j]);
                    else if(strcmp("array", table[i].type[j]) == 0) {
                        if(strcmp("int32", table[i].element_type[j]) == 0)
                            fprintf(jasmin_file, "iastore\n");
                        else if(strcmp("float32", table[i].element_type[j]) == 0)
                            fprintf(jasmin_file, "fastore\n");
                    }
                }
                if(isArray != 1)
                    isArray = 0;
                //isAssign = 0;
                PrintType = strdup(table[i].type[j]);
                if(strcmp(PrintType, "array")==0)
                    PrintType = strdup(table[i].element_type[j]);
                return;
            }
        }
    }

    printf("error:%d: undefined: %s\n", yylineno+1, name);
}

static char* type_symbol(char* name, char* type) {
    int i,j;
    int num;

    for(i=scope_level; i>=0; i--) {
        num = table[i].index_length;
        for(j=0; j<num; j++) {
            if(strcmp(name, table[i].name[j])==0 && (strcmp(type, table[i].type[j])==0 || strcmp(type, "")==0)) {
                PrintType = strdup(table[i].type[j]);
                if(strcmp(PrintType, "array")==0)
                    PrintType = strdup(table[i].element_type[j]);
                return PrintType;
            }
        }
    }
    return "";
}

static void cast_symbol() {
    if(strcmp(literal_type, "")==0) {
        if(strcmp(PrintType, "float32")==0) PrintType = "F";
        else if(strcmp(PrintType, "int32")==0) PrintType = "I";
    }
    else
        PrintType = strdup(literal_type);

    if(strcmp(TYPE, "float32")==0) {
        printf("%s to F\n", PrintType);
        fprintf(jasmin_file, "i2f\n");
    }
    else if(strcmp(TYPE, "int32")==0) {
        printf("%s to I\n", PrintType);
        fprintf(jasmin_file, "f2i\n");
    }

    literal_type = "";
}

static void dump_symbol(int level) {
    printf("> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    int i = 0;
    for(i=0; i<table[level].index_length; i++) {
        printf("%-10d%-10s%-10s%-10d%-10d%s\n", table[level].index[i], table[level].name[i], table[level].type[i], table[level].address[i], table[level].lineno[i], table[level].element_type[i]);
    }
    table[level].index_length = 0;
}

static void jasmin_label(char* type, char* op) {
    char label_name[10], next_label_name[10];
    sprintf(label_name, "L_cmp_%d", label);
    label++;
    sprintf(next_label_name, "L_cmp_%d", label);
    label++;

    if(strcmp(type, "int32") == 0) {
        fprintf(jasmin_file, "isub\n");
    }
    else if(strcmp(type, "float32") == 0) {
        fprintf(jasmin_file, "fsub\n");
        fprintf(jasmin_file, "f2i\n");
    }

    fprintf(jasmin_file, "ifgt %s\n", label_name);
    fprintf(jasmin_file, "iconst_0\n");
    fprintf(jasmin_file, "goto %s\n", next_label_name);
    fprintf(jasmin_file, "%s:\n", label_name);
    fprintf(jasmin_file, "iconst_1\n\n");
    fprintf(jasmin_file, "%s:\n", next_label_name);
}
