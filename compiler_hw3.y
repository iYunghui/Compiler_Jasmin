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

    int address = 0;
    int scope_level = 0, next_level = 1;
    struct SymbolTable table[100];
    char *TYPE = "";
    char *PrintType = "";
    char *literal_type = "";
    char *ELEMENT = "-";
    char *assign_operation = "";
    char *id = "";

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(char* name, char* type, int level);
    static void insert_symbol();
    static void lookup_symbol(char* name, char* type);
    static void cast_symbol();
    static void dump_symbol(int level);
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
%type <s_val> Type LogicalOrExpr LogicalAndExpr Expression

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
    : VAR IDENT Type '=' Expression { create_symbol($2, TYPE, scope_level);
                                      literal_type = ""; }
    | VAR IDENT Type                { create_symbol($2, TYPE, scope_level);
                                      literal_type = ""; }
;

ExpressionStmt
    : Expression
;

IncDecStmt
    : Expression INC { printf("INC\n"); }
    | Expression DEC { printf("DEC\n"); }
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
    : Expression { if(strcmp($1, "bool")!=0) 
                       printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, $1); }
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
    : PRINT '(' Expression ')'   { printf("PRINT %s\n", PrintType); }
    | PRINTLN '(' Expression ')' { printf("PRINTLN %s\n", PrintType); }
;

UnaryExpr
    : PrimaryExpr   { $$ = $1; }
    | '+' UnaryExpr { $$ = $2; printf("POS\n"); }
    | '-' UnaryExpr { $$ = $2; printf("NEG\n"); }
    | '!' UnaryExpr { $$ = $2; printf("NOT\n"); }
;

PrimaryExpr
    : Operand            { $$ = $1; }
    | IndexExpr          { $$ = ""; }
    | ConversionExpr     { $$ = ""; }
    | '(' Expression ')' { $$ = ""; }
;

Operand
    : Literal { $$ = $1; }
    | IDENT   { id = strdup(yylval.id_val); lookup_symbol(yylval.id_val, ""); $$ = strdup(PrintType); }
;

Literal
    : INT_LIT            { $$ = "li_int32"; 
                           printf("INT_LIT %d\n", $1); 
                           PrintType = "int32"; 
                           literal_type = "I"; }
    | FLOAT_LIT          { $$ = "float32"; 
                           printf("FLOAT_LIT %f\n", $1);
                           PrintType = "float32"; 
                           literal_type = "F";}
    | '"' STRING_LIT '"' { $$ = "string"; 
                           printf("STRING_LIT %s\n", $2); 
                           PrintType = "string"; }
    | BOOL_LIT           { $$ = "bool"; 
                           printf("%s\n", $1); 
                           PrintType = "bool"; }
;

IndexExpr
    : PrimaryExpr '[' Expression ']' { PrintType = strdup(TYPE); }
;

ConversionExpr
    : Type '(' Expression ')' { cast_symbol(); }
;

MultiplicationExpr
    : UnaryExpr { $$ = $1; }
    | MultiplicationExpr '*' UnaryExpr  { $$ = $1; printf("%s\n", "MUL"); }
    | MultiplicationExpr '/' UnaryExpr  { $$ = $1; printf("%s\n", "QUO"); }
    | MultiplicationExpr '%' UnaryExpr  { $$ = $1; 
                                          if(strcmp($1, "float32")==0 || strcmp($3, "float32")==0) 
                                              printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno); 
                                          printf("%s\n", "REM"); }
;

AdditionExpr
    : MultiplicationExpr { $$ = $1; }
    | AdditionExpr '+' MultiplicationExpr  { $$ = $1; 
                                             if(strcmp($1, "li_int32")==0) 
                                                 $1 = "int32"; 
                                             if(strcmp($3, "li_int32")==0) 
                                                 $3 = "int32"; 
                                             if(strcmp($1, $3)!=0 && strcmp($1, "")!=0 && strcmp($3, "")!=0) 
                                                 printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, $1, $3); 
                                             printf("%s\n", "ADD"); }
    | AdditionExpr '-' MultiplicationExpr  { $$ = $1; 
                                             if(strcmp($1, "li_int32")==0) 
                                                 $1 = "int32"; 
                                             if(strcmp($3, "li_int32")==0) 
                                                 $3 = "int32";
                                             if(strcmp($1, $3)!=0 && strcmp($1, "")!=0 && strcmp($3, "")!=0) 
                                                 printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, $1, $3); 
                                             printf("%s\n", "SUB"); }
;

ComparisonExpr
    : AdditionExpr { $$ = $1; }
    | ComparisonExpr EQL ComparisonExpr { $$ = "bool"; printf("%s\n", "EQL"); }
    | ComparisonExpr NEQ ComparisonExpr { $$ = "bool"; printf("%s\n", "NEQ"); }
    | ComparisonExpr '<' ComparisonExpr { $$ = "bool"; printf("%s\n", "LSS"); }
    | ComparisonExpr LEQ ComparisonExpr { $$ = "bool"; printf("%s\n", "LEQ"); }
    | ComparisonExpr '>' ComparisonExpr { $$ = "bool"; printf("%s\n", "GTR"); }
    | ComparisonExpr GEQ ComparisonExpr { $$ = "bool"; printf("%s\n", "GEQ"); }
;

LogicalAndExpr
    : ComparisonExpr { $$ = $1; }
    | LogicalAndExpr LAND ComparisonExpr { $$ = $1; 
                                           if(strcmp($1, "li_int32")==0) 
                                               $1 = "int32"; 
                                           if(strcmp($3, "li_int32")==0) 
                                               $3 = "int32"; 
                                           if(strcmp($1, "int32")==0 || strcmp($3, "int32")==0) 
                                               printf("error:%d: invalid operation: (operator LAND not defined on int32)\n", yylineno); 
                                           printf("%s\n", "LAND"); }
;

LogicalOrExpr
    : LogicalAndExpr { $$ = $1; }
    | LogicalOrExpr LOR LogicalAndExpr { $$ = $1; 
                                         if(strcmp($1, "li_int32")==0) 
                                             $1 = "int32"; 
                                         if(strcmp($3, "li_int32")==0) 
                                             $3 = "int32"; 
                                         if(strcmp($1, "int32")==0 || strcmp($3, "int32")==0) 
                                             printf("error:%d: invalid operation: (operator LOR not defined on int32)\n", yylineno); 
                                         printf("%s\n", "LOR"); }
;

Assign_op
    : '='        { assign_operation = "ASSIGN"; }
    | ADD_ASSIGN { assign_operation = "ADD_ASSIGN"; }
    | SUB_ASSIGN { assign_operation = "SUB_ASSIGN"; }
    | MUL_ASSIGN { assign_operation = "MUL_ASSIGN"; }
    | QUO_ASSIGN { assign_operation = "QUO_ASSIGN"; }
    | REM_ASSIGN { assign_operation = "REM_ASSIGN"; }
;

Expression
    : LogicalOrExpr { $$ = $1; }
    | UnaryExpr Assign_op Expression { $$ = $1; 
                                       if(strcmp($1, "li_int32")==0) 
                                           printf("error:%d: cannot assign to int32\n", yylineno); 
                                       if(strcmp($1, "li_int32")==0) 
                                           $1 = "int32"; 
                                       if(strcmp($3, "li_int32")==0) 
                                           $3 = "int32"; 
                                       if(strcmp($1, $3)!=0 && strcmp($1, "")!=0 && strcmp($3, "")!=0) 
                                           printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, assign_operation, $1, $3); 
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

    yylineno = 0;
    yyparse();

    dump_symbol(0);
    printf("Total lines: %d\n", yylineno);
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
                PrintType = strdup(table[i].type[j]);
                if(strcmp(PrintType, "array")==0)
                    PrintType = strdup(table[i].element_type[j]);
                return;
            }
        }
    }

    printf("error:%d: undefined: %s\n", yylineno+1, name);
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
    }
    else if(strcmp(TYPE, "int32")==0) {
        printf("%s to I\n", PrintType);
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