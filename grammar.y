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



static Def* YY_RESULT_Def_ = 0;
Def* pDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Def_;
  }
}
Def* pDef(const char *str)
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
    return YY_RESULT_Def_;
  }
}

static ListArg* YY_RESULT_ListArg_ = 0;
ListArg* pListArg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArg_;
  }
}
ListArg* pListArg(const char *str)
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
    return YY_RESULT_ListArg_;
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

static ListId* YY_RESULT_ListId_ = 0;
ListId* pListId(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListId_;
  }
}
ListId* pListId(const char *str)
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
    return YY_RESULT_ListId_;
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

static Arg* YY_RESULT_Arg_ = 0;
Arg* pArg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Arg_;
  }
}
Arg* pArg(const char *str)
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
    return YY_RESULT_Arg_;
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

static NNa* YY_RESULT_NNa_ = 0;
NNa* pNNa(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_NNa_;
  }
}
NNa* pNNa(const char *str)
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
    return YY_RESULT_NNa_;
  }
}



%}

%union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Def* def_;
  ListArg* listarg_;
  ListStm* liststm_;
  Stm* stm_;
  ListId* listid_;
  ListType* listtype_;
  Arg* arg_;
  ListExp* listexp_;
  Type* type_;
  Exp* exp_;
  NNa* nna_;

}


%token _ERROR_
%token _SYMB_0    //   (
%token _SYMB_1    //   )
%token _SYMB_2    //   {
%token _SYMB_3    //   }
%token _SYMB_4    //   ,
%token _SYMB_5    //   ;
%token _SYMB_6    //   =
%token _SYMB_7    //   <
%token _SYMB_8    //   >
%token _SYMB_9    //   [
%token _SYMB_10    //   ]
%token _SYMB_11    //   ::
%token _SYMB_12    //   .
%token _SYMB_13    //   ->
%token _SYMB_14    //   ++
%token _SYMB_15    //   --
%token _SYMB_16    //   *
%token _SYMB_17    //   !
%token _SYMB_18    //   /
%token _SYMB_19    //   %
%token _SYMB_20    //   +
%token _SYMB_21    //   -
%token _SYMB_22    //   <<
%token _SYMB_23    //   >>
%token _SYMB_24    //   <=
%token _SYMB_25    //   >=
%token _SYMB_26    //   !=
%token _SYMB_27    //   ==
%token _SYMB_28    //   &&
%token _SYMB_29    //   ||
%token _SYMB_30    //   +=
%token _SYMB_31    //   -=
%token _SYMB_32    //   ?
%token _SYMB_33    //   :
%token _SYMB_34    //   bool
%token _SYMB_35    //   do
%token _SYMB_36    //   double
%token _SYMB_37    //   else
%token _SYMB_38    //   for
%token _SYMB_39    //   ident
%token _SYMB_40    //   if
%token _SYMB_41    //   int
%token _SYMB_42    //   return
%token _SYMB_43    //   string
%token _SYMB_44    //   struct
%token _SYMB_45    //   throw
%token _SYMB_46    //   typedef
%token _SYMB_47    //   void
%token _SYMB_48    //   while
%token<string_> _SYMB_49    //   Id

%type <def_> Def
%type <listarg_> ListArg
%type <liststm_> ListStm
%type <stm_> Stm
%type <listid_> ListId
%type <listtype_> ListType
%type <arg_> Arg
%type <exp_> Exp16
%type <exp_> Exp15
%type <listexp_> ListExp
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
%type <type_> Type
%type <exp_> Exp
%type <nna_> NNa
%type <exp_> Exp5
%type <exp_> Exp6
%type <exp_> Exp7

%token<string_> _STRING_
%token<int_> _INTEGER_

%%
Def : Type _SYMB_49 _SYMB_0 ListArg _SYMB_1 _SYMB_2 ListStm _SYMB_3 {  std::reverse($4->begin(),$4->end()) ;$$ = new Function($1, $2, $4, $7); YY_RESULT_Def_= $$; } 
;
ListArg : /* empty */ {  $$ = new ListArg(); YY_RESULT_ListArg_= $$; } 
  | Arg {  $$ = new ListArg() ; $$->push_back($1); YY_RESULT_ListArg_= $$; }
  | Arg _SYMB_4 ListArg {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListArg_= $$; }
;
ListStm : /* empty */ {  $$ = new ListStm(); YY_RESULT_ListStm_= $$; } 
  | ListStm Stm {  $1->push_back($2) ; $$ = $1 ; YY_RESULT_ListStm_= $$; }
;
Stm : Type _SYMB_49 _SYMB_5 {  $$ = new StatementDeclaration($1, $2); YY_RESULT_Stm_= $$; } 
  | Type _SYMB_49 _SYMB_4 ListId _SYMB_5 {  std::reverse($4->begin(),$4->end()) ;$$ = new StatementDeclarations($1, $2, $4); YY_RESULT_Stm_= $$; }
  | Type _SYMB_49 _SYMB_6 Exp _SYMB_5 {  $$ = new StatementInitialization($1, $2, $4); YY_RESULT_Stm_= $$; }
  | _SYMB_42 Exp _SYMB_5 {  $$ = new StatementReturn($2); YY_RESULT_Stm_= $$; }
  | _SYMB_48 _SYMB_0 Exp _SYMB_1 Stm _SYMB_5 {  $$ = new StatementWhile($3, $5); YY_RESULT_Stm_= $$; }
  | _SYMB_35 Stm _SYMB_5 _SYMB_48 _SYMB_0 Exp _SYMB_1 _SYMB_5 {  $$ = new StatementDo($2, $6); YY_RESULT_Stm_= $$; }
  | _SYMB_38 _SYMB_0 Type _SYMB_49 _SYMB_6 Exp _SYMB_5 Exp _SYMB_5 Stm _SYMB_1 Stm _SYMB_5 {  $$ = new StatementFor($3, $4, $6, $8, $10, $12); YY_RESULT_Stm_= $$; }
  | _SYMB_40 _SYMB_0 Exp _SYMB_1 Stm _SYMB_5 {  $$ = new StatementIf($3, $5); YY_RESULT_Stm_= $$; }
  | _SYMB_40 _SYMB_0 Exp _SYMB_1 Stm _SYMB_5 _SYMB_37 Stm _SYMB_5 {  $$ = new StatementIfElse($3, $5, $8); YY_RESULT_Stm_= $$; }
  | _SYMB_2 ListStm _SYMB_3 {  $$ = new StatementBlock($2); YY_RESULT_Stm_= $$; }
  | _SYMB_46 Type _SYMB_7 Type _SYMB_8 _SYMB_49 _SYMB_5 {  $$ = new StatementTypedef($2, $4, $6); YY_RESULT_Stm_= $$; }
  | _SYMB_44 _SYMB_49 _SYMB_2 ListStm _SYMB_3 _SYMB_5 {  $$ = new StatementStruct($2, $4); YY_RESULT_Stm_= $$; }
  | _SYMB_39 _SYMB_7 ListType _SYMB_8 _SYMB_5 {  std::reverse($3->begin(),$3->end()) ;$$ = new TemplateInstantiations($3); YY_RESULT_Stm_= $$; }
  | Exp _SYMB_5 {  $$ = new StatementDefinition($1); YY_RESULT_Stm_= $$; }
;
ListId : /* empty */ {  $$ = new ListId(); YY_RESULT_ListId_= $$; } 
  | _SYMB_49 {  $$ = new ListId() ; $$->push_back($1); YY_RESULT_ListId_= $$; }
  | _SYMB_49 _SYMB_4 ListId {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListId_= $$; }
;
ListType : /* empty */ {  $$ = new ListType(); YY_RESULT_ListType_= $$; } 
  | Type {  $$ = new ListType() ; $$->push_back($1); YY_RESULT_ListType_= $$; }
  | Type _SYMB_4 ListType {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListType_= $$; }
;
Arg : Exp {  $$ = new ArgumentDefinition($1); YY_RESULT_Arg_= $$; } 
;
Exp16 : _INTEGER_ {  $$ = new EInteger($1); YY_RESULT_Exp_= $$; } 
  | _STRING_ {  $$ = new EString($1); YY_RESULT_Exp_= $$; }
  | _SYMB_0 Exp _SYMB_1 {  $$ = $2; YY_RESULT_Exp_= $$; }
;
Exp15 : Exp _SYMB_9 _SYMB_49 _SYMB_10 {  $$ = new EInde($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp _SYMB_11 _SYMB_49 {  $$ = new EQCon($1, $3); YY_RESULT_Exp_= $$; }
  | Exp _SYMB_0 ListExp _SYMB_1 {  std::reverse($3->begin(),$3->end()) ;$$ = new EFunC($1, $3); YY_RESULT_Exp_= $$; }
  | Exp16 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
ListExp : /* empty */ {  $$ = new ListExp(); YY_RESULT_ListExp_= $$; } 
  | Exp {  $$ = new ListExp() ; $$->push_back($1); YY_RESULT_ListExp_= $$; }
  | Exp _SYMB_4 ListExp {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListExp_= $$; }
;
Exp14 : Exp _SYMB_12 Exp {  $$ = new EStPP($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp _SYMB_13 Exp {  $$ = new EStPA($1, $3); YY_RESULT_Exp_= $$; }
  | Exp _SYMB_14 {  $$ = new EInEP($1); YY_RESULT_Exp_= $$; }
  | Exp _SYMB_15 {  $$ = new EDeEM($1); YY_RESULT_Exp_= $$; }
  | _SYMB_16 Exp {  $$ = new EDere($2); YY_RESULT_Exp_= $$; }
  | Exp15 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp13 : _SYMB_14 Exp {  $$ = new EInPE($2); YY_RESULT_Exp_= $$; } 
  | _SYMB_15 Exp {  $$ = new EDeME($2); YY_RESULT_Exp_= $$; }
  | _SYMB_17 Exp {  $$ = new ENega($2); YY_RESULT_Exp_= $$; }
  | Exp14 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp12 : Exp _SYMB_16 Exp {  $$ = new EMult($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp _SYMB_18 Exp {  $$ = new EDivi($1, $3); YY_RESULT_Exp_= $$; }
  | Exp _SYMB_19 Exp {  $$ = new ERema($1, $3); YY_RESULT_Exp_= $$; }
  | Exp13 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp11 : Exp _SYMB_20 Exp {  $$ = new EAddi($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp _SYMB_21 Exp {  $$ = new ESubt($1, $3); YY_RESULT_Exp_= $$; }
  | Exp12 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp10 : Exp _SYMB_22 Exp {  $$ = new ELShi($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp _SYMB_23 Exp {  $$ = new ERShi($1, $3); YY_RESULT_Exp_= $$; }
  | Exp11 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp9 : Exp _SYMB_7 Exp {  $$ = new ECoSm($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp _SYMB_8 Exp {  $$ = new ECoGr($1, $3); YY_RESULT_Exp_= $$; }
  | Exp _SYMB_24 Exp {  $$ = new ECoSE($1, $3); YY_RESULT_Exp_= $$; }
  | Exp _SYMB_25 Exp {  $$ = new ECoGE($1, $3); YY_RESULT_Exp_= $$; }
  | Exp10 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp8 : Exp _SYMB_26 Exp {  $$ = new EInEq($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp _SYMB_27 Exp {  $$ = new EEqua($1, $3); YY_RESULT_Exp_= $$; }
  | Exp9 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp4 : Exp _SYMB_28 Exp {  $$ = new EConj($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp5 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp3 : Exp _SYMB_29 Exp {  $$ = new EDisj($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp4 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp2 : Exp _SYMB_6 Exp {  $$ = new EAssi($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp _SYMB_30 Exp {  $$ = new EAsPl($1, $3); YY_RESULT_Exp_= $$; }
  | Exp _SYMB_31 Exp {  $$ = new EAsMi($1, $3); YY_RESULT_Exp_= $$; }
  | Exp _SYMB_32 Exp _SYMB_33 Exp {  $$ = new ECond($1, $3, $5); YY_RESULT_Exp_= $$; }
  | Exp3 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp1 : _SYMB_45 Exp {  $$ = new EExce($2); YY_RESULT_Exp_= $$; } 
  | Exp2 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Type : _SYMB_41 {  $$ = new TInt(); YY_RESULT_Type_= $$; } 
  | _SYMB_34 {  $$ = new TBool(); YY_RESULT_Type_= $$; }
  | _SYMB_36 {  $$ = new TDouble(); YY_RESULT_Type_= $$; }
  | _SYMB_47 {  $$ = new TVoid(); YY_RESULT_Type_= $$; }
  | _SYMB_43 {  $$ = new TString(); YY_RESULT_Type_= $$; }
;
Exp : NNa _SYMB_11 _SYMB_49 {  $$ = new SpecifierDefinition($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp1 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
NNa : _SYMB_49 {  $$ = new NamespaceName($1); YY_RESULT_NNa_= $$; } 
;
Exp5 : Exp6 {  $$ = $1; YY_RESULT_Exp_= $$; } 
;
Exp6 : Exp7 {  $$ = $1; YY_RESULT_Exp_= $$; } 
;
Exp7 : Exp8 {  $$ = $1; YY_RESULT_Exp_= $$; } 
;

