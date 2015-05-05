#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitProg(Prog *p);
  void visitDefinition(Definition *p); /* abstract class */
  void visitFunctionDefIn(FunctionDefIn *p);
  void visitFunctionDef(FunctionDef *p);
  void visitFunction(Function *p);
  void visitGlobVar(GlobVar *p);
  void visitGlobStruct(GlobStruct *p);
  void visitGlobTypeDef(GlobTypeDef *p);
  void visitUsingNSDef(UsingNSDef *p);
  void visitUsingDef(UsingDef *p);
  void visitListDefinition(ListDefinition* p);
  void visitArgumentList(ArgumentList *p); /* abstract class */
  void visitArgumentListDef(ArgumentListDef *p);
  void visitListArgument(ListArgument* p);
  void visitArgument(Argument *p); /* abstract class */
  void visitArgumentConstDecl(ArgumentConstDecl *p);
  void visitArgumentDecl(ArgumentDecl *p);
  void visitArgumentConsttype(ArgumentConsttype *p);
  void visitArgumentType(ArgumentType *p);
  void visitBody(Body *p); /* abstract class */
  void visitFuntionBody(FuntionBody *p);
  void visitEmptyBody(EmptyBody *p);
  void visitStm(Stm *p); /* abstract class */
  void visitStmDecl(StmDecl *p);
  void visitStmReturn(StmReturn *p);
  void visitStmExit(StmExit *p);
  void visitStmWhile(StmWhile *p);
  void visitStmDoWhile(StmDoWhile *p);
  void visitStmFor(StmFor *p);
  void visitStmIfElse(StmIfElse *p);
  void visitStmIf(StmIf *p);
  void visitStmBlock(StmBlock *p);
  void visitStmEmptyBlock(StmEmptyBlock *p);
  void visitStmTypeDef(StmTypeDef *p);
  void visitStmeStruct(StmeStruct *p);
  void visitStmExpression(StmExpression *p);
  void visitListStm(ListStm* p);
  void visitStruct(Struct *p); /* abstract class */
  void visitStructDef(StructDef *p);
  void visitTypeDef(TypeDef *p); /* abstract class */
  void visitTypeDefForm(TypeDefForm *p);
  void visitTypeDefForm2(TypeDefForm2 *p);
  void visitDecl(Decl *p); /* abstract class */
  void visitConstDecl(ConstDecl *p);
  void visitDeclaration(Declaration *p);
  void visitVar(Var *p); /* abstract class */
  void visitVariableInitialization(VariableInitialization *p);
  void visitVariableName(VariableName *p);
  void visitListVar(ListVar* p);
  void visitListDecl(ListDecl* p);
  void visitQCon(QCon *p); /* abstract class */
  void visitQualCon(QualCon *p);
  void visitQualConN(QualConN *p);
  void visitName(Name *p); /* abstract class */
  void visitIdName(IdName *p);
  void visitTempInstName(TempInstName *p);
  void visitExp(Exp *p); /* abstract class */
  void visitEIdent(EIdent *p);
  void visitELiteral(ELiteral *p);
  void visitEBracket(EBracket *p);
  void visitEIndex(EIndex *p);
  void visitEQCon(EQCon *p);
  void visitEFunCall(EFunCall *p);
  void visitEStrucProj(EStrucProj *p);
  void visitEStrucPro(EStrucPro *p);
  void visitEInC(EInC *p);
  void visitEDeC(EDeC *p);
  void visitEDeRef(EDeRef *p);
  void visitEInCr(EInCr *p);
  void visitEDeCr(EDeCr *p);
  void visitENeg(ENeg *p);
  void visitEMul(EMul *p);
  void visitEDiv(EDiv *p);
  void visitERem(ERem *p);
  void visitEAdd(EAdd *p);
  void visitESub(ESub *p);
  void visitELSh(ELSh *p);
  void visitERSh(ERSh *p);
  void visitEGT(EGT *p);
  void visitELT(ELT *p);
  void visitEGQ(EGQ *p);
  void visitEGQ1(EGQ1 *p);
  void visitELQ(ELQ *p);
  void visitELQ1(ELQ1 *p);
  void visitEQu(EQu *p);
  void visitEIQ(EIQ *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitEIs(EIs *p);
  void visitEIsP(EIsP *p);
  void visitEIsM(EIsM *p);
  void visitECond(ECond *p);
  void visitEEx(EEx *p);
  void visitListExp(ListExp* p);
  void visitTempInst(TempInst *p); /* abstract class */
  void visitTemplateInst(TemplateInst *p);
  void visitTypeList(TypeList *p); /* abstract class */
  void visitTypeListDef(TypeListDef *p);
  void visitListType(ListType* p);
  void visitType(Type *p); /* abstract class */
  void visitPointer(Pointer *p);
  void visitReference(Reference *p);
  void visitBaseType(BaseType *p);
  void visitBType(BType *p); /* abstract class */
  void visitTQCon(TQCon *p);
  void visitTInt(TInt *p);
  void visitTVoid(TVoid *p);
  void visitTBool(TBool *p);
  void visitTDouble(TDouble *p);
  void visitLiteral(Literal *p); /* abstract class */
  void visitLStringList(LStringList *p);
  void visitLInt(LInt *p);
  void visitLDouble(LDouble *p);
  void visitLChar(LChar *p);
  void visitStringList(StringList *p); /* abstract class */
  void visitLStringListDef(LStringListDef *p);
  void visitLString(LString *p);
  void visitId(Id *p); /* abstract class */
  void visitIdentif(Identif *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitProg(Prog *p);
  void visitDefinition(Definition *p); /* abstract class */
  void visitFunctionDefIn(FunctionDefIn *p);
  void visitFunctionDef(FunctionDef *p);
  void visitFunction(Function *p);
  void visitGlobVar(GlobVar *p);
  void visitGlobStruct(GlobStruct *p);
  void visitGlobTypeDef(GlobTypeDef *p);
  void visitUsingNSDef(UsingNSDef *p);
  void visitUsingDef(UsingDef *p);
  void visitListDefinition(ListDefinition* p);
  void visitArgumentList(ArgumentList *p); /* abstract class */
  void visitArgumentListDef(ArgumentListDef *p);
  void visitListArgument(ListArgument* p);
  void visitArgument(Argument *p); /* abstract class */
  void visitArgumentConstDecl(ArgumentConstDecl *p);
  void visitArgumentDecl(ArgumentDecl *p);
  void visitArgumentConsttype(ArgumentConsttype *p);
  void visitArgumentType(ArgumentType *p);
  void visitBody(Body *p); /* abstract class */
  void visitFuntionBody(FuntionBody *p);
  void visitEmptyBody(EmptyBody *p);
  void visitStm(Stm *p); /* abstract class */
  void visitStmDecl(StmDecl *p);
  void visitStmReturn(StmReturn *p);
  void visitStmExit(StmExit *p);
  void visitStmWhile(StmWhile *p);
  void visitStmDoWhile(StmDoWhile *p);
  void visitStmFor(StmFor *p);
  void visitStmIfElse(StmIfElse *p);
  void visitStmIf(StmIf *p);
  void visitStmBlock(StmBlock *p);
  void visitStmEmptyBlock(StmEmptyBlock *p);
  void visitStmTypeDef(StmTypeDef *p);
  void visitStmeStruct(StmeStruct *p);
  void visitStmExpression(StmExpression *p);
  void visitListStm(ListStm* p);
  void visitStruct(Struct *p); /* abstract class */
  void visitStructDef(StructDef *p);
  void visitTypeDef(TypeDef *p); /* abstract class */
  void visitTypeDefForm(TypeDefForm *p);
  void visitTypeDefForm2(TypeDefForm2 *p);
  void visitDecl(Decl *p); /* abstract class */
  void visitConstDecl(ConstDecl *p);
  void visitDeclaration(Declaration *p);
  void visitVar(Var *p); /* abstract class */
  void visitVariableInitialization(VariableInitialization *p);
  void visitVariableName(VariableName *p);
  void visitListVar(ListVar* p);
  void visitListDecl(ListDecl* p);
  void visitQCon(QCon *p); /* abstract class */
  void visitQualCon(QualCon *p);
  void visitQualConN(QualConN *p);
  void visitName(Name *p); /* abstract class */
  void visitIdName(IdName *p);
  void visitTempInstName(TempInstName *p);
  void visitExp(Exp *p); /* abstract class */
  void visitEIdent(EIdent *p);
  void visitELiteral(ELiteral *p);
  void visitEBracket(EBracket *p);
  void visitEIndex(EIndex *p);
  void visitEQCon(EQCon *p);
  void visitEFunCall(EFunCall *p);
  void visitEStrucProj(EStrucProj *p);
  void visitEStrucPro(EStrucPro *p);
  void visitEInC(EInC *p);
  void visitEDeC(EDeC *p);
  void visitEDeRef(EDeRef *p);
  void visitEInCr(EInCr *p);
  void visitEDeCr(EDeCr *p);
  void visitENeg(ENeg *p);
  void visitEMul(EMul *p);
  void visitEDiv(EDiv *p);
  void visitERem(ERem *p);
  void visitEAdd(EAdd *p);
  void visitESub(ESub *p);
  void visitELSh(ELSh *p);
  void visitERSh(ERSh *p);
  void visitEGT(EGT *p);
  void visitELT(ELT *p);
  void visitEGQ(EGQ *p);
  void visitEGQ1(EGQ1 *p);
  void visitELQ(ELQ *p);
  void visitELQ1(ELQ1 *p);
  void visitEQu(EQu *p);
  void visitEIQ(EIQ *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitEIs(EIs *p);
  void visitEIsP(EIsP *p);
  void visitEIsM(EIsM *p);
  void visitECond(ECond *p);
  void visitEEx(EEx *p);
  void visitListExp(ListExp* p);
  void visitTempInst(TempInst *p); /* abstract class */
  void visitTemplateInst(TemplateInst *p);
  void visitTypeList(TypeList *p); /* abstract class */
  void visitTypeListDef(TypeListDef *p);
  void visitListType(ListType* p);
  void visitType(Type *p); /* abstract class */
  void visitPointer(Pointer *p);
  void visitReference(Reference *p);
  void visitBaseType(BaseType *p);
  void visitBType(BType *p); /* abstract class */
  void visitTQCon(TQCon *p);
  void visitTInt(TInt *p);
  void visitTVoid(TVoid *p);
  void visitTBool(TBool *p);
  void visitTDouble(TDouble *p);
  void visitLiteral(Literal *p); /* abstract class */
  void visitLStringList(LStringList *p);
  void visitLInt(LInt *p);
  void visitLDouble(LDouble *p);
  void visitLChar(LChar *p);
  void visitStringList(StringList *p); /* abstract class */
  void visitLStringListDef(LStringListDef *p);
  void visitLString(LString *p);
  void visitId(Id *p); /* abstract class */
  void visitIdentif(Identif *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};




#endif

