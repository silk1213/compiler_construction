#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include<vector>
#include<string>


class Program;
class Definition;
class ListDefinition;
class ArgumentList;
class ListArgument;
class Argument;
class Body;
class Stm;
class ListStm;
class Struct;
class TypeDef;
class Decl;
class Var;
class ListVar;
class ListDecl;
class QCon;
class Name;
class Exp;
class ListExp;
class TempInst;
class TypeList;
class ListType;
class Type;
class BType;
class Literal;
class StringList;
class Id;

typedef union
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
} YYSTYPE;

Program* pProgram(FILE *inp);
Program* pProgram(const char *str);
Definition* pDefinition(FILE *inp);
Definition* pDefinition(const char *str);
ListDefinition* pListDefinition(FILE *inp);
ListDefinition* pListDefinition(const char *str);
ArgumentList* pArgumentList(FILE *inp);
ArgumentList* pArgumentList(const char *str);
ListArgument* pListArgument(FILE *inp);
ListArgument* pListArgument(const char *str);
Argument* pArgument(FILE *inp);
Argument* pArgument(const char *str);
Body* pBody(FILE *inp);
Body* pBody(const char *str);
Stm* pStm(FILE *inp);
Stm* pStm(const char *str);
ListStm* pListStm(FILE *inp);
ListStm* pListStm(const char *str);
Struct* pStruct(FILE *inp);
Struct* pStruct(const char *str);
TypeDef* pTypeDef(FILE *inp);
TypeDef* pTypeDef(const char *str);
Decl* pDecl(FILE *inp);
Decl* pDecl(const char *str);
Var* pVar(FILE *inp);
Var* pVar(const char *str);
ListVar* pListVar(FILE *inp);
ListVar* pListVar(const char *str);
ListDecl* pListDecl(FILE *inp);
ListDecl* pListDecl(const char *str);
QCon* pQCon(FILE *inp);
QCon* pQCon(const char *str);
Name* pName(FILE *inp);
Name* pName(const char *str);
Exp* pExp(FILE *inp);
Exp* pExp(const char *str);
ListExp* pListExp(FILE *inp);
ListExp* pListExp(const char *str);
TempInst* pTempInst(FILE *inp);
TempInst* pTempInst(const char *str);
TypeList* pTypeList(FILE *inp);
TypeList* pTypeList(const char *str);
ListType* pListType(FILE *inp);
ListType* pListType(const char *str);
Type* pType(FILE *inp);
Type* pType(const char *str);
BType* pBType(FILE *inp);
BType* pBType(const char *str);
Literal* pLiteral(FILE *inp);
Literal* pLiteral(const char *str);
StringList* pStringList(FILE *inp);
StringList* pStringList(const char *str);
Id* pId(FILE *inp);
Id* pId(const char *str);



#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define _SYMB_31 290
#define _SYMB_32 291
#define _SYMB_33 292
#define _SYMB_34 293
#define _SYMB_35 294
#define _SYMB_36 295
#define _SYMB_37 296
#define _SYMB_38 297
#define _SYMB_39 298
#define _SYMB_40 299
#define _SYMB_41 300
#define _SYMB_42 301
#define _SYMB_43 302
#define _SYMB_44 303
#define _SYMB_45 304
#define _SYMB_46 305
#define _SYMB_47 306
#define _SYMB_48 307
#define _SYMB_49 308
#define _SYMB_50 309
#define _SYMB_51 310
#define _SYMB_52 311
#define _SYMB_53 312
#define _SYMB_54 313
#define _STRING_ 314
#define _CHAR_ 315
#define _INTEGER_ 316
#define _DOUBLE_ 317
#define _IDENT_ 318

extern YYSTYPE yylval;

#endif
