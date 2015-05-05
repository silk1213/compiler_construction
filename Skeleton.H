#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"


class Skeleton : public Visitor
{
public:
  void visitProgram(Program* p);
  void visitDefinition(Definition* p);
  void visitArgumentList(ArgumentList* p);
  void visitArgument(Argument* p);
  void visitBody(Body* p);
  void visitStm(Stm* p);
  void visitStruct(Struct* p);
  void visitTypeDef(TypeDef* p);
  void visitDecl(Decl* p);
  void visitVar(Var* p);
  void visitQCon(QCon* p);
  void visitName(Name* p);
  void visitExp(Exp* p);
  void visitTempInst(TempInst* p);
  void visitTypeList(TypeList* p);
  void visitType(Type* p);
  void visitBType(BType* p);
  void visitLiteral(Literal* p);
  void visitStringList(StringList* p);
  void visitId(Id* p);
  void visitProg(Prog* p);
  void visitFunctionDefIn(FunctionDefIn* p);
  void visitFunctionDef(FunctionDef* p);
  void visitFunction(Function* p);
  void visitGlobVar(GlobVar* p);
  void visitGlobStruct(GlobStruct* p);
  void visitGlobTypeDef(GlobTypeDef* p);
  void visitUsingNSDef(UsingNSDef* p);
  void visitUsingDef(UsingDef* p);
  void visitArgumentListDef(ArgumentListDef* p);
  void visitArgumentConstDecl(ArgumentConstDecl* p);
  void visitArgumentDecl(ArgumentDecl* p);
  void visitArgumentConsttype(ArgumentConsttype* p);
  void visitArgumentType(ArgumentType* p);
  void visitFuntionBody(FuntionBody* p);
  void visitEmptyBody(EmptyBody* p);
  void visitStmDecl(StmDecl* p);
  void visitStmReturn(StmReturn* p);
  void visitStmExit(StmExit* p);
  void visitStmWhile(StmWhile* p);
  void visitStmDoWhile(StmDoWhile* p);
  void visitStmFor(StmFor* p);
  void visitStmIfElse(StmIfElse* p);
  void visitStmIf(StmIf* p);
  void visitStmBlock(StmBlock* p);
  void visitStmEmptyBlock(StmEmptyBlock* p);
  void visitStmTypeDef(StmTypeDef* p);
  void visitStmeStruct(StmeStruct* p);
  void visitStmExpression(StmExpression* p);
  void visitStructDef(StructDef* p);
  void visitTypeDefForm(TypeDefForm* p);
  void visitTypeDefForm2(TypeDefForm2* p);
  void visitConstDecl(ConstDecl* p);
  void visitDeclaration(Declaration* p);
  void visitVariableInitialization(VariableInitialization* p);
  void visitVariableName(VariableName* p);
  void visitQualCon(QualCon* p);
  void visitQualConN(QualConN* p);
  void visitIdName(IdName* p);
  void visitTempInstName(TempInstName* p);
  void visitEIdent(EIdent* p);
  void visitELiteral(ELiteral* p);
  void visitEBracket(EBracket* p);
  void visitEIndex(EIndex* p);
  void visitEQCon(EQCon* p);
  void visitEFunCall(EFunCall* p);
  void visitEStrucProj(EStrucProj* p);
  void visitEStrucPro(EStrucPro* p);
  void visitEInC(EInC* p);
  void visitEDeC(EDeC* p);
  void visitEDeRef(EDeRef* p);
  void visitEInCr(EInCr* p);
  void visitEDeCr(EDeCr* p);
  void visitENeg(ENeg* p);
  void visitEMul(EMul* p);
  void visitEDiv(EDiv* p);
  void visitERem(ERem* p);
  void visitEAdd(EAdd* p);
  void visitESub(ESub* p);
  void visitELSh(ELSh* p);
  void visitERSh(ERSh* p);
  void visitEGT(EGT* p);
  void visitELT(ELT* p);
  void visitEGQ(EGQ* p);
  void visitEGQ1(EGQ1* p);
  void visitELQ(ELQ* p);
  void visitELQ1(ELQ1* p);
  void visitEQu(EQu* p);
  void visitEIQ(EIQ* p);
  void visitEAnd(EAnd* p);
  void visitEOr(EOr* p);
  void visitEIs(EIs* p);
  void visitEIsP(EIsP* p);
  void visitEIsM(EIsM* p);
  void visitECond(ECond* p);
  void visitEEx(EEx* p);
  void visitTemplateInst(TemplateInst* p);
  void visitTypeListDef(TypeListDef* p);
  void visitPointer(Pointer* p);
  void visitReference(Reference* p);
  void visitBaseType(BaseType* p);
  void visitTQCon(TQCon* p);
  void visitTInt(TInt* p);
  void visitTVoid(TVoid* p);
  void visitTBool(TBool* p);
  void visitTDouble(TDouble* p);
  void visitLStringList(LStringList* p);
  void visitLInt(LInt* p);
  void visitLDouble(LDouble* p);
  void visitLChar(LChar* p);
  void visitLStringListDef(LStringListDef* p);
  void visitLString(LString* p);
  void visitIdentif(Identif* p);
  void visitListDefinition(ListDefinition* p);
  void visitListArgument(ListArgument* p);
  void visitListStm(ListStm* p);
  void visitListVar(ListVar* p);
  void visitListDecl(ListDecl* p);
  void visitListExp(ListExp* p);
  void visitListType(ListType* p);

  void visit"Integer"("Integer" x);
  void visit"Char"("Char" x);
  void visit"Double"("Double" x);
  void visit"String"("String" x);
  void visit"Ident"("Ident" x);

};


#endif
