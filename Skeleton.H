#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"


class Skeleton : public Visitor
{
public:
  void visitProg(Prog* p);
  void visitDef(Def* p);
  void visitStm(Stm* p);
  void visitArg(Arg* p);
  void visitExp(Exp* p);
  void visitType(Type* p);
  void visitPDefs(PDefs* p);
  void visitDefinitionFunction(DefinitionFunction* p);
  void visitDefinitionUsing(DefinitionUsing* p);
  void visitDefinitionUsingType(DefinitionUsingType* p);
  void visitDefinitionTypedef(DefinitionTypedef* p);
  void visitDefinitionTypedefExp(DefinitionTypedefExp* p);
  void visitStatementDeclaration(StatementDeclaration* p);
  void visitStatementDeclarations(StatementDeclarations* p);
  void visitStatementInitialization(StatementInitialization* p);
  void visitStatementReturn(StatementReturn* p);
  void visitStatementWhile(StatementWhile* p);
  void visitStatementDo(StatementDo* p);
  void visitStatementFor(StatementFor* p);
  void visitStatementIf(StatementIf* p);
  void visitStatementIfElse(StatementIfElse* p);
  void visitStatementBlock(StatementBlock* p);
  void visitStatementStruct(StatementStruct* p);
  void visitStatementTemplate(StatementTemplate* p);
  void visitStatementTypedef(StatementTypedef* p);
  void visitTemplateInstantiations(TemplateInstantiations* p);
  void visitStatementDefinition(StatementDefinition* p);
  void visitArgumentDefinition(ArgumentDefinition* p);
  void visitEId(EId* p);
  void visitEInteger(EInteger* p);
  void visitEString(EString* p);
  void visitEInde(EInde* p);
  void visitEQCon(EQCon* p);
  void visitEFunC(EFunC* p);
  void visitEStPP(EStPP* p);
  void visitEStPA(EStPA* p);
  void visitEInEP(EInEP* p);
  void visitEDeEM(EDeEM* p);
  void visitEDere(EDere* p);
  void visitEInPE(EInPE* p);
  void visitEDeME(EDeME* p);
  void visitENega(ENega* p);
  void visitEMult(EMult* p);
  void visitEDivi(EDivi* p);
  void visitERema(ERema* p);
  void visitEAddi(EAddi* p);
  void visitESubt(ESubt* p);
  void visitELShi(ELShi* p);
  void visitERShi(ERShi* p);
  void visitECoSm(ECoSm* p);
  void visitECoGr(ECoGr* p);
  void visitECoSE(ECoSE* p);
  void visitECoGE(ECoGE* p);
  void visitEInEq(EInEq* p);
  void visitEEqua(EEqua* p);
  void visitEConj(EConj* p);
  void visitEDisj(EDisj* p);
  void visitEAssi(EAssi* p);
  void visitEAsPl(EAsPl* p);
  void visitEAsMi(EAsMi* p);
  void visitECond(ECond* p);
  void visitEExce(EExce* p);
  void visitTInt(TInt* p);
  void visitTBool(TBool* p);
  void visitTDouble(TDouble* p);
  void visitTVoid(TVoid* p);
  void visitTString(TString* p);
  void visitTStringStd(TStringStd* p);
  void visitTVectorStd(TVectorStd* p);
  void visitListDef(ListDef* p);
  void visitListArg(ListArg* p);
  void visitListStm(ListStm* p);
  void visitListId(ListId* p);
  void visitListType(ListType* p);
  void visitListExp(ListExp* p);

  void visit"Id"("Id" x);
  void visit"Integer"("Integer" x);
  void visit"Char"("Char" x);
  void visit"Double"("Double" x);
  void visit"String"("String" x);
  void visit"Ident"("Ident" x);

};


#endif
