/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 55 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char *s_val;
    char *id_val;
    char *type_val;
    /* ... */

#line 125 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
