/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

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
    int fornum = 0;
    int forinit = 0;
    int forpostnum = 0;
    int ifnum = 0;
    int scope_level = 0, next_level = 1;
    struct SymbolTable table[100];
    char *TYPE = "";
    char *PrintType = "";
    char *literal_type = "";
    char *ELEMENT = "-";
    char *assign_operation = "";
    char *id = "";
    char forpost1[1024] = {'\0'};
    char forpost2[1024] = {'\0'};
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

#line 114 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    PRINT = 259,
    PRINTLN = 260,
    IF = 261,
    ELSE = 262,
    FOR = 263,
    ADD_ASSIGN = 264,
    SUB_ASSIGN = 265,
    MUL_ASSIGN = 266,
    QUO_ASSIGN = 267,
    REM_ASSIGN = 268,
    INC = 269,
    DEC = 270,
    GEQ = 271,
    LEQ = 272,
    EQL = 273,
    NEQ = 274,
    LAND = 275,
    LOR = 276,
    NEWLINE = 277,
    INT_LIT = 278,
    FLOAT_LIT = 279,
    IDENT = 280,
    STRING_LIT = 281,
    BOOL_LIT = 282,
    INT = 283,
    FLOAT = 284,
    STRING = 285,
    BOOL = 286
  };
#endif
/* Tokens.  */
#define VAR 258
#define PRINT 259
#define PRINTLN 260
#define IF 261
#define ELSE 262
#define FOR 263
#define ADD_ASSIGN 264
#define SUB_ASSIGN 265
#define MUL_ASSIGN 266
#define QUO_ASSIGN 267
#define REM_ASSIGN 268
#define INC 269
#define DEC 270
#define GEQ 271
#define LEQ 272
#define EQL 273
#define NEQ 274
#define LAND 275
#define LOR 276
#define NEWLINE 277
#define INT_LIT 278
#define FLOAT_LIT 279
#define IDENT 280
#define STRING_LIT 281
#define BOOL_LIT 282
#define INT 283
#define FLOAT 284
#define STRING 285
#define BOOL 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 55 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;
    char *id_val;
    char *type_val;
    /* ... */

#line 225 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    44,     2,     2,    36,     2,     2,
      41,    42,    34,    32,     2,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      47,    37,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   100,   101,   105,   106,   107,   108,   109,
     110,   111,   115,   118,   123,   127,   159,   193,   194,   227,
     228,   232,   236,   240,   244,   251,   255,   272,   275,   281,
     288,   291,   288,   295,   299,   303,   304,   308,   321,   337,
     338,   340,   347,   354,   355,   356,   357,   361,   362,   368,
     373,   378,   382,   390,   394,   398,   403,   413,   423,   437,
     438,   453,   470,   471,   476,   477,   482,   487,   492,   496,
     497,   511,   512,   526,   527,   528,   529,   530,   531,   535,
     536,   580,   601,   602,   603,   604,   605
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "PRINT", "PRINTLN", "IF", "ELSE",
  "FOR", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN",
  "REM_ASSIGN", "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ", "LAND", "LOR",
  "NEWLINE", "INT_LIT", "FLOAT_LIT", "IDENT", "STRING_LIT", "BOOL_LIT",
  "INT", "FLOAT", "STRING", "BOOL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'='", "'{'", "'}'", "';'", "'('", "')'", "'!'", "'\"'", "'['", "']'",
  "'<'", "'>'", "$accept", "Program", "StatementList", "Statement",
  "DeclarationStmt", "ExpressionStmt", "IncDecStmt", "Block", "Block_list",
  "Block_item", "IfStmt", "IFsym", "Condition", "ForStmt", "FORsym",
  "ForClause", "$@1", "$@2", "InitStmt", "PostStmt", "SimpleStmt",
  "PrintStmt", "UnaryExpr", "PrimaryExpr", "Operand", "Literal",
  "IndexExpr", "ConversionExpr", "MultiplicationExpr", "AdditionExpr",
  "ComparisonExpr", "LogicalAndExpr", "LogicalOrExpr", "Assign_op",
  "Expression", "Type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    43,    45,    42,    47,    37,    61,   123,   125,
      59,    40,    41,    33,    34,    91,    93,    60,    62
};
# endif

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -27

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     142,   -17,   -28,   -21,   -69,   -69,   -69,   -69,   -69,    62,
     -69,   -69,   -69,   -69,   -69,   165,   165,    18,   188,   165,
      12,   188,    25,   142,   -69,   -11,   -69,   -69,     8,    22,
     188,    36,   188,    38,    48,    62,    67,   -69,   -69,   -69,
     -69,    19,    52,    17,    93,    95,     3,    76,    80,   188,
     188,   -69,   -69,   -69,   -69,   -69,   -69,   188,   -69,   -69,
     -69,   -69,   -69,    99,   -69,    78,   -69,    74,    87,   -69,
     -69,   -69,   -69,   -69,    96,   -69,   -69,    96,    96,   -69,
     -69,    14,   -69,   -69,   188,   188,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   -69,
     -69,   188,    98,    94,    97,   -69,   -69,   -69,   -69,   -69,
      80,   134,   -69,   -69,   109,   -69,   105,   -69,   -69,   -69,
     -69,    19,    19,    17,    17,    17,    17,    17,    17,    17,
      93,   110,   188,   -69,   -69,   -69,    -1,   188,   -69,   -69,
     -69,   -69,   -69,   -69,   113,   188,   -69,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    25,    29,    11,    49,    50,    48,
      52,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     4,     0,    35,    36,     0,     0,
       0,     0,     0,     0,     0,    55,    39,    43,    47,    44,
      45,    59,    62,    69,    71,    79,    14,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    73,     0,    48,    40,
      41,    17,    21,     0,    19,     0,    42,     0,     0,     1,
       3,     5,     7,     8,     0,    26,     9,     0,     0,    30,
      33,    14,     6,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,    13,     0,     0,    80,    18,    20,    46,    51,
       0,    24,    27,    28,     0,    81,     0,    56,    57,    58,
      55,    60,    61,    68,    66,    63,    64,    65,    67,    70,
      72,     0,     0,    37,    38,    86,     0,     0,    53,    54,
      12,    23,    22,    31,     0,     0,    32,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,   -69,     4,   -69,   -69,   -69,   -68,   -69,    91,
      20,   -69,   -31,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -30,   -69,     0,   -69,   -69,   -69,   -69,   -69,    11,   -69,
     -15,    57,   -69,   122,   -18,   -41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    62,    25,    26,    27,    28,    63,    64,
      29,    30,    74,    31,    32,    78,   114,   144,    79,   146,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    57,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    77,    80,    68,    24,     4,   111,   102,    48,   112,
     113,    71,    75,    49,    81,    59,    60,    99,   100,    66,
      50,     1,     2,     3,     4,    69,     5,    70,    99,   100,
      72,   103,   104,    91,    92,    93,    94,    17,    67,   105,
       6,     7,     8,     9,    73,    10,    11,    12,    13,    14,
      15,    16,   -26,    86,    87,    88,    17,    61,    76,    18,
      82,    19,    20,    21,    95,    96,   115,   116,   141,   135,
      83,    51,    52,    53,    54,    55,   123,   124,   125,   126,
     127,   128,   129,   131,    89,    90,   117,   118,   119,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,    56,
     121,   122,     1,     2,     3,     4,   143,     5,    11,    12,
      13,    14,    85,    97,   140,   147,    98,   101,   109,    75,
     108,     6,     7,     8,     9,    21,    10,    11,    12,    13,
      14,    15,    16,   110,    17,   132,   133,    17,   106,   134,
      18,   136,    19,    20,    21,     1,     2,     3,     4,   137,
       5,   138,   139,   145,   107,   130,   142,    84,     0,     0,
       0,     0,     0,     0,     6,     7,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
      17,     0,     0,    18,     0,    19,    20,    21,     7,     8,
      58,     0,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,    18,     0,    19,    20,
      21,     7,     8,     9,     0,    10,    11,    12,    13,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,    18,
       0,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      18,    32,    32,    21,     0,     6,    74,    48,    25,    77,
      78,    22,    30,    41,    32,    15,    16,    14,    15,    19,
      41,     3,     4,     5,     6,     0,     8,    23,    14,    15,
      22,    49,    50,    16,    17,    18,    19,    38,    26,    57,
      22,    23,    24,    25,    22,    27,    28,    29,    30,    31,
      32,    33,    38,    34,    35,    36,    38,    39,    22,    41,
      22,    43,    44,    45,    47,    48,    84,    85,   136,   110,
      22,     9,    10,    11,    12,    13,    91,    92,    93,    94,
      95,    96,    97,   101,    32,    33,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    37,
      89,    90,     3,     4,     5,     6,   137,     8,    28,    29,
      30,    31,    45,    20,   132,   145,    21,    41,    44,   137,
      42,    22,    23,    24,    25,    45,    27,    28,    29,    30,
      31,    32,    33,    46,    38,    37,    42,    38,    39,    42,
      41,     7,    43,    44,    45,     3,     4,     5,     6,    40,
       8,    46,    42,    40,    63,    98,   136,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    43,    44,    45,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    44,
      45,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,    22,    23,    24,    25,
      27,    28,    29,    30,    31,    32,    33,    38,    41,    43,
      44,    45,    50,    51,    52,    53,    54,    55,    56,    59,
      60,    62,    63,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    83,    84,    25,    41,
      41,     9,    10,    11,    12,    13,    37,    82,    25,    71,
      71,    39,    52,    57,    58,    83,    71,    26,    83,     0,
      52,    22,    22,    22,    61,    83,    22,    61,    64,    67,
      69,    83,    22,    22,    82,    45,    34,    35,    36,    32,
      33,    16,    17,    18,    19,    47,    48,    20,    21,    14,
      15,    41,    84,    83,    83,    83,    39,    58,    42,    44,
      46,    56,    56,    56,    65,    83,    83,    71,    71,    71,
      71,    77,    77,    79,    79,    79,    79,    79,    79,    79,
      80,    83,    37,    42,    42,    84,     7,    40,    46,    42,
      83,    56,    59,    61,    66,    40,    68,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    58,    59,    59,    59,    60,    61,    62,    62,    63,
      65,    66,    64,    67,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    72,    72,    72,    72,    73,    73,    74,
      74,    74,    74,    75,    76,    77,    77,    77,    77,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    83,
      83,    83,    84,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     5,     3,     1,     2,     2,     2,     3,     1,
       2,     1,     5,     5,     3,     1,     1,     3,     3,     1,
       0,     0,     7,     1,     1,     1,     1,     4,     4,     1,
       2,     2,     2,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     4,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 12:
#line 115 "compiler_hw3.y" /* yacc.c:1646  */
    { isAssign = 1;
                                      create_symbol((yyvsp[-3].id_val), TYPE, scope_level);
                                      literal_type = ""; }
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol((yyvsp[-1].id_val), TYPE, scope_level);
                                      literal_type = ""; }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 127 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("INC\n");
                       char forpost[1024] = {'\0'};
                       if(strcmp((yyvsp[-1].s_val), "int32")==0 || strcmp((yyvsp[-1].s_val), "li_int32")==0) {
                           if((forpostnum-1)==scope_level && forpostnum>0) {
                               strcat(forpost, "ldc 1\n");
                               strcat(forpost, "iadd\n\n");
                           }
                           else {
                               fprintf(jasmin_file, "ldc 1\n");
                               fprintf(jasmin_file, "iadd\n");
                           }
                       }
                       else {
                           if((forpostnum-1)==scope_level && forpostnum>0) {
                               strcat(forpost, "ldc 1.0\n");
                               strcat(forpost, "fadd\n\n");
                           }
                           else {
                               fprintf(jasmin_file, "ldc 1.0\n");
                               fprintf(jasmin_file, "fadd\n"); 
                           }
                       }
                       if(forpostnum == 1) {
                           strcat(forpost1, forpost);
                       }
                       else if(forpostnum == 2) {
                           strcat(forpost2, forpost);
                       }
                       isAssign = 1;
                       printf("&&&&&&&& %d %d\n", forpostnum, scope_level);
                       lookup_symbol(id, ""); 
                       isAssign = 0;}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("DEC\n");
                       char forpost[1024] = {'\0'};
                       if(strcmp((yyvsp[-1].s_val), "int32")==0 || strcmp((yyvsp[-1].s_val), "li_int32")==0) {
                           if((forpostnum-1)==scope_level && forpostnum>0) {
                               strcat(forpost, "ldc 1\n");
                               strcat(forpost, "isub\n\n");
                           }
                           else {
                               fprintf(jasmin_file, "ldc 1\n");
                               fprintf(jasmin_file, "isub\n");
                           }
                       }
                       else {
                           if((forpostnum-1)==scope_level && forpostnum>0) {
                               strcat(forpost, "ldc 1.0\n");
                               strcat(forpost, "fsub\n\n");
                           }
                           else {
                               fprintf(jasmin_file, "ldc 1.0\n");
                               fprintf(jasmin_file, "fsub\n"); 
                           }
                       }
                       if(forpostnum == 1) {
                           strcat(forpost1, forpost);
                       }
                       else if(forpostnum == 2) {
                           strcat(forpost2, forpost);
                       }
                       isAssign = 1;
                       lookup_symbol(id, ""); 
                       isAssign = 0;}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 194 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(scope_level); 
                           scope_level--; 
                           next_level--; 
                           if(fornum > 0) {
                               if(forinit == 1) {
                                   fprintf(jasmin_file, "%s", forpost1);
                                   printf("+++++%s\n", forpost1);
                                   printf("++++++++++++++\n");
                                   forpost1[0] = '\0';
                               }
                               else if(forinit == 2) {
                                   fprintf(jasmin_file, "%s", forpost2);

                                   printf("-----%s\n", forpost2);
                                   printf("--------------\n");
                                   forpost2[0] = '\0';
                               }
                               char temp[20];
                               if(forinit > 0)
                                   sprintf(temp, "L_for_begin_init%d", forinit);
                               else
                                   sprintf(temp, "L_for_begin%d", fornum);
                               fprintf(jasmin_file, "goto %s\n", temp);
                           }
                           if(ifnum > 0) {
                               char temp[20];
                               sprintf(temp, "L_if_exit%d", ifnum);
                               fprintf(jasmin_file, "goto %s\n", temp); 
                               sprintf(temp, "L_if_false%d", ifnum);
                               fprintf(jasmin_file, "%s:\n", temp);}}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 227 "compiler_hw3.y" /* yacc.c:1646  */
    { scope_level = next_level; next_level++; }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 236 "compiler_hw3.y" /* yacc.c:1646  */
    { char temp[20];
                                          sprintf(temp, "L_if_exit%d", ifnum);
                                          fprintf(jasmin_file, "%s:\n", temp); 
                                          ifnum--; }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 240 "compiler_hw3.y" /* yacc.c:1646  */
    { char temp[20];
                                          sprintf(temp, "L_if_exit%d", ifnum);
                                          fprintf(jasmin_file, "%s:\n", temp); 
                                          ifnum--; }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 244 "compiler_hw3.y" /* yacc.c:1646  */
    { char temp[20];
                                          sprintf(temp, "L_if_exit%d", ifnum);
                                          fprintf(jasmin_file, "%s:\n", temp); 
                                          ifnum--; }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 251 "compiler_hw3.y" /* yacc.c:1646  */
    { ifnum++; }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 255 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[0].s_val), "bool")!=0) {
                       printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, (yyvsp[0].s_val)); 
                       HAS_ERROR = 1;
                   }
                   if(fornum > 0) {
                       char temp[20];
                       sprintf(temp, "L_for_exit%d", fornum);
                       fprintf(jasmin_file, "ifeq %s\n", temp);
                   }
                   if(ifnum > 0) {
                       char temp[20];
                       sprintf(temp, "L_if_false%d", ifnum);
                       fprintf(jasmin_file, "ifeq %s\n", temp);}
                 }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 272 "compiler_hw3.y" /* yacc.c:1646  */
    { char temp[20];
                               sprintf(temp, "L_for_exit%d", fornum);
                               fprintf(jasmin_file, "%s:\n", temp); fornum--; }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 275 "compiler_hw3.y" /* yacc.c:1646  */
    { char temp[20];
                               sprintf(temp, "L_for_exit%d", fornum);
                               fprintf(jasmin_file, "%s:\n", temp); fornum--; forinit--; if(forinit==0) forpostnum = 0;}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 281 "compiler_hw3.y" /* yacc.c:1646  */
    { fornum++; 
            char temp[20];
            sprintf(temp, "L_for_begin%d", fornum);
            fprintf(jasmin_file, "%s:\n", temp); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 288 "compiler_hw3.y" /* yacc.c:1646  */
    { forinit++; 
                 char temp[20];
                 sprintf(temp, "L_for_begin_init%d", forinit);
                 fprintf(jasmin_file, "%s:\n", temp); }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 291 "compiler_hw3.y" /* yacc.c:1646  */
    { forpostnum++;}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 308 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("PRINT %s\n", PrintType);
                                   if(strcmp((yyvsp[-1].s_val), "li_int32")==0) 
                                       (yyvsp[-1].s_val) = "int32";
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
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 321 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("PRINTLN %s\n", PrintType);
                                   if(strcmp((yyvsp[-1].s_val), "li_int32")==0) 
                                       (yyvsp[-1].s_val) = "int32";
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
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 337 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 338 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); 
                      printf("POS\n");}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 340 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); printf("NEG\n"); 
                      if(strcmp((yyvsp[0].s_val), "li_int32")==0)
                          (yyvsp[0].s_val) = "int32";
                      if(strcmp((yyvsp[0].s_val), "int32")==0)
                          fprintf(jasmin_file, "ineg\n");
                      else
                          fprintf(jasmin_file, "fneg\n");}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 347 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); printf("NOT\n"); 
                      fprintf(jasmin_file, "iconst_1\n");
                      fprintf(jasmin_file, "ixor\n");
                      }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 354 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 355 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = ""; }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 356 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 357 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = ""; }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 361 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 362 "compiler_hw3.y" /* yacc.c:1646  */
    { id = strdup(yylval.id_val); (yyval.s_val) = type_symbol(id, "");
                if(strcmp(TYPE, "array") != 0)
                    lookup_symbol(yylval.id_val, ""); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 368 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "li_int32"; 
                           printf("INT_LIT %d\n", (yyvsp[0].i_val)); 
                           PrintType = "int32"; 
                           literal_type = "I"; 
                           fprintf(jasmin_file, "ldc %d\n", (yyvsp[0].i_val));}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 373 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "float32"; 
                           printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
                           PrintType = "float32"; 
                           literal_type = "F";
                           fprintf(jasmin_file, "ldc %f\n", (yyvsp[0].f_val));}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 378 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "string"; 
                           printf("STRING_LIT %s\n", (yyvsp[-1].s_val)); 
                           PrintType = "string"; 
                           fprintf(jasmin_file, "ldc \"%s\"\n", (yyvsp[-1].s_val));}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 382 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; 
                           printf("%s\n", (yyvsp[0].s_val)); 
                           PrintType = "bool"; 
                           if(strcmp((yyvsp[0].s_val), "TRUE")==0) fprintf(jasmin_file, "iconst_1\n");
                           else if(strcmp((yyvsp[0].s_val), "FALSE")==0) fprintf(jasmin_file, "iconst_0\n");}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 390 "compiler_hw3.y" /* yacc.c:1646  */
    { PrintType = strdup(TYPE); isArray = 1; lookup_symbol(id, ""); }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 394 "compiler_hw3.y" /* yacc.c:1646  */
    { cast_symbol(); (yyval.s_val) = (yyvsp[-3].s_val); }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 398 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); 
                  if(isArray == 1) {
                      isArray = 2;
                      lookup_symbol(id, "");
                  }}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 403 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-2].s_val); 
                                          if(strcmp((yyvsp[-2].s_val), "li_int32")==0) 
                                              (yyvsp[-2].s_val) = "int32"; 
                                          if(strcmp((yyvsp[0].s_val), "li_int32")==0) 
                                              (yyvsp[0].s_val) = "int32"; 
                                          printf("%s\n", "MUL"); 
                                          if(strcmp((yyvsp[-2].s_val), "float32")==0 || strcmp((yyvsp[0].s_val), "float32")==0)
                                              fprintf(jasmin_file, "fmul\n");
                                          else
                                              fprintf(jasmin_file, "imul\n");}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 413 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-2].s_val);  
                                          if(strcmp((yyvsp[-2].s_val), "li_int32")==0) 
                                              (yyvsp[-2].s_val) = "int32"; 
                                          if(strcmp((yyvsp[0].s_val), "li_int32")==0) 
                                              (yyvsp[0].s_val) = "int32"; 
                                          printf("%s\n", "QUO");
                                          if(strcmp((yyvsp[-2].s_val), "float32")==0 || strcmp((yyvsp[0].s_val), "float32")==0)
                                              fprintf(jasmin_file, "fdiv\n");
                                          else
                                              fprintf(jasmin_file, "idiv\n");}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 423 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-2].s_val); 
                                          if(strcmp((yyvsp[-2].s_val), "li_int32")==0) 
                                              (yyvsp[-2].s_val) = "int32"; 
                                          if(strcmp((yyvsp[0].s_val), "li_int32")==0) 
                                              (yyvsp[0].s_val) = "int32";  
                                          if(strcmp((yyvsp[-2].s_val), "float32")==0 || strcmp((yyvsp[0].s_val), "float32")==0) {
                                              printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno); 
                                              HAS_ERROR = 1;
                                          }
                                          fprintf(jasmin_file, "irem\n");
                                          printf("%s\n", "REM"); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 437 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 438 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-2].s_val); 
    printf("++%s\n", (yyvsp[-2].s_val));
                                             if(strcmp((yyvsp[-2].s_val), "li_int32")==0) 
                                                 (yyvsp[-2].s_val) = "int32"; 
                                             if(strcmp((yyvsp[0].s_val), "li_int32")==0) 
                                                 (yyvsp[0].s_val) = "int32"; 
                                             if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val))!=0 && strcmp((yyvsp[-2].s_val), "")!=0 && strcmp((yyvsp[0].s_val), "")!=0) {
                                                 printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, (yyvsp[-2].s_val), (yyvsp[0].s_val)); 
                                                 HAS_ERROR = 1;
                                             }
                                             if(strcmp((yyvsp[-2].s_val), "float32")==0 || strcmp((yyvsp[0].s_val), "float32")==0)
                                                 fprintf(jasmin_file, "fadd\n");
                                             else
                                                 fprintf(jasmin_file, "iadd\n");
                                             printf("%s\n", "ADD"); }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 453 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-2].s_val); 
                                             if(strcmp((yyvsp[-2].s_val), "li_int32")==0) 
                                                 (yyvsp[-2].s_val) = "int32"; 
                                             if(strcmp((yyvsp[0].s_val), "li_int32")==0) 
                                                 (yyvsp[0].s_val) = "int32";
                                             if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val))!=0 && strcmp((yyvsp[-2].s_val), "")!=0 && strcmp((yyvsp[0].s_val), "")!=0) {
                                                 printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, (yyvsp[-2].s_val), (yyvsp[0].s_val)); 
                                                 HAS_ERROR = 1;
                                             }
                                             if(strcmp((yyvsp[-2].s_val), "float32")==0 || strcmp((yyvsp[0].s_val), "float32")==0)
                                                 fprintf(jasmin_file, "fsub\n");
                                             else
                                                 fprintf(jasmin_file, "isub\n");
                                             printf("%s\n", "SUB"); }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 470 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 471 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; printf("%s\n", "EQL"); 
                                          if(strcmp((yyvsp[-2].s_val), "float32")==0 || strcmp((yyvsp[0].s_val), "float32")==0)
                                              jasmin_label("float32", "==");
                                          else
                                              jasmin_label("int32", "==");}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 476 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; printf("%s\n", "NEQ"); }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 477 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; printf("%s\n", "LSS"); 
                                          if(strcmp((yyvsp[-2].s_val), "float32")==0 || strcmp((yyvsp[0].s_val), "float32")==0)
                                              jasmin_label("float32", "<");
                                          else
                                              jasmin_label("int32", "<");}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 482 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; printf("%s\n", "LEQ"); 
                                          if(strcmp((yyvsp[-2].s_val), "float32")==0 || strcmp((yyvsp[0].s_val), "float32")==0)
                                              jasmin_label("float32", "<=");
                                          else
                                              jasmin_label("int32", "<=");}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 487 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; printf("%s\n", "GTR");  
                                          if(strcmp((yyvsp[-2].s_val), "float32")==0 || strcmp((yyvsp[0].s_val), "float32")==0)
                                              jasmin_label("float32", ">");
                                          else
                                              jasmin_label("int32", ">");}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 492 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; printf("%s\n", "GEQ"); }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 496 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 497 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-2].s_val); 
                                           if(strcmp((yyvsp[-2].s_val), "li_int32")==0) 
                                               (yyvsp[-2].s_val) = "int32"; 
                                           if(strcmp((yyvsp[0].s_val), "li_int32")==0) 
                                               (yyvsp[0].s_val) = "int32"; 
                                           if(strcmp((yyvsp[-2].s_val), "int32")==0 || strcmp((yyvsp[0].s_val), "int32")==0) {
                                               printf("error:%d: invalid operation: (operator LAND not defined on int32)\n", yylineno); 
                                               HAS_ERROR = 1;
                                           }
                                           fprintf(jasmin_file, "iand\n");
                                           printf("%s\n", "LAND"); }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 511 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 512 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-2].s_val); 
                                         if(strcmp((yyvsp[-2].s_val), "li_int32")==0) 
                                             (yyvsp[-2].s_val) = "int32"; 
                                         if(strcmp((yyvsp[0].s_val), "li_int32")==0) 
                                             (yyvsp[0].s_val) = "int32"; 
                                         if(strcmp((yyvsp[-2].s_val), "int32")==0 || strcmp((yyvsp[0].s_val), "int32")==0) { 
                                             printf("error:%d: invalid operation: (operator LOR not defined on int32)\n", yylineno); 
                                             HAS_ERROR = 1;
                                         }
                                         fprintf(jasmin_file, "ior\n");
                                         printf("%s\n", "LOR"); }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 526 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_operation = "ASSIGN"; isArray = 0;}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 527 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_operation = "ADD_ASSIGN"; isArray = 0;}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 528 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_operation = "SUB_ASSIGN"; isArray = 0;}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 529 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_operation = "MUL_ASSIGN"; isArray = 0;}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 530 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_operation = "QUO_ASSIGN"; isArray = 0;}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 531 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_operation = "REM_ASSIGN"; isArray = 0;}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 535 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 536 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("%s\n", assign_operation);
                                       if(strcmp((yyvsp[0].s_val), "li_int32")==0)
                                           (yyvsp[0].s_val) = "int32";
                                       if(strcmp(assign_operation, "ADD_ASSIGN") == 0) {
                                           lookup_symbol((yyvsp[-2].id_val), "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp((yyvsp[0].s_val), "float32") == 0)
                                               fprintf(jasmin_file, "fadd\n");
                                           else if(strcmp((yyvsp[0].s_val), "int32") == 0)
                                               fprintf(jasmin_file, "iadd\n");
                                       }
                                       else if(strcmp(assign_operation, "SUB_ASSIGN") == 0) {
                                           lookup_symbol((yyvsp[-2].id_val), "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp((yyvsp[0].s_val), "float32") == 0)
                                               fprintf(jasmin_file, "fsub\n");
                                           else if(strcmp((yyvsp[0].s_val), "int32") == 0)
                                               fprintf(jasmin_file, "isub\n");
                                       }
                                       else if(strcmp(assign_operation, "MUL_ASSIGN") == 0) {
                                           lookup_symbol((yyvsp[-2].id_val), "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp((yyvsp[0].s_val), "float32") == 0)
                                               fprintf(jasmin_file, "fmul\n");
                                           else if(strcmp((yyvsp[0].s_val), "int32") == 0)
                                               fprintf(jasmin_file, "imul\n");
                                       }
                                       else if(strcmp(assign_operation, "QUO_ASSIGN") == 0) {
                                           lookup_symbol((yyvsp[-2].id_val), "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp((yyvsp[0].s_val), "float32") == 0)
                                               fprintf(jasmin_file, "fdiv\n");
                                           else if(strcmp((yyvsp[0].s_val), "int32") == 0)
                                               fprintf(jasmin_file, "idiv\n");
                                       }
                                       else if(strcmp(assign_operation, "REM_ASSIGN") == 0) {
                                           lookup_symbol((yyvsp[-2].id_val), "");
                                           fprintf(jasmin_file, "swap\n");
                                           if(strcmp((yyvsp[0].s_val), "int32") == 0)
                                               fprintf(jasmin_file, "irem\n");
                                       }
                                       isAssign = 1; 
                                       lookup_symbol((yyvsp[-2].id_val), "");
                                       isAssign = 0;}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 580 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-2].s_val); 
                                       if(strcmp((yyvsp[-2].s_val), "li_int32")==0) {
                                           printf("error:%d: cannot assign to int32\n", yylineno); 
                                           HAS_ERROR = 1;
                                       }
                                       if(strcmp((yyvsp[-2].s_val), "li_int32")==0) 
                                           (yyvsp[-2].s_val) = "int32"; 
                                       if(strcmp((yyvsp[0].s_val), "li_int32")==0) 
                                           (yyvsp[0].s_val) = "int32"; 
                                       if(strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val))!=0 && strcmp((yyvsp[-2].s_val), "")!=0 && strcmp((yyvsp[0].s_val), "")!=0) {
                                           printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, assign_operation, (yyvsp[-2].s_val), (yyvsp[0].s_val)); 
                                           HAS_ERROR = 1;
                                       }
                                       isArray = 0;
                                       isAssign = 1;
                                       lookup_symbol(id, "");
                                       isAssign = 0;
                                       printf("%s\n", assign_operation); }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 601 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].type_val); TYPE = strdup(yylval.type_val); }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 602 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].type_val); TYPE = strdup(yylval.type_val); }
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 603 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].type_val); TYPE = strdup(yylval.type_val); }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 604 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].type_val); TYPE = strdup(yylval.type_val); }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 605 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "array"; ELEMENT = strdup(yylval.type_val);}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2169 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 608 "compiler_hw3.y" /* yacc.c:1906  */


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
                if((forpostnum-1)==scope_level && forpostnum>0) {
                    char forpost[1024] = {'\0'};
                    if(isAssign==0 && isArray==0) {
                        if(strcmp("int32", table[i].type[j]) == 0) {
                            char temp[256];
                            sprintf(temp, "iload %d\n", table[i].address[j]);
                            strcat(forpost, temp);
                        }
                        else if(strcmp("float32", table[i].type[j]) == 0) {
                            char temp[256];
                            sprintf(temp, "fload %d\n", table[i].address[j]);
                            strcat(forpost, temp);
                        }
                        else if(strcmp("bool", table[i].type[j]) == 0) {
                            char temp[256];
                            sprintf(temp, "iload %d\n", table[i].address[j]);
                            strcat(forpost, temp);
                        }
                        else if(strcmp("array", table[i].type[j]) == 0) {
                            char temp[256];
                            sprintf(temp, "aload %d\n", table[i].address[j]);
                            strcat(forpost, temp);
                        }
                    }
                    else if(isAssign==0 && isArray==2) {
                        if(strcmp("array", table[i].type[j]) == 0) {
                            if(strcmp("int32", table[i].element_type[j]) == 0)
                                strcat(forpost, "iaload\n");
                            else if(strcmp("float32", table[i].element_type[j]) == 0)
                                strcat(forpost, "faload\n");
                        }
                    }
                    else if(isArray == 0) {
                        if(strcmp("int32", table[i].type[j]) == 0) {
                            char temp[256];
                            sprintf(temp, "istore %d\n", table[i].address[j]);
                            strcat(forpost, temp);
                        }
                        else if(strcmp("float32", table[i].type[j]) == 0) {
                            char temp[256];
                            sprintf(temp, "fstore %d\n", table[i].address[j]);
                            strcat(forpost, temp);
                        }
                        else if(strcmp("bool", table[i].type[j]) == 0) {
                            char temp[256];
                            sprintf(temp, "istore %d\n", table[i].address[j]);
                            strcat(forpost, temp);
                        }
                        else if(strcmp("array", table[i].type[j]) == 0) {
                            if(strcmp("int32", table[i].element_type[j]) == 0)
                                strcat(forpost, "iastore\n");
                            else if(strcmp("float32", table[i].element_type[j]) == 0)
                                strcat(forpost, "fastore\n");
                        }
                    }
                    if(forinit == 1)
                        strcat(forpost1, forpost);
                    else
                        strcat(forpost2, forpost);

                    printf("++++++%s", forpost);
                    forpost[0] = '\0';
                }
                else {
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
        PrintType = "float32";
    }
    else if(strcmp(TYPE, "int32")==0) {
        printf("%s to I\n", PrintType);
        fprintf(jasmin_file, "f2i\n");
        PrintType = "int32";
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

    if(strcmp(op, "<") == 0)
        fprintf(jasmin_file, "iflt %s\n", label_name);
    else if(strcmp(op, "<=") == 0)
        fprintf(jasmin_file, "ifle %s\n", label_name);
    else if(strcmp(op, "==") == 0)
        fprintf(jasmin_file, "ifeq %s\n", label_name);
    else
        fprintf(jasmin_file, "ifgt %s\n", label_name);
    fprintf(jasmin_file, "iconst_0\n");
    fprintf(jasmin_file, "goto %s\n", next_label_name);
    fprintf(jasmin_file, "%s:\n", label_name);
    fprintf(jasmin_file, "iconst_1\n\n");
    fprintf(jasmin_file, "%s:\n", next_label_name);
}
