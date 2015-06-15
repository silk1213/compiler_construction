#include "Interpreter.H"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

Interpreter::Interpreter() {
	env_ = new Env();
	tmpcounter = 0;
	multivarcounter = 0;
}

Interpreter::~Interpreter() {
	delete env_;
}

//b = 1: endline, b = 0: same line
void Interpreter::emit(bool b, std::string str) {
	if (b) {
		std::cout << str << std::endl;
	} else {
		std::cout << str;
	}
}

std::string Interpreter::newTemporary () {
	std::string temporary;
	std::ostringstream convert;
	convert << tmpcounter;
	temporary = convert.str();
	tmpcounter++;
	return temporary;
}

Type* Interpreter::typecheck (Visitable* v) {
	v->accept (this);
	return ty_;
}

void Interpreter::visitProgram(Program* t) {} //abstract class
void Interpreter::visitDef(Def* t) {} //abstract class
void Interpreter::visitArg(Arg* t) {} //abstract class
void Interpreter::visitStm(Stm* t) {} //abstract class
void Interpreter::visitExp(Exp* t) {} //abstract class
void Interpreter::visitType(Type* t) {} //abstract class

void Interpreter::visitPDefs(PDefs *pdefs)
{
  /* Code For PDefs Goes Here */

	for(ListDef::iterator i = pdefs->listdef_->begin(); i != pdefs->listdef_->end(); i++) {
		env_->updateFun((*i)->getId(), (*i)->getArg(), (*i)->getType());
  	}

  	pdefs->listdef_->accept(this);

}

void Interpreter::visitDFun(DFun *dfun)
{
  	/* Code For DFun Goes Here */

	std::string output = "define " + dfun->type_->getLLVMType() + " @" + dfun->id_ + "(";

  	visitId(dfun->id_);

	env_->addEnv();
	dfun->listarg_->accept(this);
	ListArg::iterator it;
	for (it = dfun->listarg_->begin(); it != dfun->listarg_->end(); ++it) {
		env_->updateVar((*it)->getId(), (*it)->getType());
		output = output + (*it)->getType()->getLLVMType() + " %" + (*it)->getId();
		if ((it+1) != dfun->listarg_->end()) {
			output = output + ", ";
		}
	}
	output = output + ") #0 {";
	emit (1, output);
	dfun->liststm_->accept(this);
	emit (1, "}");
	env_->deleteEnv();
}

void Interpreter::visitADecl(ADecl *adecl)
{
  	/* Code For ADecl Goes Here */

  	adecl->type_->accept(this);
  	visitId(adecl->id_);
}

void Interpreter::visitSExp(SExp *sexp)
{
  	/* Code For SExp Goes Here */

  	sexp->exp_->accept(this);
}

void Interpreter::visitSDecls(SDecls *sdecls)
{
  	/* Code For SDecls Goes Here */
  	//printf("visitSDecls\n");

  	sdecls->type_->accept(this);
  	sdecls->listid_->accept(this);

	std::string type = sdecls->type_->getLLVMType();
	Type* t;
	
  	for(ListId::iterator i = sdecls->listid_->begin(); i != sdecls->listid_->end(); i++) {
		t = env_->lookupVar(*i);
		if (t != NULL) {
			multivarcounter++;
			env_->updateVar((*i), sdecls->type_, multivarcounter);
			std::string tmp;
			std::ostringstream convert;
			convert << multivarcounter;
			tmp = convert.str();
			emit (1, "%" + (*i) + tmp + " = alloca " + type + ", align 4");
		} else {
			env_->updateVar((*i), sdecls->type_);
			emit (1, "%" + (*i) + " = alloca " + type + ", align 4");
		}
	}
}

void Interpreter::visitSInit(SInit *sinit)
{
  	/* Code For SInit Goes Here */

  	sinit->type_->accept(this);
  	visitId(sinit->id_);

	Type* t;
	t = env_->lookupVar(sinit->id_);

  	if (t != NULL) {
			multivarcounter++;
			env_->updateVar(sinit->id_, sinit->type_, multivarcounter);
			std::string tmp;
			std::ostringstream convert;
			convert << multivarcounter;
			tmp = convert.str();
			emit (1, "%" + sinit->id_ + tmp + " = alloca " + sinit->type_->getLLVMType() + ", align 4");
			emit (0, "store ");
			sinit->exp_->accept(this);
			emit (1, ", " + sinit->type_->getLLVMType() + "* %" + sinit->id_ + tmp + ", align 4");
		} else {
			env_->updateVar(sinit->id_, sinit->type_);
			emit (1, "%" + sinit->id_ + " = alloca " + sinit->type_->getLLVMType() + ", align 4");
			emit (0, "store ");
			sinit->exp_->accept(this);
			emit (1, ", " + sinit->type_->getLLVMType() + "* %" + sinit->id_ + ", align 4");
		}

	

	env_->updateVar(sinit->id_, sinit->type_);
}

void Interpreter::visitSReturn(SReturn *sreturn)
{
  	/* Code For SReturn Goes Here */
	emit (0, "ret ");
  	sreturn->exp_->accept(this);
	emit (1, " ");
}

void Interpreter::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
  	/* Code For SReturnVoid Goes Here */
	std::string output = "ret void";
	emit (1, output);
}

void Interpreter::visitSWhile(SWhile *swhile)
{
  	/* Code For SWhile Goes Here */
	std::string whilelabel = "label" + newTemporary();
	std::string truelabel = "label" + newTemporary();
	std::string falselabel = "label" + newTemporary();
	emit (1, whilelabel + ":");
	emit (0, "br i1 EXP");
  	swhile->exp_->accept(this);
	std::string output_while = ", label %" + truelabel + ", label %" + falselabel;
	emit (1, output_while);
	emit (1, truelabel + ":");
  	swhile->stm_->accept(this);
	emit (1, "br label %" + whilelabel);
	emit (1, " ");
	emit (1, falselabel + ":");
}

void Interpreter::visitSBlock(SBlock *sblock)
{
  	/* Code For SBlock Goes Here */
  	//printf("visitSBlock\n");

  	env_->addEnv();
  	sblock->liststm_->accept(this);
	env_->deleteEnv();
}

void Interpreter::visitSIfElse(SIfElse *sifelse)
{
  	/* Code For SIfElse Goes Here */
  	//printf("visitSIfElse\n");
	std::string iflabel = "label" + newTemporary();
	std::string truelabel = "label" + newTemporary();
	std::string falselabel = "label" + newTemporary();
	std::string nextlabel = "label" + newTemporary();

	emit (1, iflabel + ":");
	emit (0, "br i1 EXP");
  	sifelse->exp_->accept(this);
	emit (1, ", label %" + truelabel + ", label %" + falselabel);

	emit (1, truelabel + ":");
  	sifelse->stm_1->accept(this);
	emit (1, "br label %" + nextlabel);

	emit (1, falselabel + ":");
  	sifelse->stm_2->accept(this);
	emit (1, "br label %" + nextlabel);

	emit (1, nextlabel + ":");

}

void Interpreter::visitETrue(ETrue *etrue)
{
  /* Code For ETrue Goes Here */
  //printf("visitETrue\n");

	etrue->type = "bool";

}

void Interpreter::visitEFalse(EFalse *efalse)
{
  /* Code For EFalse Goes Here */
  //printf("visitEFalse\n");

	efalse->type = "bool";


}

void Interpreter::visitEInt(EInt *eint)
{
  	/* Code For EInt Goes Here */
  	//printf("visitEInt\n");

  	visitInteger(eint->integer_);
	std::string tmp;
	std::ostringstream convert;
	convert << eint->integer_;
	tmp = convert.str();
	std::string output = "i32 " + tmp;
	emit (0, output);
	eint->type = "int";

}

void Interpreter::visitEDouble(EDouble *edouble)
{
  /* Code For EDouble Goes Here */
  //printf("visitEDouble\n");

  visitDouble(edouble->double_);
	std::string tmp;
	std::ostringstream convert;
	convert << edouble->double_;
	tmp = convert.str();
	std::string output = "double " + tmp;
	emit (0, output);
	edouble->type = "double";

}

void Interpreter::visitEString(EString *estring)
{
  /* Code For EString Goes Here */
  //printf("visitEString\n");

  visitString(estring->string_);

	estring->type = "string";

}

void Interpreter::visitEId(EId *eid)
{
  	/* Code For EId Goes Here */
  	//printf("visitEId\n");

  	visitId(eid->id_);
	emit( 0, "%" + eid->id_);
	
	eid->type = env_->lookupVariable(eid->id_);
}

void Interpreter::visitEApp(EApp *eapp)
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

void Interpreter::visitEPIncr(EPIncr *epincr)
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

void Interpreter::visitEPDecr(EPDecr *epdecr)
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

void Interpreter::visitEIncr(EIncr *eincr)
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

void Interpreter::visitEDecr(EDecr *edecr)
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

void Interpreter::visitETimes(ETimes *etimes)
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

void Interpreter::visitEDiv(EDiv *ediv)
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

void Interpreter::visitEPlus(EPlus *eplus)
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

void Interpreter::visitEMinus(EMinus *eminus)
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

void Interpreter::visitELt(ELt *elt)
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

void Interpreter::visitEGt(EGt *egt)
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

void Interpreter::visitELtEq(ELtEq *elteq)
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

void Interpreter::visitEGtEq(EGtEq *egteq)
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

void Interpreter::visitEEq(EEq *eeq)
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

void Interpreter::visitENEq(ENEq *eneq)
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

void Interpreter::visitEAnd(EAnd *eand)
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

void Interpreter::visitEOr(EOr *eor)
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

void Interpreter::visitEAss(EAss *eass)
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

void Interpreter::visitETyped(ETyped *etyped)
{
  /* Code For ETyped Goes Here */
  //printf("visitETyped\n");

  etyped->exp_->accept(this);
  etyped->type_->accept(this);

}

void Interpreter::visitType_bool(Type_bool *type_bool)
{
  /* Code For Type_bool Goes Here */
  //printf("visitType_bool\n");


}

void Interpreter::visitType_int(Type_int *type_int)
{
  /* Code For Type_int Goes Here */
  //printf("visitType_int\n");


}

void Interpreter::visitType_double(Type_double *type_double)
{
  /* Code For Type_double Goes Here */
  //printf("visitType_double\n");


}

void Interpreter::visitType_void(Type_void *type_void)
{
  /* Code For Type_void Goes Here */
  //printf("visitType_void\n");


}

void Interpreter::visitType_string(Type_string *type_string)
{
  /* Code For Type_string Goes Here */
  //printf("visitType_string\n");


}


void Interpreter::visitListDef(ListDef* listdef)
{
  //printf("visitListDef\n");
  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
	//printf("1\n");
    (*i)->accept(this);
	//printf("2\n");
  }
//printf("nanana\n");
//printf("OK\n");
}

void Interpreter::visitListArg(ListArg* listarg)
{
  //printf("visitListArg\n");
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Interpreter::visitListStm(ListStm* liststm)
{
  //printf("visitListStm\n");
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Interpreter::visitListExp(ListExp* listexp)
{
  //printf("visitListExp\n");
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Interpreter::visitListId(ListId* listid)
{
  //printf("visitListId\n");
  for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
  {
    visitId(*i) ;
  }
}


void Interpreter::visitId(Id x)
{
  /* Code for Id Goes Here */
  //printf("visitId\n");
}

void Interpreter::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
  //printf("visitInteger\n");
}

void Interpreter::visitChar(Char x)
{
  /* Code for Char Goes Here */
  //printf("visitChar\n");
}

void Interpreter::visitDouble(Double x)
{
  /* Code for Double Goes Here */
  //printf("visitDouble\n");
}

void Interpreter::visitString(String x)
{
  /* Code for String Goes Here */
  //printf("visitString\n");
}

void Interpreter::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
  //printf("visitIdent\n");
}
