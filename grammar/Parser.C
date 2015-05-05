/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "grammar.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "Absyn.H"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *str);
void yy_delete_buffer(YY_BUFFER_STATE buf);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  std::cout << "line " << yy_mylinenumber << std::endl ;
  fprintf(stderr,"error: %s\n",str);
}



static Program* YY_RESULT_Program_ = 0;
Program* pProgram(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}
Program* pProgram(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}

static Definition* YY_RESULT_Definition_ = 0;
Definition* pDefinition(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Definition_;
  }
}
Definition* pDefinition(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Definition_;
  }
}

static ListDefinition* YY_RESULT_ListDefinition_ = 0;
ListDefinition* pListDefinition(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListDefinition_;
  }
}
ListDefinition* pListDefinition(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListDefinition_;
  }
}

static ArgumentList* YY_RESULT_ArgumentList_ = 0;
ArgumentList* pArgumentList(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ArgumentList_;
  }
}
ArgumentList* pArgumentList(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ArgumentList_;
  }
}

static ListArgument* YY_RESULT_ListArgument_ = 0;
ListArgument* pListArgument(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArgument_;
  }
}
ListArgument* pListArgument(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArgument_;
  }
}

static Argument* YY_RESULT_Argument_ = 0;
Argument* pArgument(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Argument_;
  }
}
Argument* pArgument(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Argument_;
  }
}

static Body* YY_RESULT_Body_ = 0;
Body* pBody(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Body_;
  }
}
Body* pBody(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Body_;
  }
}

static Stm* YY_RESULT_Stm_ = 0;
Stm* pStm(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stm_;
  }
}
Stm* pStm(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stm_;
  }
}

static ListStm* YY_RESULT_ListStm_ = 0;
ListStm* pListStm(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStm_;
  }
}
ListStm* pListStm(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStm_;
  }
}

static Struct* YY_RESULT_Struct_ = 0;
Struct* pStruct(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Struct_;
  }
}
Struct* pStruct(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Struct_;
  }
}

static TypeDef* YY_RESULT_TypeDef_ = 0;
TypeDef* pTypeDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TypeDef_;
  }
}
TypeDef* pTypeDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TypeDef_;
  }
}

static Decl* YY_RESULT_Decl_ = 0;
Decl* pDecl(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Decl_;
  }
}
Decl* pDecl(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Decl_;
  }
}

static Var* YY_RESULT_Var_ = 0;
Var* pVar(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Var_;
  }
}
Var* pVar(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Var_;
  }
}

static ListVar* YY_RESULT_ListVar_ = 0;
ListVar* pListVar(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListVar_;
  }
}
ListVar* pListVar(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListVar_;
  }
}

static ListDecl* YY_RESULT_ListDecl_ = 0;
ListDecl* pListDecl(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListDecl_;
  }
}
ListDecl* pListDecl(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListDecl_;
  }
}

static QCon* YY_RESULT_QCon_ = 0;
QCon* pQCon(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_QCon_;
  }
}
QCon* pQCon(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_QCon_;
  }
}

static Name* YY_RESULT_Name_ = 0;
Name* pName(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Name_;
  }
}
Name* pName(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Name_;
  }
}

static Exp* YY_RESULT_Exp_ = 0;
Exp* pExp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}
Exp* pExp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

static ListExp* YY_RESULT_ListExp_ = 0;
ListExp* pListExp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExp_;
  }
}
ListExp* pListExp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExp_;
  }
}

static TempInst* YY_RESULT_TempInst_ = 0;
TempInst* pTempInst(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TempInst_;
  }
}
TempInst* pTempInst(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TempInst_;
  }
}

static TypeList* YY_RESULT_TypeList_ = 0;
TypeList* pTypeList(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TypeList_;
  }
}
TypeList* pTypeList(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TypeList_;
  }
}

static ListType* YY_RESULT_ListType_ = 0;
ListType* pListType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListType_;
  }
}
ListType* pListType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListType_;
  }
}

static Type* YY_RESULT_Type_ = 0;
Type* pType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}
Type* pType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}

static BType* YY_RESULT_BType_ = 0;
BType* pBType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_BType_;
  }
}
BType* pBType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_BType_;
  }
}

static Literal* YY_RESULT_Literal_ = 0;
Literal* pLiteral(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Literal_;
  }
}
Literal* pLiteral(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Literal_;
  }
}

static StringList* YY_RESULT_StringList_ = 0;
StringList* pStringList(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_StringList_;
  }
}
StringList* pStringList(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_StringList_;
  }
}

static Id* YY_RESULT_Id_ = 0;
Id* pId(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Id_;
  }
}
Id* pId(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Id_;
  }
}




#line 987 "Parser.C" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif


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
    _ERROR_ = 258,
    _SYMB_0 = 259,
    _SYMB_1 = 260,
    _SYMB_2 = 261,
    _SYMB_3 = 262,
    _SYMB_4 = 263,
    _SYMB_5 = 264,
    _SYMB_6 = 265,
    _SYMB_7 = 266,
    _SYMB_8 = 267,
    _SYMB_9 = 268,
    _SYMB_10 = 269,
    _SYMB_11 = 270,
    _SYMB_12 = 271,
    _SYMB_13 = 272,
    _SYMB_14 = 273,
    _SYMB_15 = 274,
    _SYMB_16 = 275,
    _SYMB_17 = 276,
    _SYMB_18 = 277,
    _SYMB_19 = 278,
    _SYMB_20 = 279,
    _SYMB_21 = 280,
    _SYMB_22 = 281,
    _SYMB_23 = 282,
    _SYMB_24 = 283,
    _SYMB_25 = 284,
    _SYMB_26 = 285,
    _SYMB_27 = 286,
    _SYMB_28 = 287,
    _SYMB_29 = 288,
    _SYMB_30 = 289,
    _SYMB_31 = 290,
    _SYMB_32 = 291,
    _SYMB_33 = 292,
    _SYMB_34 = 293,
    _SYMB_35 = 294,
    _SYMB_36 = 295,
    _SYMB_37 = 296,
    _SYMB_38 = 297,
    _SYMB_39 = 298,
    _SYMB_40 = 299,
    _SYMB_41 = 300,
    _SYMB_42 = 301,
    _SYMB_43 = 302,
    _SYMB_44 = 303,
    _SYMB_45 = 304,
    _SYMB_46 = 305,
    _SYMB_47 = 306,
    _SYMB_48 = 307,
    _SYMB_49 = 308,
    _SYMB_50 = 309,
    _SYMB_51 = 310,
    _SYMB_52 = 311,
    _SYMB_53 = 312,
    _SYMB_54 = 313,
    _STRING_ = 314,
    _CHAR_ = 315,
    _INTEGER_ = 316,
    _DOUBLE_ = 317,
    _IDENT_ = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 924 "grammar.y" /* yacc.c:355  */

  int int_;
  char char_;
  double double_;
  char* string_;
  Program* program_;
  Definition* definition_;
  ListDefinition* listdefinition_;
  ArgumentList* argumentlist_;
  ListArgument* listargument_;
  Argument* argument_;
  Body* body_;
  Stm* stm_;
  ListStm* liststm_;
  Struct* struct_;
  TypeDef* typedef_;
  Decl* decl_;
  Var* var_;
  ListVar* listvar_;
  ListDecl* listdecl_;
  QCon* qcon_;
  Name* name_;
  Exp* exp_;
  ListExp* listexp_;
  TempInst* tempinst_;
  TypeList* typelist_;
  ListType* listtype_;
  Type* type_;
  BType* btype_;
  Literal* literal_;
  StringList* stringlist_;
  Id* id_;


#line 1123 "Parser.C" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 1138 "Parser.C" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   416

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1068,  1068,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1079,  1080,  1082,  1084,  1085,  1086,  1087,  1088,  1090,
    1091,  1092,  1093,  1095,  1096,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1112,  1113,
    1115,  1117,  1118,  1120,  1121,  1123,  1124,  1126,  1127,  1128,
    1129,  1131,  1132,  1133,  1134,  1135,  1137,  1138,  1140,  1141,
    1143,  1144,  1145,  1146,  1148,  1149,  1150,  1151,  1153,  1154,
    1155,  1156,  1157,  1158,  1160,  1161,  1162,  1163,  1165,  1166,
    1167,  1168,  1170,  1171,  1172,  1174,  1175,  1176,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,  1186,  1187,  1188,  1190,  1191,
    1193,  1194,  1196,  1197,  1198,  1199,  1200,  1202,  1203,  1205,
    1207,  1209,  1211,  1213,  1214,  1215,  1216,  1217,  1219,  1221,
    1223,  1224,  1225,  1226,  1227,  1229,  1230,  1231,  1233,  1234,
    1235,  1236,  1237,  1239,  1240,  1241,  1242,  1244,  1245,  1247
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "_SYMB_0", "_SYMB_1",
  "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6", "_SYMB_7",
  "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12", "_SYMB_13",
  "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18", "_SYMB_19",
  "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24", "_SYMB_25",
  "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30", "_SYMB_31",
  "_SYMB_32", "_SYMB_33", "_SYMB_34", "_SYMB_35", "_SYMB_36", "_SYMB_37",
  "_SYMB_38", "_SYMB_39", "_SYMB_40", "_SYMB_41", "_SYMB_42", "_SYMB_43",
  "_SYMB_44", "_SYMB_45", "_SYMB_46", "_SYMB_47", "_SYMB_48", "_SYMB_49",
  "_SYMB_50", "_SYMB_51", "_SYMB_52", "_SYMB_53", "_SYMB_54", "_STRING_",
  "_CHAR_", "_INTEGER_", "_DOUBLE_", "_IDENT_", "$accept", "Program",
  "Definition", "ListDefinition", "ArgumentList", "ListArgument",
  "Argument", "Body", "Stm", "ListStm", "Struct", "TypeDef", "Decl", "Var",
  "ListVar", "ListDecl", "QCon", "Name", "Exp16", "Exp15", "Exp14",
  "Exp13", "Exp12", "Exp11", "Exp10", "Exp9", "Exp8", "Exp4", "Exp3",
  "Exp2", "Exp1", "Exp", "Exp5", "Exp6", "Exp7", "ListExp", "TempInst",
  "TypeList", "ListType", "Type", "BType", "Literal", "StringList", "Id", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF -133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-133)))

#define YYTABLE_NINF -129

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -133,     7,   295,  -133,  -133,   341,  -133,   341,  -133,   -45,
     341,   -37,  -133,  -133,  -133,    16,  -133,    28,    23,  -133,
    -133,   -45,     9,    10,   -45,   -45,    35,    -3,   -45,    84,
    -133,  -133,   -45,    -5,  -133,    12,  -133,  -133,   341,  -133,
      41,    40,   242,  -133,    66,    76,  -133,  -133,   -45,  -133,
     337,   116,   136,    56,  -133,   336,    77,    24,    95,   -45,
    -133,  -133,  -133,   341,    90,   166,   116,   116,   131,   131,
     101,   131,   263,  -133,  -133,  -133,  -133,    23,  -133,   273,
    -133,  -133,   102,    92,   104,   379,   150,   113,   103,   188,
    -133,  -133,  -133,  -133,  -133,  -133,    99,    10,  -133,   168,
    -133,  -133,   341,  -133,  -133,   242,  -133,  -133,   116,  -133,
     337,  -133,  -133,   174,  -133,  -133,    93,  -133,   188,   116,
     116,   101,   101,  -133,  -133,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,  -133,   165,   195,  -133,
    -133,  -133,  -133,  -133,    94,   179,   183,    93,    93,  -133,
    -133,  -133,   102,   102,    92,    92,   104,   104,   104,   104,
     104,   104,   379,   379,  -133,   113,   103,   103,   103,   106,
    -133,   192,  -133,   313,   200,   204,   210,   116,   212,  -133,
     223,  -133,   224,    46,   227,   116,  -133,  -133,  -133,   263,
    -133,   254,   175,   116,   242,   116,   228,   116,  -133,  -133,
    -133,  -133,   103,  -133,   230,   234,   240,   245,  -133,   261,
     116,   265,   116,   313,   313,   268,  -133,   271,   201,  -133,
     272,   116,   313,  -133,   285,  -133,   313,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     2,     1,   131,     0,   132,     0,   129,     0,
       0,     0,   130,   139,    12,     0,     8,     0,   128,    57,
      59,    49,   127,    58,    49,     0,     0,     0,     0,     0,
       7,     6,     0,    47,    44,    46,   125,   126,   120,    43,
      46,     0,    51,    42,     0,     0,    10,    56,    49,    50,
      14,     0,     0,     0,   119,   120,     0,    51,     0,    49,
      41,     9,    48,     0,     0,    14,    22,     0,     0,     0,
       0,     0,     0,   138,   136,   134,   135,    65,    67,    73,
      77,    81,    84,    87,    94,    97,   112,   101,   106,   108,
     109,    45,    99,   110,   111,    61,   133,    58,     5,    38,
       4,   118,   120,   124,     3,    51,    55,    40,    21,    13,
      14,    18,    20,     0,    74,    75,    72,    76,   107,   113,
       0,     0,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,   122,
      53,    19,    16,    62,   113,     0,     0,    68,    69,    78,
      79,    80,    82,    83,    85,    86,    88,    89,    90,    91,
      92,    93,    95,    96,    98,   100,   102,   103,   104,     0,
      24,    38,    23,     0,     0,     0,     0,     0,     0,    39,
       0,    35,     0,    65,     0,   113,   117,    66,    64,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    36,    25,
      37,   115,   105,    33,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,    27,     0,    32,    28,
       0,     0,     0,    29,     0,    31,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,  -133,   236,   -32,  -133,   237,   -93,   129,
     292,   301,     2,  -133,    69,   -51,    -2,   287,  -133,     5,
      97,   139,    59,    89,   279,   122,  -133,   186,  -132,   248,
    -133,   -36,   193,  -133,  -133,  -104,  -133,  -133,   -26,    87,
    -133,  -133,  -133,    14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    14,     2,    52,    64,    65,   100,   189,   148,
     190,   191,   192,    33,    34,    58,    77,    19,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   194,    92,    93,    94,   155,    20,    53,    54,    59,
      22,    95,    96,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    43,    48,    18,    17,    18,   106,     3,    18,    29,
     176,   177,   178,   179,    28,    91,    23,    50,    13,    23,
      30,    23,    51,    26,    23,    23,    13,    36,   105,   103,
     112,   113,    31,   111,    32,    35,    18,    38,    40,    41,
      18,    44,    45,    42,    57,    50,    23,    40,    18,    37,
     196,    51,    23,    18,   150,    18,    23,    32,    13,    57,
      13,    18,    40,    18,    23,     4,     5,   212,     6,    23,
      60,    23,   151,    40,     8,   116,   149,    23,   152,    23,
      61,    12,   101,   154,   156,    99,  -128,    13,    46,    21,
     202,   211,    24,    39,    25,    32,   109,    27,   119,    67,
      18,   195,    49,    18,   107,   120,    67,    57,    18,  -128,
      68,    69,    70,    71,   128,   129,    23,    62,   154,    23,
     125,    67,   126,   127,    23,    55,   157,   158,   130,   131,
     228,   229,    68,    69,    70,    71,    67,    66,   141,   235,
      98,   141,    55,   237,    99,   199,   193,   140,    72,    70,
     108,   206,    66,    73,    74,    75,    76,    13,   146,   154,
      73,    74,    75,    76,    13,   114,   115,   215,   117,   217,
      72,   219,   147,   110,   180,    73,    74,    75,    76,    13,
     153,   193,   138,   139,   225,   197,   227,   162,   163,    55,
      73,    74,    75,    76,    13,   234,   198,    66,   142,   193,
      67,   200,    18,   181,   182,   203,   216,     4,    63,   204,
       6,    68,    69,    70,    71,   205,     8,   207,    23,   164,
     165,   193,   193,    12,   143,   144,   145,   208,   209,    13,
     193,   210,   218,   214,   193,   220,     4,     5,   183,     6,
     221,   184,   185,   186,   222,     8,   232,   187,     9,    72,
      10,   223,    12,   188,    73,    74,    75,    76,    13,    67,
     172,   173,   181,   213,   159,   160,   161,   224,    67,   226,
      68,    69,    70,    71,   230,   231,   233,    56,   119,    68,
      69,    70,    71,     4,     5,   120,     6,   121,   122,   123,
     124,   236,     8,   104,    15,     4,     5,   183,     6,    12,
     184,   185,   186,    16,     8,    13,   187,     9,    72,    10,
     201,    12,   188,    73,    74,    75,    76,    13,    67,    47,
     118,   181,    73,    74,    75,    76,    13,   175,     0,    68,
      69,    70,    71,   174,     0,     0,     4,     5,     0,     6,
       0,     0,     0,   102,     7,     8,     0,     0,     9,     0,
      10,    11,    12,     0,     4,     5,   183,     6,    13,   184,
     185,   186,     0,     8,     0,   187,     9,    72,    10,     0,
      12,   188,    73,    74,    75,    76,    13,     4,     4,    63,
       6,     6,     4,     0,     0,     6,     8,     8,     0,     0,
       0,     8,     0,    12,    12,     0,     0,     0,    12,    13,
      13,     0,     0,     0,    13,   132,   133,   134,   135,   136,
     137,   166,   167,   168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
       2,     4,     7,     5,     2,     7,    57,     0,    10,    11,
     142,   143,   144,   145,    51,    51,     2,     5,    63,     5,
       4,     7,    10,     9,    10,    11,    63,    18,     4,    55,
      66,    67,     4,    65,    11,    21,    38,    27,    24,    25,
      42,    27,    28,     8,    42,     5,    32,    33,    50,    40,
     154,    10,    38,    55,   105,    57,    42,    11,    63,    57,
      63,    63,    48,    65,    50,    41,    42,   199,    44,    55,
       4,    57,   108,    59,    50,    70,   102,    63,   110,    65,
       4,    57,    26,   119,   120,     8,    40,    63,     4,     2,
     183,   195,     5,    24,     7,    11,     6,    10,     5,     5,
     102,     7,    33,   105,     9,    12,     5,   105,   110,    63,
      16,    17,    18,    19,    22,    23,   102,    48,   154,   105,
      18,     5,    20,    21,   110,    38,   121,   122,    24,    25,
     223,   224,    16,    17,    18,    19,     5,    50,    35,   232,
       4,    35,    55,   236,     8,    39,   148,    34,    54,    18,
      63,   187,    65,    59,    60,    61,    62,    63,    59,   195,
      59,    60,    61,    62,    63,    68,    69,   203,    71,   205,
      54,   207,     4,     7,     9,    59,    60,    61,    62,    63,
       6,   183,    32,    33,   220,     6,   222,   128,   129,   102,
      59,    60,    61,    62,    63,   231,    13,   110,    10,   201,
       5,     9,   204,     8,     9,     5,   204,    41,    42,     5,
      44,    16,    17,    18,    19,     5,    50,     5,   204,   130,
     131,   223,   224,    57,    36,    37,    38,     4,     4,    63,
     232,     4,     4,    58,   236,     5,    41,    42,    43,    44,
       6,    46,    47,    48,     4,    50,    45,    52,    53,    54,
      55,     6,    57,    58,    59,    60,    61,    62,    63,     5,
     138,   139,     8,     9,   125,   126,   127,     6,     5,     4,
      16,    17,    18,    19,     6,     4,     4,    41,     5,    16,
      17,    18,    19,    41,    42,    12,    44,    14,    15,    16,
      17,     6,    50,    56,     2,    41,    42,    43,    44,    57,
      46,    47,    48,     2,    50,    63,    52,    53,    54,    55,
     181,    57,    58,    59,    60,    61,    62,    63,     5,    32,
      72,     8,    59,    60,    61,    62,    63,   141,    -1,    16,
      17,    18,    19,   140,    -1,    -1,    41,    42,    -1,    44,
      -1,    -1,    -1,     7,    49,    50,    -1,    -1,    53,    -1,
      55,    56,    57,    -1,    41,    42,    43,    44,    63,    46,
      47,    48,    -1,    50,    -1,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    41,    41,    42,
      44,    44,    41,    -1,    -1,    44,    50,    50,    -1,    -1,
      -1,    50,    -1,    57,    57,    -1,    -1,    -1,    57,    63,
      63,    -1,    -1,    -1,    63,    26,    27,    28,    29,    30,
      31,   132,   133,   134,   135,   136,   137
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    67,     0,    41,    42,    44,    49,    50,    53,
      55,    56,    57,    63,    66,    74,    75,    76,    80,    81,
     100,   103,   104,   107,   103,   103,   107,   103,    51,    80,
       4,     4,    11,    77,    78,   107,    18,    40,    27,    78,
     107,   107,     8,     4,   107,   107,     4,    81,     7,    78,
       5,    10,    68,   101,   102,   103,    68,    76,    79,   103,
       4,     4,    78,    42,    69,    70,   103,     5,    16,    17,
      18,    19,    54,    59,    60,    61,    62,    80,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   105,   106,   107,     4,     8,
      71,    26,     7,   102,    71,     4,    79,     9,   103,     6,
       7,    69,    95,    95,    84,    84,    83,    84,    93,     5,
      12,    14,    15,    16,    17,    18,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    10,    36,    37,    38,    59,     4,    73,   102,
      79,    95,    69,     6,    95,    99,    95,    83,    83,    85,
      85,    85,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    89,    89,    96,    91,    92,    92,    92,    92,
       9,     8,     9,    43,    46,    47,    48,    52,    58,    72,
      74,    75,    76,    80,    95,     7,    99,     6,    13,    39,
       9,    73,    72,     5,     5,     5,    95,     5,     4,     4,
       4,    99,    92,     9,    58,    95,    76,    95,     4,    95,
       5,     6,     4,     6,     6,    95,     4,    95,    72,    72,
       6,     4,    45,     4,    95,    72,     6,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    73,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    82,    83,    83,    83,    83,    84,    84,
      84,    84,    84,    84,    85,    85,    85,    85,    86,    86,
      86,    86,    87,    87,    87,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    93,    93,    93,    94,    94,    95,
      96,    97,    98,    99,    99,    99,    99,    99,   100,   101,
     102,   102,   102,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   106,   106,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     4,     4,     2,     2,     1,     4,
       3,     0,     2,     3,     0,     1,     3,     0,     2,     3,
       2,     2,     1,     3,     3,     2,     3,     5,     5,     7,
       9,     7,     5,     3,     2,     1,     2,     2,     0,     2,
       5,     4,     3,     3,     2,     3,     1,     1,     3,     0,
       2,     0,     1,     3,     0,     2,     3,     1,     1,     1,
       1,     1,     3,     3,     4,     1,     4,     1,     3,     3,
       2,     2,     2,     1,     2,     2,     2,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     3,     3,     5,     1,     2,     1,     1,
       1,     1,     1,     0,     1,     3,     0,     2,     4,     1,
       0,     1,     3,     0,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1
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
        case 2:
#line 1068 "grammar.y" /* yacc.c:1646  */
    {  (yyval.program_) = new Prog((yyvsp[0].listdefinition_)); YY_RESULT_Program_= (yyval.program_); }
#line 2428 "Parser.C" /* yacc.c:1646  */
    break;

  case 3:
#line 1070 "grammar.y" /* yacc.c:1646  */
    {  (yyval.definition_) = new FunctionDefIn((yyvsp[-3].type_), (yyvsp[-2].id_), (yyvsp[-1].argumentlist_), (yyvsp[0].body_)); YY_RESULT_Definition_= (yyval.definition_); }
#line 2434 "Parser.C" /* yacc.c:1646  */
    break;

  case 4:
#line 1071 "grammar.y" /* yacc.c:1646  */
    {  (yyval.definition_) = new FunctionDef((yyvsp[-3].type_), (yyvsp[-2].id_), (yyvsp[-1].argumentlist_), (yyvsp[0].body_)); YY_RESULT_Definition_= (yyval.definition_); }
#line 2440 "Parser.C" /* yacc.c:1646  */
    break;

  case 5:
#line 1072 "grammar.y" /* yacc.c:1646  */
    {  (yyval.definition_) = new Function((yyvsp[-3].type_), (yyvsp[-2].id_), (yyvsp[-1].argumentlist_)); YY_RESULT_Definition_= (yyval.definition_); }
#line 2446 "Parser.C" /* yacc.c:1646  */
    break;

  case 6:
#line 1073 "grammar.y" /* yacc.c:1646  */
    {  (yyval.definition_) = new GlobVar((yyvsp[-1].decl_)); YY_RESULT_Definition_= (yyval.definition_); }
#line 2452 "Parser.C" /* yacc.c:1646  */
    break;

  case 7:
#line 1074 "grammar.y" /* yacc.c:1646  */
    {  (yyval.definition_) = new GlobStruct((yyvsp[-1].struct_)); YY_RESULT_Definition_= (yyval.definition_); }
#line 2458 "Parser.C" /* yacc.c:1646  */
    break;

  case 8:
#line 1075 "grammar.y" /* yacc.c:1646  */
    {  (yyval.definition_) = new GlobTypeDef((yyvsp[0].typedef_)); YY_RESULT_Definition_= (yyval.definition_); }
#line 2464 "Parser.C" /* yacc.c:1646  */
    break;

  case 9:
#line 1076 "grammar.y" /* yacc.c:1646  */
    {  (yyval.definition_) = new UsingNSDef((yyvsp[-1].id_)); YY_RESULT_Definition_= (yyval.definition_); }
#line 2470 "Parser.C" /* yacc.c:1646  */
    break;

  case 10:
#line 1077 "grammar.y" /* yacc.c:1646  */
    {  (yyval.definition_) = new UsingDef((yyvsp[-1].qcon_)); YY_RESULT_Definition_= (yyval.definition_); }
#line 2476 "Parser.C" /* yacc.c:1646  */
    break;

  case 11:
#line 1079 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listdefinition_) = new ListDefinition(); YY_RESULT_ListDefinition_= (yyval.listdefinition_); }
#line 2482 "Parser.C" /* yacc.c:1646  */
    break;

  case 12:
#line 1080 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listdefinition_)->push_back((yyvsp[0].definition_)) ; (yyval.listdefinition_) = (yyvsp[-1].listdefinition_) ; YY_RESULT_ListDefinition_= (yyval.listdefinition_); }
#line 2488 "Parser.C" /* yacc.c:1646  */
    break;

  case 13:
#line 1082 "grammar.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listargument_)->begin(),(yyvsp[-1].listargument_)->end()) ;(yyval.argumentlist_) = new ArgumentListDef((yyvsp[-1].listargument_)); YY_RESULT_ArgumentList_= (yyval.argumentlist_); }
#line 2494 "Parser.C" /* yacc.c:1646  */
    break;

  case 14:
#line 1084 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listargument_) = new ListArgument(); YY_RESULT_ListArgument_= (yyval.listargument_); }
#line 2500 "Parser.C" /* yacc.c:1646  */
    break;

  case 15:
#line 1085 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listargument_) = new ListArgument() ; (yyval.listargument_)->push_back((yyvsp[0].argument_)); YY_RESULT_ListArgument_= (yyval.listargument_); }
#line 2506 "Parser.C" /* yacc.c:1646  */
    break;

  case 16:
#line 1086 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listargument_)->push_back((yyvsp[-2].argument_)) ; (yyval.listargument_) = (yyvsp[0].listargument_) ; YY_RESULT_ListArgument_= (yyval.listargument_); }
#line 2512 "Parser.C" /* yacc.c:1646  */
    break;

  case 17:
#line 1087 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listargument_) = new ListArgument(); YY_RESULT_ListArgument_= (yyval.listargument_); }
#line 2518 "Parser.C" /* yacc.c:1646  */
    break;

  case 18:
#line 1088 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listargument_)->push_back((yyvsp[-1].argument_)) ; (yyval.listargument_) = (yyvsp[0].listargument_) ; YY_RESULT_ListArgument_= (yyval.listargument_); }
#line 2524 "Parser.C" /* yacc.c:1646  */
    break;

  case 19:
#line 1090 "grammar.y" /* yacc.c:1646  */
    {  (yyval.argument_) = new ArgumentConstDecl((yyvsp[-1].type_), (yyvsp[0].exp_)); YY_RESULT_Argument_= (yyval.argument_); }
#line 2530 "Parser.C" /* yacc.c:1646  */
    break;

  case 20:
#line 1091 "grammar.y" /* yacc.c:1646  */
    {  (yyval.argument_) = new ArgumentDecl((yyvsp[-1].type_), (yyvsp[0].exp_)); YY_RESULT_Argument_= (yyval.argument_); }
#line 2536 "Parser.C" /* yacc.c:1646  */
    break;

  case 21:
#line 1092 "grammar.y" /* yacc.c:1646  */
    {  (yyval.argument_) = new ArgumentConsttype((yyvsp[0].type_)); YY_RESULT_Argument_= (yyval.argument_); }
#line 2542 "Parser.C" /* yacc.c:1646  */
    break;

  case 22:
#line 1093 "grammar.y" /* yacc.c:1646  */
    {  (yyval.argument_) = new ArgumentType((yyvsp[0].type_)); YY_RESULT_Argument_= (yyval.argument_); }
#line 2548 "Parser.C" /* yacc.c:1646  */
    break;

  case 23:
#line 1095 "grammar.y" /* yacc.c:1646  */
    {  (yyval.body_) = new FuntionBody((yyvsp[-1].liststm_)); YY_RESULT_Body_= (yyval.body_); }
#line 2554 "Parser.C" /* yacc.c:1646  */
    break;

  case 24:
#line 1096 "grammar.y" /* yacc.c:1646  */
    {  (yyval.body_) = new EmptyBody(); YY_RESULT_Body_= (yyval.body_); }
#line 2560 "Parser.C" /* yacc.c:1646  */
    break;

  case 25:
#line 1098 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmDecl((yyvsp[-1].decl_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2566 "Parser.C" /* yacc.c:1646  */
    break;

  case 26:
#line 1099 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmReturn((yyvsp[-1].exp_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2572 "Parser.C" /* yacc.c:1646  */
    break;

  case 27:
#line 1100 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmExit((yyvsp[-2].exp_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2578 "Parser.C" /* yacc.c:1646  */
    break;

  case 28:
#line 1101 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmWhile((yyvsp[-2].exp_), (yyvsp[0].stm_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2584 "Parser.C" /* yacc.c:1646  */
    break;

  case 29:
#line 1102 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmDoWhile((yyvsp[-5].stm_), (yyvsp[-2].exp_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2590 "Parser.C" /* yacc.c:1646  */
    break;

  case 30:
#line 1103 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmFor((yyvsp[-6].decl_), (yyvsp[-4].exp_), (yyvsp[-2].exp_), (yyvsp[0].stm_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2596 "Parser.C" /* yacc.c:1646  */
    break;

  case 31:
#line 1104 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmIfElse((yyvsp[-4].exp_), (yyvsp[-2].stm_), (yyvsp[0].stm_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2602 "Parser.C" /* yacc.c:1646  */
    break;

  case 32:
#line 1105 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmIf((yyvsp[-2].exp_), (yyvsp[0].stm_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2608 "Parser.C" /* yacc.c:1646  */
    break;

  case 33:
#line 1106 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmBlock((yyvsp[-1].liststm_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2614 "Parser.C" /* yacc.c:1646  */
    break;

  case 34:
#line 1107 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmEmptyBlock(); YY_RESULT_Stm_= (yyval.stm_); }
#line 2620 "Parser.C" /* yacc.c:1646  */
    break;

  case 35:
#line 1108 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmTypeDef((yyvsp[0].typedef_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2626 "Parser.C" /* yacc.c:1646  */
    break;

  case 36:
#line 1109 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmeStruct((yyvsp[-1].struct_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2632 "Parser.C" /* yacc.c:1646  */
    break;

  case 37:
#line 1110 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stm_) = new StmExpression((yyvsp[-1].exp_)); YY_RESULT_Stm_= (yyval.stm_); }
#line 2638 "Parser.C" /* yacc.c:1646  */
    break;

  case 38:
#line 1112 "grammar.y" /* yacc.c:1646  */
    {  (yyval.liststm_) = new ListStm(); YY_RESULT_ListStm_= (yyval.liststm_); }
#line 2644 "Parser.C" /* yacc.c:1646  */
    break;

  case 39:
#line 1113 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[-1].liststm_)->push_back((yyvsp[0].stm_)) ; (yyval.liststm_) = (yyvsp[-1].liststm_) ; YY_RESULT_ListStm_= (yyval.liststm_); }
#line 2650 "Parser.C" /* yacc.c:1646  */
    break;

  case 40:
#line 1115 "grammar.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listdecl_)->begin(),(yyvsp[-1].listdecl_)->end()) ;(yyval.struct_) = new StructDef((yyvsp[-3].id_), (yyvsp[-1].listdecl_)); YY_RESULT_Struct_= (yyval.struct_); }
#line 2656 "Parser.C" /* yacc.c:1646  */
    break;

  case 41:
#line 1117 "grammar.y" /* yacc.c:1646  */
    {  (yyval.typedef_) = new TypeDefForm((yyvsp[-2].type_), (yyvsp[-1].id_)); YY_RESULT_TypeDef_= (yyval.typedef_); }
#line 2662 "Parser.C" /* yacc.c:1646  */
    break;

  case 42:
#line 1118 "grammar.y" /* yacc.c:1646  */
    {  (yyval.typedef_) = new TypeDefForm2((yyvsp[-1].type_)); YY_RESULT_TypeDef_= (yyval.typedef_); }
#line 2668 "Parser.C" /* yacc.c:1646  */
    break;

  case 43:
#line 1120 "grammar.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[0].listvar_)->begin(),(yyvsp[0].listvar_)->end()) ;(yyval.decl_) = new ConstDecl((yyvsp[-1].type_), (yyvsp[0].listvar_)); YY_RESULT_Decl_= (yyval.decl_); }
#line 2674 "Parser.C" /* yacc.c:1646  */
    break;

  case 44:
#line 1121 "grammar.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[0].listvar_)->begin(),(yyvsp[0].listvar_)->end()) ;(yyval.decl_) = new Declaration((yyvsp[-1].type_), (yyvsp[0].listvar_)); YY_RESULT_Decl_= (yyval.decl_); }
#line 2680 "Parser.C" /* yacc.c:1646  */
    break;

  case 45:
#line 1123 "grammar.y" /* yacc.c:1646  */
    {  (yyval.var_) = new VariableInitialization((yyvsp[-2].id_), (yyvsp[0].exp_)); YY_RESULT_Var_= (yyval.var_); }
#line 2686 "Parser.C" /* yacc.c:1646  */
    break;

  case 46:
#line 1124 "grammar.y" /* yacc.c:1646  */
    {  (yyval.var_) = new VariableName((yyvsp[0].id_)); YY_RESULT_Var_= (yyval.var_); }
#line 2692 "Parser.C" /* yacc.c:1646  */
    break;

  case 47:
#line 1126 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listvar_) = new ListVar() ; (yyval.listvar_)->push_back((yyvsp[0].var_)); YY_RESULT_ListVar_= (yyval.listvar_); }
#line 2698 "Parser.C" /* yacc.c:1646  */
    break;

  case 48:
#line 1127 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listvar_)->push_back((yyvsp[-2].var_)) ; (yyval.listvar_) = (yyvsp[0].listvar_) ; YY_RESULT_ListVar_= (yyval.listvar_); }
#line 2704 "Parser.C" /* yacc.c:1646  */
    break;

  case 49:
#line 1128 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listvar_) = new ListVar(); YY_RESULT_ListVar_= (yyval.listvar_); }
#line 2710 "Parser.C" /* yacc.c:1646  */
    break;

  case 50:
#line 1129 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listvar_)->push_back((yyvsp[-1].var_)) ; (yyval.listvar_) = (yyvsp[0].listvar_) ; YY_RESULT_ListVar_= (yyval.listvar_); }
#line 2716 "Parser.C" /* yacc.c:1646  */
    break;

  case 51:
#line 1131 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listdecl_) = new ListDecl(); YY_RESULT_ListDecl_= (yyval.listdecl_); }
#line 2722 "Parser.C" /* yacc.c:1646  */
    break;

  case 52:
#line 1132 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listdecl_) = new ListDecl() ; (yyval.listdecl_)->push_back((yyvsp[0].decl_)); YY_RESULT_ListDecl_= (yyval.listdecl_); }
#line 2728 "Parser.C" /* yacc.c:1646  */
    break;

  case 53:
#line 1133 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listdecl_)->push_back((yyvsp[-2].decl_)) ; (yyval.listdecl_) = (yyvsp[0].listdecl_) ; YY_RESULT_ListDecl_= (yyval.listdecl_); }
#line 2734 "Parser.C" /* yacc.c:1646  */
    break;

  case 54:
#line 1134 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listdecl_) = new ListDecl(); YY_RESULT_ListDecl_= (yyval.listdecl_); }
#line 2740 "Parser.C" /* yacc.c:1646  */
    break;

  case 55:
#line 1135 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listdecl_)->push_back((yyvsp[-1].decl_)) ; (yyval.listdecl_) = (yyvsp[0].listdecl_) ; YY_RESULT_ListDecl_= (yyval.listdecl_); }
#line 2746 "Parser.C" /* yacc.c:1646  */
    break;

  case 56:
#line 1137 "grammar.y" /* yacc.c:1646  */
    {  (yyval.qcon_) = new QualCon((yyvsp[-2].qcon_), (yyvsp[0].name_)); YY_RESULT_QCon_= (yyval.qcon_); }
#line 2752 "Parser.C" /* yacc.c:1646  */
    break;

  case 57:
#line 1138 "grammar.y" /* yacc.c:1646  */
    {  (yyval.qcon_) = new QualConN((yyvsp[0].name_)); YY_RESULT_QCon_= (yyval.qcon_); }
#line 2758 "Parser.C" /* yacc.c:1646  */
    break;

  case 58:
#line 1140 "grammar.y" /* yacc.c:1646  */
    {  (yyval.name_) = new IdName((yyvsp[0].id_)); YY_RESULT_Name_= (yyval.name_); }
#line 2764 "Parser.C" /* yacc.c:1646  */
    break;

  case 59:
#line 1141 "grammar.y" /* yacc.c:1646  */
    {  (yyval.name_) = new TempInstName((yyvsp[0].tempinst_)); YY_RESULT_Name_= (yyval.name_); }
#line 2770 "Parser.C" /* yacc.c:1646  */
    break;

  case 60:
#line 1143 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EIdent((yyvsp[0].id_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2776 "Parser.C" /* yacc.c:1646  */
    break;

  case 61:
#line 1144 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ELiteral((yyvsp[0].literal_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2782 "Parser.C" /* yacc.c:1646  */
    break;

  case 62:
#line 1145 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EBracket((yyvsp[-1].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2788 "Parser.C" /* yacc.c:1646  */
    break;

  case 63:
#line 1146 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[-1].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 2794 "Parser.C" /* yacc.c:1646  */
    break;

  case 64:
#line 1148 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EIndex((yyvsp[-3].exp_), (yyvsp[-1].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2800 "Parser.C" /* yacc.c:1646  */
    break;

  case 65:
#line 1149 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EQCon((yyvsp[0].qcon_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2806 "Parser.C" /* yacc.c:1646  */
    break;

  case 66:
#line 1150 "grammar.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listexp_)->begin(),(yyvsp[-1].listexp_)->end()) ;(yyval.exp_) = new EFunCall((yyvsp[-3].exp_), (yyvsp[-1].listexp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2812 "Parser.C" /* yacc.c:1646  */
    break;

  case 67:
#line 1151 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 2818 "Parser.C" /* yacc.c:1646  */
    break;

  case 68:
#line 1153 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EStrucProj((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2824 "Parser.C" /* yacc.c:1646  */
    break;

  case 69:
#line 1154 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EStrucPro((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2830 "Parser.C" /* yacc.c:1646  */
    break;

  case 70:
#line 1155 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EInC((yyvsp[-1].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2836 "Parser.C" /* yacc.c:1646  */
    break;

  case 71:
#line 1156 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDeC((yyvsp[-1].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2842 "Parser.C" /* yacc.c:1646  */
    break;

  case 72:
#line 1157 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDeRef((yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2848 "Parser.C" /* yacc.c:1646  */
    break;

  case 73:
#line 1158 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 2854 "Parser.C" /* yacc.c:1646  */
    break;

  case 74:
#line 1160 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EInCr((yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2860 "Parser.C" /* yacc.c:1646  */
    break;

  case 75:
#line 1161 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDeCr((yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2866 "Parser.C" /* yacc.c:1646  */
    break;

  case 76:
#line 1162 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ENeg((yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2872 "Parser.C" /* yacc.c:1646  */
    break;

  case 77:
#line 1163 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 2878 "Parser.C" /* yacc.c:1646  */
    break;

  case 78:
#line 1165 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EMul((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2884 "Parser.C" /* yacc.c:1646  */
    break;

  case 79:
#line 1166 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDiv((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2890 "Parser.C" /* yacc.c:1646  */
    break;

  case 80:
#line 1167 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ERem((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2896 "Parser.C" /* yacc.c:1646  */
    break;

  case 81:
#line 1168 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 2902 "Parser.C" /* yacc.c:1646  */
    break;

  case 82:
#line 1170 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EAdd((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2908 "Parser.C" /* yacc.c:1646  */
    break;

  case 83:
#line 1171 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ESub((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2914 "Parser.C" /* yacc.c:1646  */
    break;

  case 84:
#line 1172 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 2920 "Parser.C" /* yacc.c:1646  */
    break;

  case 85:
#line 1174 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ELSh((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2926 "Parser.C" /* yacc.c:1646  */
    break;

  case 86:
#line 1175 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ERSh((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2932 "Parser.C" /* yacc.c:1646  */
    break;

  case 87:
#line 1176 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 2938 "Parser.C" /* yacc.c:1646  */
    break;

  case 88:
#line 1178 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EGT((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2944 "Parser.C" /* yacc.c:1646  */
    break;

  case 89:
#line 1179 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ELT((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2950 "Parser.C" /* yacc.c:1646  */
    break;

  case 90:
#line 1180 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EGQ((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2956 "Parser.C" /* yacc.c:1646  */
    break;

  case 91:
#line 1181 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EGQ1((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2962 "Parser.C" /* yacc.c:1646  */
    break;

  case 92:
#line 1182 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ELQ((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2968 "Parser.C" /* yacc.c:1646  */
    break;

  case 93:
#line 1183 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ELQ1((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2974 "Parser.C" /* yacc.c:1646  */
    break;

  case 94:
#line 1184 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 2980 "Parser.C" /* yacc.c:1646  */
    break;

  case 95:
#line 1186 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EQu((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2986 "Parser.C" /* yacc.c:1646  */
    break;

  case 96:
#line 1187 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EIQ((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 2992 "Parser.C" /* yacc.c:1646  */
    break;

  case 97:
#line 1188 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 2998 "Parser.C" /* yacc.c:1646  */
    break;

  case 98:
#line 1190 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EAnd((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 3004 "Parser.C" /* yacc.c:1646  */
    break;

  case 99:
#line 1191 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 3010 "Parser.C" /* yacc.c:1646  */
    break;

  case 100:
#line 1193 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EOr((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 3016 "Parser.C" /* yacc.c:1646  */
    break;

  case 101:
#line 1194 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 3022 "Parser.C" /* yacc.c:1646  */
    break;

  case 102:
#line 1196 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EIs((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 3028 "Parser.C" /* yacc.c:1646  */
    break;

  case 103:
#line 1197 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EIsP((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 3034 "Parser.C" /* yacc.c:1646  */
    break;

  case 104:
#line 1198 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EIsM((yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 3040 "Parser.C" /* yacc.c:1646  */
    break;

  case 105:
#line 1199 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ECond((yyvsp[-4].exp_), (yyvsp[-2].exp_), (yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 3046 "Parser.C" /* yacc.c:1646  */
    break;

  case 106:
#line 1200 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 3052 "Parser.C" /* yacc.c:1646  */
    break;

  case 107:
#line 1202 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EEx((yyvsp[0].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
#line 3058 "Parser.C" /* yacc.c:1646  */
    break;

  case 108:
#line 1203 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 3064 "Parser.C" /* yacc.c:1646  */
    break;

  case 109:
#line 1205 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 3070 "Parser.C" /* yacc.c:1646  */
    break;

  case 110:
#line 1207 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 3076 "Parser.C" /* yacc.c:1646  */
    break;

  case 111:
#line 1209 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 3082 "Parser.C" /* yacc.c:1646  */
    break;

  case 112:
#line 1211 "grammar.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_); YY_RESULT_Exp_= (yyval.exp_); }
#line 3088 "Parser.C" /* yacc.c:1646  */
    break;

  case 113:
#line 1213 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listexp_) = new ListExp(); YY_RESULT_ListExp_= (yyval.listexp_); }
#line 3094 "Parser.C" /* yacc.c:1646  */
    break;

  case 114:
#line 1214 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listexp_) = new ListExp() ; (yyval.listexp_)->push_back((yyvsp[0].exp_)); YY_RESULT_ListExp_= (yyval.listexp_); }
#line 3100 "Parser.C" /* yacc.c:1646  */
    break;

  case 115:
#line 1215 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listexp_)->push_back((yyvsp[-2].exp_)) ; (yyval.listexp_) = (yyvsp[0].listexp_) ; YY_RESULT_ListExp_= (yyval.listexp_); }
#line 3106 "Parser.C" /* yacc.c:1646  */
    break;

  case 116:
#line 1216 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listexp_) = new ListExp(); YY_RESULT_ListExp_= (yyval.listexp_); }
#line 3112 "Parser.C" /* yacc.c:1646  */
    break;

  case 117:
#line 1217 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listexp_)->push_back((yyvsp[-1].exp_)) ; (yyval.listexp_) = (yyvsp[0].listexp_) ; YY_RESULT_ListExp_= (yyval.listexp_); }
#line 3118 "Parser.C" /* yacc.c:1646  */
    break;

  case 118:
#line 1219 "grammar.y" /* yacc.c:1646  */
    {  (yyval.tempinst_) = new TemplateInst((yyvsp[-3].id_), (yyvsp[-1].typelist_)); YY_RESULT_TempInst_= (yyval.tempinst_); }
#line 3124 "Parser.C" /* yacc.c:1646  */
    break;

  case 119:
#line 1221 "grammar.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[0].listtype_)->begin(),(yyvsp[0].listtype_)->end()) ;(yyval.typelist_) = new TypeListDef((yyvsp[0].listtype_)); YY_RESULT_TypeList_= (yyval.typelist_); }
#line 3130 "Parser.C" /* yacc.c:1646  */
    break;

  case 120:
#line 1223 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listtype_) = new ListType(); YY_RESULT_ListType_= (yyval.listtype_); }
#line 3136 "Parser.C" /* yacc.c:1646  */
    break;

  case 121:
#line 1224 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listtype_) = new ListType() ; (yyval.listtype_)->push_back((yyvsp[0].type_)); YY_RESULT_ListType_= (yyval.listtype_); }
#line 3142 "Parser.C" /* yacc.c:1646  */
    break;

  case 122:
#line 1225 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listtype_)->push_back((yyvsp[-2].type_)) ; (yyval.listtype_) = (yyvsp[0].listtype_) ; YY_RESULT_ListType_= (yyval.listtype_); }
#line 3148 "Parser.C" /* yacc.c:1646  */
    break;

  case 123:
#line 1226 "grammar.y" /* yacc.c:1646  */
    {  (yyval.listtype_) = new ListType(); YY_RESULT_ListType_= (yyval.listtype_); }
#line 3154 "Parser.C" /* yacc.c:1646  */
    break;

  case 124:
#line 1227 "grammar.y" /* yacc.c:1646  */
    {  (yyvsp[0].listtype_)->push_back((yyvsp[-1].type_)) ; (yyval.listtype_) = (yyvsp[0].listtype_) ; YY_RESULT_ListType_= (yyval.listtype_); }
#line 3160 "Parser.C" /* yacc.c:1646  */
    break;

  case 125:
#line 1229 "grammar.y" /* yacc.c:1646  */
    {  (yyval.type_) = new Pointer((yyvsp[-1].btype_)); YY_RESULT_Type_= (yyval.type_); }
#line 3166 "Parser.C" /* yacc.c:1646  */
    break;

  case 126:
#line 1230 "grammar.y" /* yacc.c:1646  */
    {  (yyval.type_) = new Reference((yyvsp[-1].btype_)); YY_RESULT_Type_= (yyval.type_); }
#line 3172 "Parser.C" /* yacc.c:1646  */
    break;

  case 127:
#line 1231 "grammar.y" /* yacc.c:1646  */
    {  (yyval.type_) = new BaseType((yyvsp[0].btype_)); YY_RESULT_Type_= (yyval.type_); }
#line 3178 "Parser.C" /* yacc.c:1646  */
    break;

  case 128:
#line 1233 "grammar.y" /* yacc.c:1646  */
    {  (yyval.btype_) = new TQCon((yyvsp[0].qcon_)); YY_RESULT_BType_= (yyval.btype_); }
#line 3184 "Parser.C" /* yacc.c:1646  */
    break;

  case 129:
#line 1234 "grammar.y" /* yacc.c:1646  */
    {  (yyval.btype_) = new TInt(); YY_RESULT_BType_= (yyval.btype_); }
#line 3190 "Parser.C" /* yacc.c:1646  */
    break;

  case 130:
#line 1235 "grammar.y" /* yacc.c:1646  */
    {  (yyval.btype_) = new TVoid(); YY_RESULT_BType_= (yyval.btype_); }
#line 3196 "Parser.C" /* yacc.c:1646  */
    break;

  case 131:
#line 1236 "grammar.y" /* yacc.c:1646  */
    {  (yyval.btype_) = new TBool(); YY_RESULT_BType_= (yyval.btype_); }
#line 3202 "Parser.C" /* yacc.c:1646  */
    break;

  case 132:
#line 1237 "grammar.y" /* yacc.c:1646  */
    {  (yyval.btype_) = new TDouble(); YY_RESULT_BType_= (yyval.btype_); }
#line 3208 "Parser.C" /* yacc.c:1646  */
    break;

  case 133:
#line 1239 "grammar.y" /* yacc.c:1646  */
    {  (yyval.literal_) = new LStringList((yyvsp[0].stringlist_)); YY_RESULT_Literal_= (yyval.literal_); }
#line 3214 "Parser.C" /* yacc.c:1646  */
    break;

  case 134:
#line 1240 "grammar.y" /* yacc.c:1646  */
    {  (yyval.literal_) = new LInt((yyvsp[0].int_)); YY_RESULT_Literal_= (yyval.literal_); }
#line 3220 "Parser.C" /* yacc.c:1646  */
    break;

  case 135:
#line 1241 "grammar.y" /* yacc.c:1646  */
    {  (yyval.literal_) = new LDouble((yyvsp[0].double_)); YY_RESULT_Literal_= (yyval.literal_); }
#line 3226 "Parser.C" /* yacc.c:1646  */
    break;

  case 136:
#line 1242 "grammar.y" /* yacc.c:1646  */
    {  (yyval.literal_) = new LChar((yyvsp[0].char_)); YY_RESULT_Literal_= (yyval.literal_); }
#line 3232 "Parser.C" /* yacc.c:1646  */
    break;

  case 137:
#line 1244 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stringlist_) = new LStringListDef((yyvsp[-1].stringlist_), (yyvsp[0].string_)); YY_RESULT_StringList_= (yyval.stringlist_); }
#line 3238 "Parser.C" /* yacc.c:1646  */
    break;

  case 138:
#line 1245 "grammar.y" /* yacc.c:1646  */
    {  (yyval.stringlist_) = new LString((yyvsp[0].string_)); YY_RESULT_StringList_= (yyval.stringlist_); }
#line 3244 "Parser.C" /* yacc.c:1646  */
    break;

  case 139:
#line 1247 "grammar.y" /* yacc.c:1646  */
    {  (yyval.id_) = new Identif((yyvsp[0].string_)); YY_RESULT_Id_= (yyval.id_); }
#line 3250 "Parser.C" /* yacc.c:1646  */
    break;


#line 3254 "Parser.C" /* yacc.c:1646  */
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
