/* This Bison file was machine-generated by BNFC */
%{
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



%}

%union
{
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

}


%token _ERROR_
%token _SYMB_0    //   ;
%token _SYMB_1    //   (
%token _SYMB_2    //   )
%token _SYMB_3    //   ,
%token _SYMB_4    //   {
%token _SYMB_5    //   }
%token _SYMB_6    //   =
%token _SYMB_7    //   ::
%token _SYMB_8    //   [
%token _SYMB_9    //   ]
%token _SYMB_10    //   .
%token _SYMB_11    //   ->
%token _SYMB_12    //   ++
%token _SYMB_13    //   --
%token _SYMB_14    //   *
%token _SYMB_15    //   !
%token _SYMB_16    //   /
%token _SYMB_17    //   %
%token _SYMB_18    //   +
%token _SYMB_19    //   -
%token _SYMB_20    //   <<
%token _SYMB_21    //   >>
%token _SYMB_22    //   >
%token _SYMB_23    //   <
%token _SYMB_24    //   =>
%token _SYMB_25    //   >=
%token _SYMB_26    //   <=
%token _SYMB_27    //   =<
%token _SYMB_28    //   ==
%token _SYMB_29    //   !=
%token _SYMB_30    //   &&
%token _SYMB_31    //   ||
%token _SYMB_32    //   +=
%token _SYMB_33    //   -=
%token _SYMB_34    //   ?
%token _SYMB_35    //   :
%token _SYMB_36    //   &
%token _SYMB_37    //   bool
%token _SYMB_38    //   const
%token _SYMB_39    //   do
%token _SYMB_40    //   double
%token _SYMB_41    //   else
%token _SYMB_42    //   exit
%token _SYMB_43    //   for
%token _SYMB_44    //   if
%token _SYMB_45    //   inline
%token _SYMB_46    //   int
%token _SYMB_47    //   namespace
%token _SYMB_48    //   return
%token _SYMB_49    //   struct
%token _SYMB_50    //   throw
%token _SYMB_51    //   typedef
%token _SYMB_52    //   using
%token _SYMB_53    //   void
%token _SYMB_54    //   while

%type <program_> Program
%type <definition_> Definition
%type <listdefinition_> ListDefinition
%type <argumentlist_> ArgumentList
%type <listargument_> ListArgument
%type <argument_> Argument
%type <body_> Body
%type <stm_> Stm
%type <liststm_> ListStm
%type <struct_> Struct
%type <typedef_> TypeDef
%type <decl_> Decl
%type <var_> Var
%type <listvar_> ListVar
%type <listdecl_> ListDecl
%type <qcon_> QCon
%type <name_> Name
%type <exp_> Exp16
%type <exp_> Exp15
%type <exp_> Exp14
%type <exp_> Exp13
%type <exp_> Exp12
%type <exp_> Exp11
%type <exp_> Exp10
%type <exp_> Exp9
%type <exp_> Exp8
%type <exp_> Exp4
%type <exp_> Exp3
%type <exp_> Exp2
%type <exp_> Exp1
%type <exp_> Exp
%type <exp_> Exp5
%type <exp_> Exp6
%type <exp_> Exp7
%type <listexp_> ListExp
%type <tempinst_> TempInst
%type <typelist_> TypeList
%type <listtype_> ListType
%type <type_> Type
%type <btype_> BType
%type <literal_> Literal
%type <stringlist_> StringList
%type <id_> Id

%token<string_> _STRING_
%token<char_> _CHAR_
%token<int_> _INTEGER_
%token<double_> _DOUBLE_
%token<string_> _IDENT_

%%
Program : ListDefinition {  $$ = new Prog($1); YY_RESULT_Program_= $$; } 
;
Definition : _SYMB_45 Type Id ArgumentList Body {  $$ = new FunctionDefIn($2, $3, $4, $5); YY_RESULT_Definition_= $$; } 
  | Type Id ArgumentList Body {  $$ = new FunctionDef($1, $2, $3, $4); YY_RESULT_Definition_= $$; }
  | Type Id ArgumentList _SYMB_0 {  $$ = new Function($1, $2, $3); YY_RESULT_Definition_= $$; }
  | Decl _SYMB_0 {  $$ = new GlobVar($1); YY_RESULT_Definition_= $$; }
  | Struct _SYMB_0 {  $$ = new GlobStruct($1); YY_RESULT_Definition_= $$; }
  | TypeDef {  $$ = new GlobTypeDef($1); YY_RESULT_Definition_= $$; }
  | _SYMB_52 _SYMB_47 Id _SYMB_0 {  $$ = new UsingNSDef($3); YY_RESULT_Definition_= $$; }
  | _SYMB_52 QCon _SYMB_0 {  $$ = new UsingDef($2); YY_RESULT_Definition_= $$; }
;
ListDefinition : /* empty */ {  $$ = new ListDefinition(); YY_RESULT_ListDefinition_= $$; } 
  | ListDefinition Definition {  $1->push_back($2) ; $$ = $1 ; YY_RESULT_ListDefinition_= $$; }
;
ArgumentList : _SYMB_1 ListArgument _SYMB_2 {  std::reverse($2->begin(),$2->end()) ;$$ = new ArgumentListDef($2); YY_RESULT_ArgumentList_= $$; } 
;
ListArgument : /* empty */ {  $$ = new ListArgument(); YY_RESULT_ListArgument_= $$; } 
  | Argument {  $$ = new ListArgument() ; $$->push_back($1); YY_RESULT_ListArgument_= $$; }
  | Argument _SYMB_3 ListArgument {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListArgument_= $$; }
  | /* empty */ {  $$ = new ListArgument(); YY_RESULT_ListArgument_= $$; }
  | Argument ListArgument {  $2->push_back($1) ; $$ = $2 ; YY_RESULT_ListArgument_= $$; }
;
Argument : _SYMB_38 Type Exp {  $$ = new ArgumentConstDecl($2, $3); YY_RESULT_Argument_= $$; } 
  | Type Exp {  $$ = new ArgumentDecl($1, $2); YY_RESULT_Argument_= $$; }
  | _SYMB_38 Type {  $$ = new ArgumentConsttype($2); YY_RESULT_Argument_= $$; }
  | Type {  $$ = new ArgumentType($1); YY_RESULT_Argument_= $$; }
;
Body : _SYMB_4 ListStm _SYMB_5 {  $$ = new FuntionBody($2); YY_RESULT_Body_= $$; } 
  | _SYMB_4 _SYMB_0 _SYMB_5 {  $$ = new EmptyBody(); YY_RESULT_Body_= $$; }
;
Stm : Decl _SYMB_0 {  $$ = new StmDecl($1); YY_RESULT_Stm_= $$; } 
  | _SYMB_48 Exp _SYMB_0 {  $$ = new StmReturn($2); YY_RESULT_Stm_= $$; }
  | _SYMB_42 _SYMB_1 Exp _SYMB_2 _SYMB_0 {  $$ = new StmExit($3); YY_RESULT_Stm_= $$; }
  | _SYMB_54 _SYMB_1 Exp _SYMB_2 Stm {  $$ = new StmWhile($3, $5); YY_RESULT_Stm_= $$; }
  | _SYMB_39 Stm _SYMB_54 _SYMB_1 Exp _SYMB_2 _SYMB_0 {  $$ = new StmDoWhile($2, $5); YY_RESULT_Stm_= $$; }
  | _SYMB_43 _SYMB_1 Decl _SYMB_0 Exp _SYMB_0 Exp _SYMB_2 Stm {  $$ = new StmFor($3, $5, $7, $9); YY_RESULT_Stm_= $$; }
  | _SYMB_44 _SYMB_1 Exp _SYMB_2 Stm _SYMB_41 Stm {  $$ = new StmIfElse($3, $5, $7); YY_RESULT_Stm_= $$; }
  | _SYMB_44 _SYMB_1 Exp _SYMB_2 Stm {  $$ = new StmIf($3, $5); YY_RESULT_Stm_= $$; }
  | _SYMB_4 ListStm _SYMB_5 {  $$ = new StmBlock($2); YY_RESULT_Stm_= $$; }
  | _SYMB_4 _SYMB_5 {  $$ = new StmEmptyBlock(); YY_RESULT_Stm_= $$; }
  | TypeDef {  $$ = new StmTypeDef($1); YY_RESULT_Stm_= $$; }
  | Struct _SYMB_0 {  $$ = new StmeStruct($1); YY_RESULT_Stm_= $$; }
  | Exp _SYMB_0 {  $$ = new StmExpression($1); YY_RESULT_Stm_= $$; }
;
ListStm : /* empty */ {  $$ = new ListStm(); YY_RESULT_ListStm_= $$; } 
  | ListStm Stm {  $1->push_back($2) ; $$ = $1 ; YY_RESULT_ListStm_= $$; }
;
Struct : _SYMB_49 Id _SYMB_4 ListDecl _SYMB_5 {  std::reverse($4->begin(),$4->end()) ;$$ = new StructDef($2, $4); YY_RESULT_Struct_= $$; } 
;
TypeDef : _SYMB_51 Type Id _SYMB_0 {  $$ = new TypeDefForm($2, $3); YY_RESULT_TypeDef_= $$; } 
  | _SYMB_51 Type _SYMB_0 {  $$ = new TypeDefForm2($2); YY_RESULT_TypeDef_= $$; }
;
Decl : _SYMB_38 Type ListVar {  std::reverse($3->begin(),$3->end()) ;$$ = new ConstDecl($2, $3); YY_RESULT_Decl_= $$; } 
  | Type ListVar {  std::reverse($2->begin(),$2->end()) ;$$ = new Declaration($1, $2); YY_RESULT_Decl_= $$; }
;
Var : Id _SYMB_6 Exp {  $$ = new VariableInitialization($1, $3); YY_RESULT_Var_= $$; } 
  | Id {  $$ = new VariableName($1); YY_RESULT_Var_= $$; }
;
ListVar : Var {  $$ = new ListVar() ; $$->push_back($1); YY_RESULT_ListVar_= $$; } 
  | Var _SYMB_3 ListVar {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListVar_= $$; }
  | /* empty */ {  $$ = new ListVar(); YY_RESULT_ListVar_= $$; }
  | Var ListVar {  $2->push_back($1) ; $$ = $2 ; YY_RESULT_ListVar_= $$; }
;
ListDecl : /* empty */ {  $$ = new ListDecl(); YY_RESULT_ListDecl_= $$; } 
  | Decl {  $$ = new ListDecl() ; $$->push_back($1); YY_RESULT_ListDecl_= $$; }
  | Decl _SYMB_0 ListDecl {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListDecl_= $$; }
  | /* empty */ {  $$ = new ListDecl(); YY_RESULT_ListDecl_= $$; }
  | Decl ListDecl {  $2->push_back($1) ; $$ = $2 ; YY_RESULT_ListDecl_= $$; }
;
QCon : QCon _SYMB_7 Name {  $$ = new QualCon($1, $3); YY_RESULT_QCon_= $$; } 
  | Name {  $$ = new QualConN($1); YY_RESULT_QCon_= $$; }
;
Name : Id {  $$ = new IdName($1); YY_RESULT_Name_= $$; } 
  | TempInst {  $$ = new TempInstName($1); YY_RESULT_Name_= $$; }
;
Exp16 : Id {  $$ = new EIdent($1); YY_RESULT_Exp_= $$; } 
  | Literal {  $$ = new ELiteral($1); YY_RESULT_Exp_= $$; }
  | _SYMB_1 Exp _SYMB_2 {  $$ = new EBracket($2); YY_RESULT_Exp_= $$; }
  | _SYMB_1 Exp _SYMB_2 {  $$ = $2; YY_RESULT_Exp_= $$; }
;
Exp15 : Exp15 _SYMB_8 Exp _SYMB_9 {  $$ = new EIndex($1, $3); YY_RESULT_Exp_= $$; } 
  | QCon {  $$ = new EQCon($1); YY_RESULT_Exp_= $$; }
  | Exp15 _SYMB_1 ListExp _SYMB_2 {  std::reverse($3->begin(),$3->end()) ;$$ = new EFunCall($1, $3); YY_RESULT_Exp_= $$; }
  | Exp16 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp14 : Exp15 _SYMB_10 Exp15 {  $$ = new EStrucProj($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp15 _SYMB_11 Exp15 {  $$ = new EStrucPro($1, $3); YY_RESULT_Exp_= $$; }
  | Exp15 _SYMB_12 {  $$ = new EInC($1); YY_RESULT_Exp_= $$; }
  | Exp15 _SYMB_13 {  $$ = new EDeC($1); YY_RESULT_Exp_= $$; }
  | _SYMB_14 Exp15 {  $$ = new EDeRef($2); YY_RESULT_Exp_= $$; }
  | Exp15 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp13 : _SYMB_12 Exp14 {  $$ = new EInCr($2); YY_RESULT_Exp_= $$; } 
  | _SYMB_13 Exp14 {  $$ = new EDeCr($2); YY_RESULT_Exp_= $$; }
  | _SYMB_15 Exp14 {  $$ = new ENeg($2); YY_RESULT_Exp_= $$; }
  | Exp14 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp12 : Exp12 _SYMB_14 Exp13 {  $$ = new EMul($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp12 _SYMB_16 Exp13 {  $$ = new EDiv($1, $3); YY_RESULT_Exp_= $$; }
  | Exp12 _SYMB_17 Exp13 {  $$ = new ERem($1, $3); YY_RESULT_Exp_= $$; }
  | Exp13 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp11 : Exp11 _SYMB_18 Exp12 {  $$ = new EAdd($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp11 _SYMB_19 Exp12 {  $$ = new ESub($1, $3); YY_RESULT_Exp_= $$; }
  | Exp12 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp10 : Exp10 _SYMB_20 Exp11 {  $$ = new ELSh($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp10 _SYMB_21 Exp11 {  $$ = new ERSh($1, $3); YY_RESULT_Exp_= $$; }
  | Exp11 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp9 : Exp9 _SYMB_22 Exp10 {  $$ = new EGT($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp9 _SYMB_23 Exp10 {  $$ = new ELT($1, $3); YY_RESULT_Exp_= $$; }
  | Exp9 _SYMB_24 Exp10 {  $$ = new EGQ($1, $3); YY_RESULT_Exp_= $$; }
  | Exp9 _SYMB_25 Exp10 {  $$ = new EGQ1($1, $3); YY_RESULT_Exp_= $$; }
  | Exp9 _SYMB_26 Exp10 {  $$ = new ELQ($1, $3); YY_RESULT_Exp_= $$; }
  | Exp9 _SYMB_27 Exp10 {  $$ = new ELQ1($1, $3); YY_RESULT_Exp_= $$; }
  | Exp10 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp8 : Exp8 _SYMB_28 Exp9 {  $$ = new EQu($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp8 _SYMB_29 Exp9 {  $$ = new EIQ($1, $3); YY_RESULT_Exp_= $$; }
  | Exp9 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp4 : Exp4 _SYMB_30 Exp5 {  $$ = new EAnd($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp5 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp3 : Exp3 _SYMB_31 Exp4 {  $$ = new EOr($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp4 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp2 : Exp2 _SYMB_6 Exp3 {  $$ = new EIs($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp2 _SYMB_32 Exp3 {  $$ = new EIsP($1, $3); YY_RESULT_Exp_= $$; }
  | Exp2 _SYMB_33 Exp3 {  $$ = new EIsM($1, $3); YY_RESULT_Exp_= $$; }
  | Exp2 _SYMB_34 Exp3 _SYMB_35 Exp3 {  $$ = new ECond($1, $3, $5); YY_RESULT_Exp_= $$; }
  | Exp3 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp1 : _SYMB_50 Exp2 {  $$ = new EEx($2); YY_RESULT_Exp_= $$; } 
  | Exp2 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp : Exp1 {  $$ = $1; YY_RESULT_Exp_= $$; } 
;
Exp5 : Exp6 {  $$ = $1; YY_RESULT_Exp_= $$; } 
;
Exp6 : Exp7 {  $$ = $1; YY_RESULT_Exp_= $$; } 
;
Exp7 : Exp8 {  $$ = $1; YY_RESULT_Exp_= $$; } 
;
ListExp : /* empty */ {  $$ = new ListExp(); YY_RESULT_ListExp_= $$; } 
  | Exp {  $$ = new ListExp() ; $$->push_back($1); YY_RESULT_ListExp_= $$; }
  | Exp _SYMB_3 ListExp {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListExp_= $$; }
  | /* empty */ {  $$ = new ListExp(); YY_RESULT_ListExp_= $$; }
  | Exp ListExp {  $2->push_back($1) ; $$ = $2 ; YY_RESULT_ListExp_= $$; }
;
TempInst : Id _SYMB_23 TypeList _SYMB_22 {  $$ = new TemplateInst($1, $3); YY_RESULT_TempInst_= $$; } 
;
TypeList : ListType {  std::reverse($1->begin(),$1->end()) ;$$ = new TypeListDef($1); YY_RESULT_TypeList_= $$; } 
;
ListType : /* empty */ {  $$ = new ListType(); YY_RESULT_ListType_= $$; } 
  | Type {  $$ = new ListType() ; $$->push_back($1); YY_RESULT_ListType_= $$; }
  | Type _SYMB_3 ListType {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListType_= $$; }
  | /* empty */ {  $$ = new ListType(); YY_RESULT_ListType_= $$; }
  | Type ListType {  $2->push_back($1) ; $$ = $2 ; YY_RESULT_ListType_= $$; }
;
Type : BType _SYMB_14 {  $$ = new Pointer($1); YY_RESULT_Type_= $$; } 
  | BType _SYMB_36 {  $$ = new Reference($1); YY_RESULT_Type_= $$; }
  | BType {  $$ = new BaseType($1); YY_RESULT_Type_= $$; }
;
BType : QCon {  $$ = new TQCon($1); YY_RESULT_BType_= $$; } 
  | _SYMB_46 {  $$ = new TInt(); YY_RESULT_BType_= $$; }
  | _SYMB_53 {  $$ = new TVoid(); YY_RESULT_BType_= $$; }
  | _SYMB_37 {  $$ = new TBool(); YY_RESULT_BType_= $$; }
  | _SYMB_40 {  $$ = new TDouble(); YY_RESULT_BType_= $$; }
;
Literal : StringList {  $$ = new LStringList($1); YY_RESULT_Literal_= $$; } 
  | _INTEGER_ {  $$ = new LInt($1); YY_RESULT_Literal_= $$; }
  | _DOUBLE_ {  $$ = new LDouble($1); YY_RESULT_Literal_= $$; }
  | _CHAR_ {  $$ = new LChar($1); YY_RESULT_Literal_= $$; }
;
StringList : StringList _STRING_ {  $$ = new LStringListDef($1, $2); YY_RESULT_StringList_= $$; } 
  | _STRING_ {  $$ = new LString($1); YY_RESULT_StringList_= $$; }
;
Id : _IDENT_ {  $$ = new Identif($1); YY_RESULT_Id_= $$; } 
;

