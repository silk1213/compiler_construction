/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"



void Skeleton::visitDef(Def* t) {} //abstract class
void Skeleton::visitStm(Stm* t) {} //abstract class
void Skeleton::visitArg(Arg* t) {} //abstract class
void Skeleton::visitExp(Exp* t) {} //abstract class
void Skeleton::visitType(Type* t) {} //abstract class

void Skeleton::visitPDefs(PDefs *pdefs)
{
  /* Code For PDefs Goes Here */

  pdefs->listdef_->accept(this);

}

void Skeleton::visitDefinitionFunction(DefinitionFunction *definitionfunction)
{
  /* Code For DefinitionFunction Goes Here */

  definitionfunction->type_->accept(this);
  visitId(definitionfunction->id_);
  definitionfunction->listarg_->accept(this);
  definitionfunction->liststm_->accept(this);

}

void Skeleton::visitDefinitionUsing(DefinitionUsing *definitionusing)
{
  /* Code For DefinitionUsing Goes Here */

  definitionusing->exp_->accept(this);

}

void Skeleton::visitDefinitionTypeDef(DefinitionTypeDef *definitiontypedef)
{
  /* Code For DefinitionTypeDef Goes Here */

  visitId(definitiontypedef->id_);
  definitiontypedef->type_->accept(this);
  definitiontypedef->exp_->accept(this);

}

void Skeleton::visitStatementDeclaration(StatementDeclaration *statementdeclaration)
{
  /* Code For StatementDeclaration Goes Here */

  statementdeclaration->type_->accept(this);
  visitId(statementdeclaration->id_);

}

void Skeleton::visitStatementDeclarations(StatementDeclarations *statementdeclarations)
{
  /* Code For StatementDeclarations Goes Here */

  statementdeclarations->type_->accept(this);
  visitId(statementdeclarations->id_);
  statementdeclarations->listid_->accept(this);

}

void Skeleton::visitStatementInitialization(StatementInitialization *statementinitialization)
{
  /* Code For StatementInitialization Goes Here */

  statementinitialization->type_->accept(this);
  visitId(statementinitialization->id_);
  statementinitialization->exp_->accept(this);

}

void Skeleton::visitStatementReturn(StatementReturn *statementreturn)
{
  /* Code For StatementReturn Goes Here */

  statementreturn->exp_->accept(this);

}

void Skeleton::visitStatementWhile(StatementWhile *statementwhile)
{
  /* Code For StatementWhile Goes Here */

  statementwhile->exp_->accept(this);
  statementwhile->stm_->accept(this);

}

void Skeleton::visitStatementDo(StatementDo *statementdo)
{
  /* Code For StatementDo Goes Here */

  statementdo->stm_->accept(this);
  statementdo->exp_->accept(this);

}

void Skeleton::visitStatementFor(StatementFor *statementfor)
{
  /* Code For StatementFor Goes Here */

  statementfor->type_->accept(this);
  visitId(statementfor->id_);
  statementfor->exp_1->accept(this);
  statementfor->exp_2->accept(this);
  statementfor->stm_1->accept(this);
  statementfor->stm_2->accept(this);

}

void Skeleton::visitStatementIf(StatementIf *statementif)
{
  /* Code For StatementIf Goes Here */

  statementif->exp_->accept(this);
  statementif->stm_->accept(this);

}

void Skeleton::visitStatementIfElse(StatementIfElse *statementifelse)
{
  /* Code For StatementIfElse Goes Here */

  statementifelse->exp_->accept(this);
  statementifelse->stm_1->accept(this);
  statementifelse->stm_2->accept(this);

}

void Skeleton::visitStatementBlock(StatementBlock *statementblock)
{
  /* Code For StatementBlock Goes Here */

  statementblock->liststm_->accept(this);

}

void Skeleton::visitStatementStruct(StatementStruct *statementstruct)
{
  /* Code For StatementStruct Goes Here */

  visitId(statementstruct->id_);
  statementstruct->liststm_->accept(this);

}

void Skeleton::visitStatementTemplate(StatementTemplate *statementtemplate)
{
  /* Code For StatementTemplate Goes Here */

  visitId(statementtemplate->id_);
  statementtemplate->type_->accept(this);
  statementtemplate->exp_->accept(this);

}

void Skeleton::visitTemplateInstantiations(TemplateInstantiations *templateinstantiations)
{
  /* Code For TemplateInstantiations Goes Here */

  templateinstantiations->listtype_->accept(this);

}

void Skeleton::visitStatementDefinition(StatementDefinition *statementdefinition)
{
  /* Code For StatementDefinition Goes Here */

  statementdefinition->exp_->accept(this);

}

void Skeleton::visitArgumentDefinition(ArgumentDefinition *argumentdefinition)
{
  /* Code For ArgumentDefinition Goes Here */

  argumentdefinition->exp_->accept(this);

}

void Skeleton::visitTInt(TInt *tint)
{
  /* Code For TInt Goes Here */


}

void Skeleton::visitTBool(TBool *tbool)
{
  /* Code For TBool Goes Here */


}

void Skeleton::visitTDouble(TDouble *tdouble)
{
  /* Code For TDouble Goes Here */


}

void Skeleton::visitTVoid(TVoid *tvoid)
{
  /* Code For TVoid Goes Here */


}

void Skeleton::visitTString(TString *tstring)
{
  /* Code For TString Goes Here */


}

void Skeleton::visitTStringStd(TStringStd *tstringstd)
{
  /* Code For TStringStd Goes Here */


}

void Skeleton::visitTVectorStd(TVectorStd *tvectorstd)
{
  /* Code For TVectorStd Goes Here */


}

void Skeleton::visitEId(EId *eid)
{
  /* Code For EId Goes Here */

  visitId(eid->id_);

}

void Skeleton::visitEInteger(EInteger *einteger)
{
  /* Code For EInteger Goes Here */

  visitInteger(einteger->integer_);

}

void Skeleton::visitEString(EString *estring)
{
  /* Code For EString Goes Here */

  visitString(estring->string_);

}

void Skeleton::visitEInde(EInde *einde)
{
  /* Code For EInde Goes Here */

  einde->exp_->accept(this);
  visitId(einde->id_);

}

void Skeleton::visitEQCon(EQCon *eqcon)
{
  /* Code For EQCon Goes Here */

  eqcon->exp_->accept(this);
  visitId(eqcon->id_);

}

void Skeleton::visitEFunC(EFunC *efunc)
{
  /* Code For EFunC Goes Here */

  efunc->exp_->accept(this);
  efunc->listexp_->accept(this);

}

void Skeleton::visitEStPP(EStPP *estpp)
{
  /* Code For EStPP Goes Here */

  estpp->exp_1->accept(this);
  estpp->exp_2->accept(this);

}

void Skeleton::visitEStPA(EStPA *estpa)
{
  /* Code For EStPA Goes Here */

  estpa->exp_1->accept(this);
  estpa->exp_2->accept(this);

}

void Skeleton::visitEInEP(EInEP *einep)
{
  /* Code For EInEP Goes Here */

  einep->exp_->accept(this);

}

void Skeleton::visitEDeEM(EDeEM *edeem)
{
  /* Code For EDeEM Goes Here */

  edeem->exp_->accept(this);

}

void Skeleton::visitEDere(EDere *edere)
{
  /* Code For EDere Goes Here */

  edere->exp_->accept(this);

}

void Skeleton::visitEInPE(EInPE *einpe)
{
  /* Code For EInPE Goes Here */

  einpe->exp_->accept(this);

}

void Skeleton::visitEDeME(EDeME *edeme)
{
  /* Code For EDeME Goes Here */

  edeme->exp_->accept(this);

}

void Skeleton::visitENega(ENega *enega)
{
  /* Code For ENega Goes Here */

  enega->exp_->accept(this);

}

void Skeleton::visitEMult(EMult *emult)
{
  /* Code For EMult Goes Here */

  emult->exp_1->accept(this);
  emult->exp_2->accept(this);

}

void Skeleton::visitEDivi(EDivi *edivi)
{
  /* Code For EDivi Goes Here */

  edivi->exp_1->accept(this);
  edivi->exp_2->accept(this);

}

void Skeleton::visitERema(ERema *erema)
{
  /* Code For ERema Goes Here */

  erema->exp_1->accept(this);
  erema->exp_2->accept(this);

}

void Skeleton::visitEAddi(EAddi *eaddi)
{
  /* Code For EAddi Goes Here */

  eaddi->exp_1->accept(this);
  eaddi->exp_2->accept(this);

}

void Skeleton::visitESubt(ESubt *esubt)
{
  /* Code For ESubt Goes Here */

  esubt->exp_1->accept(this);
  esubt->exp_2->accept(this);

}

void Skeleton::visitELShi(ELShi *elshi)
{
  /* Code For ELShi Goes Here */

  elshi->exp_1->accept(this);
  elshi->exp_2->accept(this);

}

void Skeleton::visitERShi(ERShi *ershi)
{
  /* Code For ERShi Goes Here */

  ershi->exp_1->accept(this);
  ershi->exp_2->accept(this);

}

void Skeleton::visitECoSm(ECoSm *ecosm)
{
  /* Code For ECoSm Goes Here */

  ecosm->exp_1->accept(this);
  ecosm->exp_2->accept(this);

}

void Skeleton::visitECoGr(ECoGr *ecogr)
{
  /* Code For ECoGr Goes Here */

  ecogr->exp_1->accept(this);
  ecogr->exp_2->accept(this);

}

void Skeleton::visitECoSE(ECoSE *ecose)
{
  /* Code For ECoSE Goes Here */

  ecose->exp_1->accept(this);
  ecose->exp_2->accept(this);

}

void Skeleton::visitECoGE(ECoGE *ecoge)
{
  /* Code For ECoGE Goes Here */

  ecoge->exp_1->accept(this);
  ecoge->exp_2->accept(this);

}

void Skeleton::visitEInEq(EInEq *eineq)
{
  /* Code For EInEq Goes Here */

  eineq->exp_1->accept(this);
  eineq->exp_2->accept(this);

}

void Skeleton::visitEEqua(EEqua *eequa)
{
  /* Code For EEqua Goes Here */

  eequa->exp_1->accept(this);
  eequa->exp_2->accept(this);

}

void Skeleton::visitEConj(EConj *econj)
{
  /* Code For EConj Goes Here */

  econj->exp_1->accept(this);
  econj->exp_2->accept(this);

}

void Skeleton::visitEDisj(EDisj *edisj)
{
  /* Code For EDisj Goes Here */

  edisj->exp_1->accept(this);
  edisj->exp_2->accept(this);

}

void Skeleton::visitEAssi(EAssi *eassi)
{
  /* Code For EAssi Goes Here */

  eassi->exp_1->accept(this);
  eassi->exp_2->accept(this);

}

void Skeleton::visitEAsPl(EAsPl *easpl)
{
  /* Code For EAsPl Goes Here */

  easpl->exp_1->accept(this);
  easpl->exp_2->accept(this);

}

void Skeleton::visitEAsMi(EAsMi *easmi)
{
  /* Code For EAsMi Goes Here */

  easmi->exp_1->accept(this);
  easmi->exp_2->accept(this);

}

void Skeleton::visitECond(ECond *econd)
{
  /* Code For ECond Goes Here */

  econd->exp_1->accept(this);
  econd->exp_2->accept(this);
  econd->exp_3->accept(this);

}

void Skeleton::visitEExce(EExce *eexce)
{
  /* Code For EExce Goes Here */

  eexce->exp_->accept(this);

}


void Skeleton::visitListDef(ListDef* listdef)
{
  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListArg(ListArg* listarg)
{
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStm(ListStm* liststm)
{
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListId(ListId* listid)
{
  for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
  {
    visitId(*i) ;
  }
}

void Skeleton::visitListType(ListType* listtype)
{
  for (ListType::iterator i = listtype->begin() ; i != listtype->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListExp(ListExp* listexp)
{
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void Skeleton::visitId(Id x)
{
  /* Code for Id Goes Here */
}

void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



