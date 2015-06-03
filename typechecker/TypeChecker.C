#include "TypeChecker.H"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

TypeChecker::TypeChecker() {
	env_ = new Env();
}

TypeChecker::~TypeChecker() {
	delete env_;
}

Type* TypeChecker::typecheck (Visitable* v) {
	v->accept (this);
	return ty_;
}

void TypeChecker::visitProgram(Program* t) {} //abstract class
void TypeChecker::visitDef(Def* t) {} //abstract class
void TypeChecker::visitArg(Arg* t) {} //abstract class
void TypeChecker::visitStm(Stm* t) {} //abstract class
void TypeChecker::visitExp(Exp* t) {} //abstract class
void TypeChecker::visitType(Type* t) {} //abstract class

void TypeChecker::visitPDefs(PDefs *pdefs)
{
  /* Code For PDefs Goes Here */
  //printf("visitPDefs\n");

	for(ListDef::iterator i = pdefs->listdef_->begin(); i != pdefs->listdef_->end(); i++) {
		env_->updateFun((*i)->getId(), (*i)->getArg(), (*i)->getType());
  	}

  	pdefs->listdef_->accept(this);

	printf("OK");

}

void TypeChecker::visitDFun(DFun *dfun)
{
  /* Code For DFun Goes Here */
  printf("visitDFun\n");

  dfun->type_->accept(this);

  visitId(dfun->id_);

	latestFunc = dfun->id_;
  dfun->listarg_->accept(this);
  env_->addEnv();
	ListArg::iterator it;
				for (it = dfun->listarg_->begin(); it != dfun->listarg_->end(); ++it) {
					env_->updateVar((*it)->getId(), (*it)->getType());				
				}

  dfun->liststm_->accept(this);
  env_->deleteEnv();
	printf("finished funct\n");
}

void TypeChecker::visitADecl(ADecl *adecl)
{
  /* Code For ADecl Goes Here */
  //printf("visitADecl\n");

  adecl->type_->accept(this);
  visitId(adecl->id_);

}

void TypeChecker::visitSExp(SExp *sexp)
{
  /* Code For SExp Goes Here */
  //printf("visitSExp\n");

  sexp->exp_->accept(this);

}

void TypeChecker::visitSDecls(SDecls *sdecls)
{
  /* Code For SDecls Goes Here */
  //printf("visitSDecls\n");

  sdecls->type_->accept(this);
  sdecls->listid_->accept(this);

  for(ListId::iterator i = sdecls->listid_->begin(); i != sdecls->listid_->end(); i++) {
  	if (env_->lookuplatest(*i) != NULL) {
			printf("TYPE ERROR");
			exit(1);
		}

		env_->updateVar(*i,sdecls->type_);
  }
}

void TypeChecker::visitSInit(SInit *sinit)
{
  /* Code For SInit Goes Here */
  //printf("visitSInit\n");

  sinit->type_->accept(this);
  visitId(sinit->id_);

	if (env_->lookuplatest(sinit->id_) != NULL) {
			printf("TYPE ERROR");
			exit(1);
		}

  sinit->exp_->accept(this);

	if (sinit->type_->getType() != sinit->exp_->type) {
		printf("TYPE ERROR");
		exit(1);
	}

	env_->updateVar(sinit->id_, sinit->type_);
}

void TypeChecker::visitSReturn(SReturn *sreturn)
{
  /* Code For SReturn Goes Here */
  //printf("visitSReturn\n");

  sreturn->exp_->accept(this);
  if(env_->lookupFun(latestFunc).second->getType() != sreturn->exp_->type) {
		printf("TYPE ERROR");
		exit(1);
	}
}

void TypeChecker::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
  /* Code For SReturnVoid Goes Here */
  //printf("visitSReturnVoid\n");


}

void TypeChecker::visitSWhile(SWhile *swhile)
{
  /* Code For SWhile Goes Here */
  //printf("visitSWhile\n");

  swhile->exp_->accept(this);

	if (swhile->exp_->type != "bool") {
		printf("TYPE ERROR");
		exit(1);
	}

  swhile->stm_->accept(this);

}

void TypeChecker::visitSBlock(SBlock *sblock)
{
  /* Code For SBlock Goes Here */
  //printf("visitSBlock\n");

  env_->addEnv();

  sblock->liststm_->accept(this);

  env_->deleteEnv();
}

void TypeChecker::visitSIfElse(SIfElse *sifelse)
{
  /* Code For SIfElse Goes Here */
  //printf("visitSIfElse\n");

  sifelse->exp_->accept(this);

	if (sifelse->exp_->type != "bool") {
		printf("TYPE ERROR");
		exit(1);
	}

  sifelse->stm_1->accept(this);
  sifelse->stm_2->accept(this);

}

void TypeChecker::visitETrue(ETrue *etrue)
{
  /* Code For ETrue Goes Here */
  //printf("visitETrue\n");

	etrue->type = "bool";

}

void TypeChecker::visitEFalse(EFalse *efalse)
{
  /* Code For EFalse Goes Here */
  //printf("visitEFalse\n");

	efalse->type = "bool";


}

void TypeChecker::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */
  //printf("visitEInt\n");

  visitInteger(eint->integer_);

	eint->type = "int";

}

void TypeChecker::visitEDouble(EDouble *edouble)
{
  /* Code For EDouble Goes Here */
  //printf("visitEDouble\n");

  visitDouble(edouble->double_);
	
	edouble->type = "double";

}

void TypeChecker::visitEString(EString *estring)
{
  /* Code For EString Goes Here */
  //printf("visitEString\n");

  visitString(estring->string_);

	estring->type = "string";

}

void TypeChecker::visitEId(EId *eid)
{
  /* Code For EId Goes Here */
  //printf("visitEId\n");

  visitId(eid->id_);
	
	eid->type = env_->lookupVariable(eid->id_);

	if(eid->type == "") {
		printf("TYPE ERROR");
		exit(1);
	}
}

void TypeChecker::visitEApp(EApp *eapp)
{
  /* Code For EApp Goes Here */
  //printf("visitEApp\n");

  visitId(eapp->id_);
  eapp->listexp_->accept(this);
 
  std::pair<ListArg*,Type*> func = env_->lookupFun (eapp->id_);
	ListArg* inputTypes = func.first;
	Type* outputType = func.second;
	ListArg::iterator it;
	ListExp::iterator it_exp;

	if (eapp->listexp_->size() != inputTypes->size()) {
		printf("TYPE ERROR");
		exit(1);
	}

	for (it = inputTypes->begin(), it_exp = eapp->listexp_->begin(); it != inputTypes->end(); ++it, ++it_exp) {
		if ((*it)->getType()->getType() != (*it_exp)->type) {
			printf("TYPE ERROR");
			exit(1);
		}
	}
	
	eapp->type = outputType->getType();
}

void TypeChecker::visitEPIncr(EPIncr *epincr)
{
  /* Code For EPIncr Goes Here */
  //printf("visitEPIncr\n");

  epincr->exp_->accept(this);

	if (epincr->exp_->type == "string" || epincr->exp_->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	}
	else {
		epincr->type = epincr->exp_->type;
	}

}

void TypeChecker::visitEPDecr(EPDecr *epdecr)
{
  /* Code For EPDecr Goes Here */
  //printf("visitEPDecr\n");

  epdecr->exp_->accept(this);

	if (epdecr->exp_->type == "string" || epdecr->exp_->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	}
	else {
		epdecr->type = epdecr->exp_->type;
	}

}

void TypeChecker::visitEIncr(EIncr *eincr)
{
  /* Code For EIncr Goes Here */
  //printf("visitEIncr\n");

  eincr->exp_->accept(this);

	if (eincr->exp_->type == "string" || eincr->exp_->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	}
	else {
		eincr->type = eincr->exp_->type;
	}

}

void TypeChecker::visitEDecr(EDecr *edecr)
{
  /* Code For EDecr Goes Here */
  //printf("visitEDecr\n");

  edecr->exp_->accept(this);

	if (edecr->exp_->type == "string" || edecr->exp_->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	}
	else {
		edecr->type = edecr->exp_->type;
	}

}

void TypeChecker::visitETimes(ETimes *etimes)
{
  /* Code For ETimes Goes Here */
  //printf("visitETimes\n");

  etimes->exp_1->accept(this);
  etimes->exp_2->accept(this);

	if (etimes->exp_1->type == "string" || etimes->exp_1->type == "bool" || etimes->exp_2->type == "string" || etimes->exp_2->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	} else if (etimes->exp_1->type == "int" && etimes->exp_2->type == "int"){
		etimes->type = "int";
	} else if (etimes->exp_1->type == "double" && etimes->exp_2->type == "double"){
		etimes->type = "double";
	//} else if (etimes->exp_1->type == "int" && etimes->exp_2->type == "double"){
	//	etimes->type = "double";
	//} else if (etimes->exp_1->type == "double" && etimes->exp_2->type == "int") {
	//	etimes->type = "double";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */
  //printf("visitEDiv\n");

  ediv->exp_1->accept(this);
  ediv->exp_2->accept(this);

	if (ediv->exp_1->type == "string" || ediv->exp_1->type == "bool" || ediv->exp_2->type == "string" || ediv->exp_2->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	} else if (ediv->exp_1->type == "int" && ediv->exp_2->type == "int"){
		ediv->type = "int";
	} else if (ediv->exp_1->type == "double" && ediv->exp_2->type == "double"){
		ediv->type = "double";
	} else if ((ediv->exp_1->type == "int" && ediv->exp_2->type == "double") || (ediv->exp_1->type == "double" && ediv->exp_2->type == "int")){
		ediv->type = "double";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitEPlus(EPlus *eplus)
{
  /* Code For EPlus Goes Here */
  //printf("visitEPlus\n");

  eplus->exp_1->accept(this);
  eplus->exp_2->accept(this);

	if (eplus->exp_1->type == "bool" || eplus->exp_2->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	} else if (eplus->exp_1->type == "int" && eplus->exp_2->type == "int"){
		eplus->type = "int";
	} else if (eplus->exp_1->type == "double" && eplus->exp_2->type == "double"){
		eplus->type = "double";
	} else if (eplus->exp_1->type == "string" && eplus->exp_2->type == "string"){
		eplus->type = "string";
	} else if ((eplus->exp_1->type == "int" && eplus->exp_2->type == "double") || (eplus->exp_1->type == "double" && eplus->exp_2->type == "int")){
		eplus->type = "double";
	} else if ((eplus->exp_1->type == "string" && eplus->exp_2->type == "double") || (eplus->exp_1->type == "double" && eplus->exp_2->type == "string")){
		eplus->type = "string";
	} else if ((eplus->exp_1->type == "int" && eplus->exp_2->type == "string") || (eplus->exp_1->type == "string" && eplus->exp_2->type == "int")){
		eplus->type = "string";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitEMinus(EMinus *eminus)
{
  /* Code For EMinus Goes Here */
  //printf("visitEMinus\n");

  eminus->exp_1->accept(this);
  eminus->exp_2->accept(this);

	if (eminus->exp_1->type == "string" || eminus->exp_1->type == "bool" || eminus->exp_2->type == "string" || eminus->exp_2->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	} else if (eminus->exp_1->type == "int" && eminus->exp_2->type == "int"){
		eminus->type = "int";
	} else if (eminus->exp_1->type == "double" && eminus->exp_2->type == "double"){
		eminus->type = "double";
	} else if ((eminus->exp_1->type == "int" && eminus->exp_2->type == "double") || (eminus->exp_1->type == "double" && eminus->exp_2->type == "int")){
		eminus->type = "double";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */
  //printf("visitELt\n");

  elt->exp_1->accept(this);
  elt->exp_2->accept(this);

	if (elt->exp_1->type == "string" || elt->exp_1->type == "bool" || elt->exp_2->type == "string" || elt->exp_2->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	} else if (elt->exp_1->type == "int" && elt->exp_2->type == "int"){
		elt->type = "bool";
	} else if (elt->exp_1->type == "double" && elt->exp_2->type == "double"){
		elt->type = "bool";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */
  //printf("visitEGt\n");

  egt->exp_1->accept(this);
  egt->exp_2->accept(this);

	if (egt->exp_1->type == "string" || egt->exp_1->type == "bool" || egt->exp_2->type == "string" || egt->exp_2->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	} else if (egt->exp_1->type == "int" && egt->exp_2->type == "int"){
		egt->type = "bool";
	} else if (egt->exp_1->type == "double" && egt->exp_2->type == "double"){
		egt->type = "bool";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitELtEq(ELtEq *elteq)
{
  /* Code For ELtEq Goes Here */
  //printf("visitELtEq\n");

  elteq->exp_1->accept(this);
  elteq->exp_2->accept(this);

	if (elteq->exp_1->type == "string" || elteq->exp_1->type == "bool" || elteq->exp_2->type == "string" || elteq->exp_2->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	} else if (elteq->exp_1->type == "int" && elteq->exp_2->type == "int"){
		elteq->type = "bool";
	} else if (elteq->exp_1->type == "double" && elteq->exp_2->type == "double"){
		elteq->type = "bool";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitEGtEq(EGtEq *egteq)
{
  /* Code For EGtEq Goes Here */
  //printf("visitEGtEq\n");

  egteq->exp_1->accept(this);
  egteq->exp_2->accept(this);

	if (egteq->exp_1->type == "string" || egteq->exp_1->type == "bool" || egteq->exp_2->type == "string" || egteq->exp_2->type == "bool") {
		printf("TYPE ERROR");
		exit(1);
	} else if (egteq->exp_1->type == "int" && egteq->exp_2->type == "int"){
		egteq->type = "bool";
	} else if (egteq->exp_1->type == "double" && egteq->exp_2->type == "double"){
		egteq->type = "bool";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitEEq(EEq *eeq)
{
  /* Code For EEq Goes Here */
  //printf("visitEEq\n");

  eeq->exp_1->accept(this);
  eeq->exp_2->accept(this);

	if (eeq->exp_1->type == "int" && eeq->exp_2->type == "int"){
		eeq->type = "bool";
	} else if (eeq->exp_1->type == "double" && eeq->exp_2->type == "double"){
		eeq->type = "bool";
	} else if (eeq->exp_1->type == "string" && eeq->exp_2->type == "string"){
		eeq->type = "bool";
	} else if (eeq->exp_1->type == "bool" && eeq->exp_2->type == "bool"){
		eeq->type = "bool";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitENEq(ENEq *eneq)
{
  /* Code For ENEq Goes Here */
  //printf("visitENEq\n");

  eneq->exp_1->accept(this);
  eneq->exp_2->accept(this);

	if (eneq->exp_1->type == "int" && eneq->exp_2->type == "int"){
		eneq->type = "bool";
	} else if (eneq->exp_1->type == "double" && eneq->exp_2->type == "double"){
		eneq->type = "bool";
	} else if (eneq->exp_1->type == "string" && eneq->exp_2->type == "string"){
		eneq->type = "bool";
	} else if (eneq->exp_1->type == "bool" && eneq->exp_2->type == "bool"){
		eneq->type = "bool";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */
  //printf("visitEAnd\n");

  eand->exp_1->accept(this);
  eand->exp_2->accept(this);

	if (eand->exp_1->type == "bool" && eand->exp_2->type == "bool"){
		eand->type = "bool";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */
  //printf("visitEOr\n");

  eor->exp_1->accept(this);
  eor->exp_2->accept(this);

	if (eor->exp_1->type == "bool" && eor->exp_2->type == "bool"){
		eor->type = "bool";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitEAss(EAss *eass)
{
  /* Code For EAss Goes Here */
  //printf("visitEAss\n");

  eass->exp_1->accept(this);
  eass->exp_2->accept(this);

	if (eass->exp_1->type == "int" && eass->exp_2->type == "int"){
		eass->type = "int";
	} else if (eass->exp_1->type == "double" && eass->exp_2->type == "double"){
		eass->type = "double";
	} else if (eass->exp_1->type == "string" && eass->exp_2->type == "string"){
		eass->type = "string";
	} else if (eass->exp_1->type == "bool" && eass->exp_2->type == "bool"){
		eass->type = "bool";
	} else {
		printf("TYPE ERROR");
		exit(1);
	}

}

void TypeChecker::visitETyped(ETyped *etyped)
{
  /* Code For ETyped Goes Here */
  //printf("visitETyped\n");

  etyped->exp_->accept(this);
  etyped->type_->accept(this);

}

void TypeChecker::visitType_bool(Type_bool *type_bool)
{
  /* Code For Type_bool Goes Here */
  printf("visitType_bool\n");


}

void TypeChecker::visitType_int(Type_int *type_int)
{
  /* Code For Type_int Goes Here */
  //printf("visitType_int\n");


}

void TypeChecker::visitType_double(Type_double *type_double)
{
  /* Code For Type_double Goes Here */
  //printf("visitType_double\n");


}

void TypeChecker::visitType_void(Type_void *type_void)
{
  /* Code For Type_void Goes Here */
  //printf("visitType_void\n");


}

void TypeChecker::visitType_string(Type_string *type_string)
{
  /* Code For Type_string Goes Here */
  //printf("visitType_string\n");


}


void TypeChecker::visitListDef(ListDef* listdef)
{
  //printf("visitListDef\n");
  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
	printf("1\n");
    (*i)->accept(this);
	printf("2\n");
  }
printf("nanana\n");
}

void TypeChecker::visitListArg(ListArg* listarg)
{
  //printf("visitListArg\n");
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeChecker::visitListStm(ListStm* liststm)
{
  //printf("visitListStm\n");
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeChecker::visitListExp(ListExp* listexp)
{
  //printf("visitListExp\n");
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeChecker::visitListId(ListId* listid)
{
  //printf("visitListId\n");
  for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
  {
    visitId(*i) ;
  }
}


void TypeChecker::visitId(Id x)
{
  /* Code for Id Goes Here */
  //printf("visitId\n");
}

void TypeChecker::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
  //printf("visitInteger\n");
}

void TypeChecker::visitChar(Char x)
{
  /* Code for Char Goes Here */
  //printf("visitChar\n");
}

void TypeChecker::visitDouble(Double x)
{
  /* Code for Double Goes Here */
  //printf("visitDouble\n");
}

void TypeChecker::visitString(String x)
{
  /* Code for String Goes Here */
  //printf("visitString\n");
}

void TypeChecker::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
  //printf("visitIdent\n");
}
