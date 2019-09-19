/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VAL = 258,
     ID = 259,
     READ = 260,
     WRITE = 261,
     IF = 262,
     ELSE = 263,
     ENDIF = 264,
     WHILE = 265,
     ENDWHILE = 266,
     THEN = 267,
     DO = 268,
     DECL = 269,
     ENDDECL = 270,
     INT_TYPE = 271,
     BOOL_TYPE = 272,
     BOOL_VAL = 273,
     BEG = 274,
     END = 275,
     RETURN = 276,
     MAIN = 277,
     NOT = 278,
     OR = 279,
     AND = 280,
     NE = 281,
     EQ = 282,
     GE = 283,
     GT = 284,
     LE = 285,
     LT = 286,
     UMINUS = 287
   };
#endif
/* Tokens.  */
#define INT_VAL 258
#define ID 259
#define READ 260
#define WRITE 261
#define IF 262
#define ELSE 263
#define ENDIF 264
#define WHILE 265
#define ENDWHILE 266
#define THEN 267
#define DO 268
#define DECL 269
#define ENDDECL 270
#define INT_TYPE 271
#define BOOL_TYPE 272
#define BOOL_VAL 273
#define BEG 274
#define END 275
#define RETURN 276
#define MAIN 277
#define NOT 278
#define OR 279
#define AND 280
#define NE 281
#define EQ 282
#define GE 283
#define GT 284
#define LE 285
#define LT 286
#define UMINUS 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 114 "p.y"
struct Tnode* x;
	


/* Line 2068 of yacc.c  */
#line 119 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


