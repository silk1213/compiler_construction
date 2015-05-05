/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"



void Skeleton::visitProgram(Program* t) {} //abstract class
void Skeleton::visitDefinition(Definition* t) {} //abstract class
void Skeleton::visitArgumentList(ArgumentList* t) {} //abstract class
void Skeleton::visitArgument(Argument* t) {} //abstract class
void Skeleton::visitBody(Body* t) {} //abstract class
void Skeleton::visitStm(Stm* t) {} //abstract class
void Skeleton::visitStruct(Struct* t) {} //abstract class
void Skeleton::visitTypeDef(TypeDef* t) {} //abstract class
void Skeleton::visitDecl(Decl* t) {} //abstract class
void Skeleton::visitVar(Var* t) {} //abstract class
void Skeleton::visitQCon(QCon* t) {} //abstract class
void Skeleton::visitName(Name* t) {} //abstract class
void Skeleton::visitExp(Exp* t) {} //abstract class
void Skeleton::visitTempInst(TempInst* t) {} //abstract class
void Skeleton::visitTypeList(TypeList* t) {} //abstract class
void Skeleton::visitType(Type* t) {} //abstract class
void Skeleton::visitBType(BType* t) {} //abstract class
void Skeleton::visitLiteral(Literal* t) {} //abstract class
void Skeleton::visitStringList(StringList* t) {} //abstract class
void Skeleton::visitId(Id* t) {} //abstract class

void Skeleton::visitProg(Prog *prog)
{
  /* Code For Prog Goes Here */

  prog->listdefinition_->accept(this);

}

void Skeleton::visitFunctionDefIn(FunctionDefIn *functiondefin)
{
  /* Code For FunctionDefIn Goes Here */

  functiondefin->type_->accept(this);
  functiondefin->id_->accept(this);
  functiondefin->argumentlist_->accept(this);
  functiondefin->body_->accept(this);

}

void Skeleton::visitFunctionDef(FunctionDef *functiondef)
{
  /* Code For FunctionDef Goes Here */

  functiondef->type_->accept(this);
  functiondef->id_->accept(this);
  functiondef->argumentlist_->accept(this);
  functiondef->body_->accept(this);

}

void Skeleton::visitFunction(Function *function)
{
  /* Code For Function Goes Here */

  function->type_->accept(this);
  function->id_->accept(this);
  function->argumentlist_->accept(this);

}

void Skeleton::visitGlobVar(GlobVar *globvar)
{
  /* Code For GlobVar Goes Here */

  globvar->decl_->accept(this);

}

void Skeleton::visitGlobStruct(GlobStruct *globstruct)
{
  /* Code For GlobStruct Goes Here */

  globstruct->struct_->accept(this);

}

void Skeleton::visitGlobTypeDef(GlobTypeDef *globtypedef)
{
  /* Code For GlobTypeDef Goes Here */

  globtypedef->typedef_->accept(this);

}

void Skeleton::visitUsingNSDef(UsingNSDef *usingnsdef)
{
  /* Code For UsingNSDef Goes Here */

  usingnsdef->id_->accept(this);

}

void Skeleton::visitUsingDef(UsingDef *usingdef)
{
  /* Code For UsingDef Goes Here */

  usingdef->qcon_->accept(this);

}

void Skeleton::visitArgumentListDef(ArgumentListDef *argumentlistdef)
{
  /* Code For ArgumentListDef Goes Here */

  argumentlistdef->listargument_->accept(this);

}

void Skeleton::visitArgumentConstDecl(ArgumentConstDecl *argumentconstdecl)
{
  /* Code For ArgumentConstDecl Goes Here */

  argumentconstdecl->type_->accept(this);
  argumentconstdecl->exp_->accept(this);

}

void Skeleton::visitArgumentDecl(ArgumentDecl *argumentdecl)
{
  /* Code For ArgumentDecl Goes Here */

  argumentdecl->type_->accept(this);
  argumentdecl->exp_->accept(this);

}

void Skeleton::visitArgumentConsttype(ArgumentConsttype *argumentconsttype)
{
  /* Code For ArgumentConsttype Goes Here */

  argumentconsttype->type_->accept(this);

}

void Skeleton::visitArgumentType(ArgumentType *argumenttype)
{
  /* Code For ArgumentType Goes Here */

  argumenttype->type_->accept(this);

}

void Skeleton::visitFuntionBody(FuntionBody *funtionbody)
{
  /* Code For FuntionBody Goes Here */

  funtionbody->liststm_->accept(this);

}

void Skeleton::visitEmptyBody(EmptyBody *emptybody)
{
  /* Code For EmptyBody Goes Here */


}

void Skeleton::visitStmDecl(StmDecl *stmdecl)
{
  /* Code For StmDecl Goes Here */

  stmdecl->decl_->accept(this);

}

void Skeleton::visitStmReturn(StmReturn *stmreturn)
{
  /* Code For StmReturn Goes Here */

  stmreturn->exp_->accept(this);

}

void Skeleton::visitStmExit(StmExit *stmexit)
{
  /* Code For StmExit Goes Here */

  stmexit->exp_->accept(this);

}

void Skeleton::visitStmWhile(StmWhile *stmwhile)
{
  /* Code For StmWhile Goes Here */

  stmwhile->exp_->accept(this);
  stmwhile->stm_->accept(this);

}

void Skeleton::visitStmDoWhile(StmDoWhile *stmdowhile)
{
  /* Code For StmDoWhile Goes Here */

  stmdowhile->stm_->accept(this);
  stmdowhile->exp_->accept(this);

}

void Skeleton::visitStmFor(StmFor *stmfor)
{
  /* Code For StmFor Goes Here */

  stmfor->decl_->accept(this);
  stmfor->exp_1->accept(this);
  stmfor->exp_2->accept(this);
  stmfor->stm_->accept(this);

}

void Skeleton::visitStmIfElse(StmIfElse *stmifelse)
{
  /* Code For StmIfElse Goes Here */

  stmifelse->exp_->accept(this);
  stmifelse->stm_1->accept(this);
  stmifelse->stm_2->accept(this);

}

void Skeleton::visitStmIf(StmIf *stmif)
{
  /* Code For StmIf Goes Here */

  stmif->exp_->accept(this);
  stmif->stm_->accept(this);

}

void Skeleton::visitStmBlock(StmBlock *stmblock)
{
  /* Code For StmBlock Goes Here */

  stmblock->liststm_->accept(this);

}

void Skeleton::visitStmEmptyBlock(StmEmptyBlock *stmemptyblock)
{
  /* Code For StmEmptyBlock Goes Here */


}

void Skeleton::visitStmTypeDef(StmTypeDef *stmtypedef)
{
  /* Code For StmTypeDef Goes Here */

  stmtypedef->typedef_->accept(this);

}

void Skeleton::visitStmeStruct(StmeStruct *stmestruct)
{
  /* Code For StmeStruct Goes Here */

  stmestruct->struct_->accept(this);

}

void Skeleton::visitStmExpression(StmExpression *stmexpression)
{
  /* Code For StmExpression Goes Here */

  stmexpression->exp_->accept(this);

}

void Skeleton::visitStructDef(StructDef *structdef)
{
  /* Code For StructDef Goes Here */

  structdef->id_->accept(this);
  structdef->listdecl_->accept(this);

}

void Skeleton::visitTypeDefForm(TypeDefForm *typedefform)
{
  /* Code For TypeDefForm Goes Here */

  typedefform->type_->accept(this);
  typedefform->id_->accept(this);

}

void Skeleton::visitTypeDefForm2(TypeDefForm2 *typedefform2)
{
  /* Code For TypeDefForm2 Goes Here */

  typedefform2->type_->accept(this);

}

void Skeleton::visitConstDecl(ConstDecl *constdecl)
{
  /* Code For ConstDecl Goes Here */

  constdecl->type_->accept(this);
  constdecl->listvar_->accept(this);

}

void Skeleton::visitDeclaration(Declaration *declaration)
{
  /* Code For Declaration Goes Here */

  declaration->type_->accept(this);
  declaration->listvar_->accept(this);

}

void Skeleton::visitVariableInitialization(VariableInitialization *variableinitialization)
{
  /* Code For VariableInitialization Goes Here */

  variableinitialization->id_->accept(this);
  variableinitialization->exp_->accept(this);

}

void Skeleton::visitVariableName(VariableName *variablename)
{
  /* Code For VariableName Goes Here */

  variablename->id_->accept(this);

}

void Skeleton::visitQualCon(QualCon *qualcon)
{
  /* Code For QualCon Goes Here */

  qualcon->qcon_->accept(this);
  qualcon->name_->accept(this);

}

void Skeleton::visitQualConN(QualConN *qualconn)
{
  /* Code For QualConN Goes Here */

  qualconn->name_->accept(this);

}

void Skeleton::visitIdName(IdName *idname)
{
  /* Code For IdName Goes Here */

  idname->id_->accept(this);

}

void Skeleton::visitTempInstName(TempInstName *tempinstname)
{
  /* Code For TempInstName Goes Here */

  tempinstname->tempinst_->accept(this);

}

void Skeleton::visitEIdent(EIdent *eident)
{
  /* Code For EIdent Goes Here */

  eident->id_->accept(this);

}

void Skeleton::visitELiteral(ELiteral *eliteral)
{
  /* Code For ELiteral Goes Here */

  eliteral->literal_->accept(this);

}

void Skeleton::visitEBracket(EBracket *ebracket)
{
  /* Code For EBracket Goes Here */

  ebracket->exp_->accept(this);

}

void Skeleton::visitEIndex(EIndex *eindex)
{
  /* Code For EIndex Goes Here */

  eindex->exp_1->accept(this);
  eindex->exp_2->accept(this);

}

void Skeleton::visitEQCon(EQCon *eqcon)
{
  /* Code For EQCon Goes Here */

  eqcon->qcon_->accept(this);

}

void Skeleton::visitEFunCall(EFunCall *efuncall)
{
  /* Code For EFunCall Goes Here */

  efuncall->exp_->accept(this);
  efuncall->listexp_->accept(this);

}

void Skeleton::visitEStrucProj(EStrucProj *estrucproj)
{
  /* Code For EStrucProj Goes Here */

  estrucproj->exp_1->accept(this);
  estrucproj->exp_2->accept(this);

}

void Skeleton::visitEStrucPro(EStrucPro *estrucpro)
{
  /* Code For EStrucPro Goes Here */

  estrucpro->exp_1->accept(this);
  estrucpro->exp_2->accept(this);

}

void Skeleton::visitEInC(EInC *einc)
{
  /* Code For EInC Goes Here */

  einc->exp_->accept(this);

}

void Skeleton::visitEDeC(EDeC *edec)
{
  /* Code For EDeC Goes Here */

  edec->exp_->accept(this);

}

void Skeleton::visitEDeRef(EDeRef *ederef)
{
  /* Code For EDeRef Goes Here */

  ederef->exp_->accept(this);

}

void Skeleton::visitEInCr(EInCr *eincr)
{
  /* Code For EInCr Goes Here */

  eincr->exp_->accept(this);

}

void Skeleton::visitEDeCr(EDeCr *edecr)
{
  /* Code For EDeCr Goes Here */

  edecr->exp_->accept(this);

}

void Skeleton::visitENeg(ENeg *eneg)
{
  /* Code For ENeg Goes Here */

  eneg->exp_->accept(this);

}

void Skeleton::visitEMul(EMul *emul)
{
  /* Code For EMul Goes Here */

  emul->exp_1->accept(this);
  emul->exp_2->accept(this);

}

void Skeleton::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */

  ediv->exp_1->accept(this);
  ediv->exp_2->accept(this);

}

void Skeleton::visitERem(ERem *erem)
{
  /* Code For ERem Goes Here */

  erem->exp_1->accept(this);
  erem->exp_2->accept(this);

}

void Skeleton::visitEAdd(EAdd *eadd)
{
  /* Code For EAdd Goes Here */

  eadd->exp_1->accept(this);
  eadd->exp_2->accept(this);

}

void Skeleton::visitESub(ESub *esub)
{
  /* Code For ESub Goes Here */

  esub->exp_1->accept(this);
  esub->exp_2->accept(this);

}

void Skeleton::visitELSh(ELSh *elsh)
{
  /* Code For ELSh Goes Here */

  elsh->exp_1->accept(this);
  elsh->exp_2->accept(this);

}

void Skeleton::visitERSh(ERSh *ersh)
{
  /* Code For ERSh Goes Here */

  ersh->exp_1->accept(this);
  ersh->exp_2->accept(this);

}

void Skeleton::visitEGT(EGT *egt)
{
  /* Code For EGT Goes Here */

  egt->exp_1->accept(this);
  egt->exp_2->accept(this);

}

void Skeleton::visitELT(ELT *elt)
{
  /* Code For ELT Goes Here */

  elt->exp_1->accept(this);
  elt->exp_2->accept(this);

}

void Skeleton::visitEGQ(EGQ *egq)
{
  /* Code For EGQ Goes Here */

  egq->exp_1->accept(this);
  egq->exp_2->accept(this);

}

void Skeleton::visitEGQ1(EGQ1 *egq1)
{
  /* Code For EGQ1 Goes Here */

  egq1->exp_1->accept(this);
  egq1->exp_2->accept(this);

}

void Skeleton::visitELQ(ELQ *elq)
{
  /* Code For ELQ Goes Here */

  elq->exp_1->accept(this);
  elq->exp_2->accept(this);

}

void Skeleton::visitELQ1(ELQ1 *elq1)
{
  /* Code For ELQ1 Goes Here */

  elq1->exp_1->accept(this);
  elq1->exp_2->accept(this);

}

void Skeleton::visitEQu(EQu *equ)
{
  /* Code For EQu Goes Here */

  equ->exp_1->accept(this);
  equ->exp_2->accept(this);

}

void Skeleton::visitEIQ(EIQ *eiq)
{
  /* Code For EIQ Goes Here */

  eiq->exp_1->accept(this);
  eiq->exp_2->accept(this);

}

void Skeleton::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */

  eand->exp_1->accept(this);
  eand->exp_2->accept(this);

}

void Skeleton::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */

  eor->exp_1->accept(this);
  eor->exp_2->accept(this);

}

void Skeleton::visitEIs(EIs *eis)
{
  /* Code For EIs Goes Here */

  eis->exp_1->accept(this);
  eis->exp_2->accept(this);

}

void Skeleton::visitEIsP(EIsP *eisp)
{
  /* Code For EIsP Goes Here */

  eisp->exp_1->accept(this);
  eisp->exp_2->accept(this);

}

void Skeleton::visitEIsM(EIsM *eism)
{
  /* Code For EIsM Goes Here */

  eism->exp_1->accept(this);
  eism->exp_2->accept(this);

}

void Skeleton::visitECond(ECond *econd)
{
  /* Code For ECond Goes Here */

  econd->exp_1->accept(this);
  econd->exp_2->accept(this);
  econd->exp_3->accept(this);

}

void Skeleton::visitEEx(EEx *eex)
{
  /* Code For EEx Goes Here */

  eex->exp_->accept(this);

}

void Skeleton::visitTemplateInst(TemplateInst *templateinst)
{
  /* Code For TemplateInst Goes Here */

  templateinst->id_->accept(this);
  templateinst->typelist_->accept(this);

}

void Skeleton::visitTypeListDef(TypeListDef *typelistdef)
{
  /* Code For TypeListDef Goes Here */

  typelistdef->listtype_->accept(this);

}

void Skeleton::visitPointer(Pointer *pointer)
{
  /* Code For Pointer Goes Here */

  pointer->btype_->accept(this);

}

void Skeleton::visitReference(Reference *reference)
{
  /* Code For Reference Goes Here */

  reference->btype_->accept(this);

}

void Skeleton::visitBaseType(BaseType *basetype)
{
  /* Code For BaseType Goes Here */

  basetype->btype_->accept(this);

}

void Skeleton::visitTQCon(TQCon *tqcon)
{
  /* Code For TQCon Goes Here */

  tqcon->qcon_->accept(this);

}

void Skeleton::visitTInt(TInt *tint)
{
  /* Code For TInt Goes Here */


}

void Skeleton::visitTVoid(TVoid *tvoid)
{
  /* Code For TVoid Goes Here */


}

void Skeleton::visitTBool(TBool *tbool)
{
  /* Code For TBool Goes Here */


}

void Skeleton::visitTDouble(TDouble *tdouble)
{
  /* Code For TDouble Goes Here */


}

void Skeleton::visitLStringList(LStringList *lstringlist)
{
  /* Code For LStringList Goes Here */

  lstringlist->stringlist_->accept(this);

}

void Skeleton::visitLInt(LInt *lint)
{
  /* Code For LInt Goes Here */

  visitInteger(lint->integer_);

}

void Skeleton::visitLDouble(LDouble *ldouble)
{
  /* Code For LDouble Goes Here */

  visitDouble(ldouble->double_);

}

void Skeleton::visitLChar(LChar *lchar)
{
  /* Code For LChar Goes Here */

  visitChar(lchar->char_);

}

void Skeleton::visitLStringListDef(LStringListDef *lstringlistdef)
{
  /* Code For LStringListDef Goes Here */

  lstringlistdef->stringlist_->accept(this);
  visitString(lstringlistdef->string_);

}

void Skeleton::visitLString(LString *lstring)
{
  /* Code For LString Goes Here */

  visitString(lstring->string_);

}

void Skeleton::visitIdentif(Identif *identif)
{
  /* Code For Identif Goes Here */

  visitIdent(identif->ident_);

}


void Skeleton::visitListDefinition(ListDefinition* listdefinition)
{
  for (ListDefinition::iterator i = listdefinition->begin() ; i != listdefinition->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListArgument(ListArgument* listargument)
{
  for (ListArgument::iterator i = listargument->begin() ; i != listargument->end() ; ++i)
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

void Skeleton::visitListVar(ListVar* listvar)
{
  for (ListVar::iterator i = listvar->begin() ; i != listvar->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListDecl(ListDecl* listdecl)
{
  for (ListDecl::iterator i = listdecl->begin() ; i != listdecl->end() ; ++i)
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

void Skeleton::visitListType(ListType* listtype)
{
  for (ListType::iterator i = listtype->begin() ; i != listtype->end() ; ++i)
  {
    (*i)->accept(this);
  }
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



