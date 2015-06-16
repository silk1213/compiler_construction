#include "Interpreter.H"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>

Interpreter::Interpreter() {
	env_ = new Env();
	tmpcounter = 0;
	multivarcounter = 0;
	labelcounter = 0;

	if (remove("output.ll")) {
		std::cout << "Failed to delete File"<< std::endl;
	} else {
		std::cout << "File successfully deleted"<< std::endl;
	}
}

Interpreter::~Interpreter() {
	delete env_;
	
}

//b = 1: endline, b = 0: same line
void Interpreter::emit(bool b, std::string str) {
	out.open ("output.ll", std::ios::app);
	if (b) {
		out << str + "\n";
		std::cout << str << std::endl;
	} else {
		out << str;
		std::cout << str;
	}
	out.close();
}

std::string Interpreter::getLLVMType(std::string type) {
    if (type == "int") {
        return "i32";
    } else if (type == "double") {
        return type;
    } else if (type == "bool") {
        return "i1";
    } else {
        return "";
    }
}

std::string Interpreter::newTemporary () {
	tmpcounter++;
	std::string temporary;
	std::ostringstream convert;
	convert << tmpcounter;
	temporary = convert.str();
	
	return temporary;
}

std::string Interpreter::getTemporary () {
    std::string temporary;
    std::ostringstream convert;
    convert << tmpcounter;
    temporary = convert.str();
    return temporary;
}

std::string Interpreter::newLabel() {
	std::string tmp;
	std::ostringstream conv;
	conv << labelcounter;
	tmp = conv.str();
	labelcounter++;
	return tmp;
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
	for (it = dfun->listarg_->begin(); it != dfun->listarg_->end(); ++it) {
		emit(1, "%" + newTemporary() + " = alloca " + (*it)->getType()->getLLVMType() + " , align 4");
		emit(1, "store " + (*it)->getType()->getLLVMType() + " %" + (*it)->getId() + ", " + (*it)->getType()->getLLVMType() + "* %" + getTemporary() + " , align 4");
	}
	dfun->liststm_->accept(this);
	emit (1, "}");
	env_->deleteEnv();
}

void Interpreter::visitADecl(ADecl *adecl)
{
  	adecl->type_->accept(this);
  	visitId(adecl->id_);
}

void Interpreter::visitSExp(SExp *sexp)
{
  	sexp->exp_->accept(this);
}

void Interpreter::visitSDecls(SDecls *sdecls)
{
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
			sinit->exp_->accept(this);
			emit (1, "%" + sinit->id_ + tmp + " = alloca " + sinit->type_->getLLVMType() + ", align 4");
			emit (0, "store " + getLLVMType(sinit->exp_->type)+ " " + sinit->exp_->temporary);
			
			emit (1, ", " + sinit->type_->getLLVMType() + "* %" + sinit->id_ + tmp + ", align 4");
		} else {
			env_->updateVar(sinit->id_, sinit->type_);
			sinit->exp_->accept(this);
			emit (1, "%" + sinit->id_ + " = alloca " + sinit->type_->getLLVMType() + ", align 4");
			emit (0, "store " + getLLVMType(sinit->exp_->type) + " " + sinit->exp_->temporary);
			
			emit (1, ", " + sinit->type_->getLLVMType() + "* %" + sinit->id_ + ", align 4");
		}

	

	env_->updateVar(sinit->id_, sinit->type_);
}

void Interpreter::visitSReturn(SReturn *sreturn)
{
  	sreturn->exp_->accept(this);
	std::string exp = getLLVMType(sreturn->exp_->type) + " %"+getTemporary();
	emit (1, "ret "+ exp + " ");
}

void Interpreter::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
	std::string output = "ret void";
	emit (1, output);
}

void Interpreter::visitSWhile(SWhile *swhile)
{
	std::string whilelabel = "label" + newLabel();
	std::string truelabel = "label" + newLabel();
	std::string falselabel = "label" + newLabel();
	emit (1, "br label %" + whilelabel);
    emit (1, whilelabel + ":");

    swhile->exp_->accept(this);

    emit (0, "br i1 %"+getTemporary());

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
  	env_->addEnv();
  	sblock->liststm_->accept(this);
	env_->deleteEnv();
}

void Interpreter::visitSIfElse(SIfElse *sifelse)
{
	std::string iflabel = "label" + newLabel();
	std::string truelabel = "label" + newLabel();
	std::string falselabel = "label" + newLabel();
	std::string nextlabel = "label" + newLabel();

	emit (1, "br label %" + iflabel);
	emit (1, iflabel + ":");
	sifelse->exp_->accept(this);
	emit (1, "br i1 " + sifelse->exp_->temporary + ", label %" + truelabel + ", label %" + falselabel);

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
	etrue->type = "bool";
}

void Interpreter::visitEFalse(EFalse *efalse)
{
	efalse->type = "bool";
}

void Interpreter::visitEInt(EInt *eint)
{
  	visitInteger(eint->integer_);
	std::ostringstream convert;
	convert << eint->integer_;
	eint->temporary = convert.str();

	/*std::string integer = "%" + newTemporary();
	emit(1, integer + " = alloca i32, align 4");
	emit(1, "store i32 " + tmp + ", i32* " + integer);*/
	eint->type = "int";
}

void Interpreter::visitEDouble(EDouble *edouble)
{
  	visitDouble(edouble->double_);
	std::ostringstream convert;
	convert << edouble->double_;
	edouble->temporary = convert.str();
	/*std::string output = "double " + tmp;
	emit (0, output);*/
	edouble->type = "double";
}

void Interpreter::visitEString(EString *estring)
{
  	visitString(estring->string_);

	estring->type = "string";
}

void Interpreter::visitEId(EId *eid)
{
  	visitId(eid->id_);
	
	std::pair<Type*,int> var = env_->lookupVarIp(eid->id_);
	std::string output;

	if(var.second == 0) {

		output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_;
		latestFunc = eid->id_;
		
	} else {
 		std::string temporary;
		std::ostringstream convert;
		convert << var.second;
		temporary = convert.str();
		output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_ + temporary;
		latestFunc = eid->id_ + temporary;
	}
	eid->temporary = "%" + getTemporary();
	emit( 1, output);
	eid->type = var.first->getType();
}

void Interpreter::visitEApp(EApp *eapp)
{
  visitId(eapp->id_);
  eapp->listexp_->accept(this);
 
  std::pair<ListArg*,Type*> func = env_->lookupFun (eapp->id_);
	ListArg* inputTypes = func.first;
	Type* outputType = func.second;
	ListArg::iterator it;
	ListExp::iterator it_exp;

    std::string call = "call " + outputType->getLLVMType() + " @" + eapp->id_ + "(";
    int i = 0;
    for (it_exp = eapp->listexp_->begin(), it = inputTypes->begin() ; it_exp != eapp->listexp_->end(); ++it_exp, ++it) {
        (*it_exp)->accept(this);

        std::string tmp = (*it_exp)->temporary;
        call += (*it)->getType()->getLLVMType() + tmp;
        if ((it+1) != inputTypes->end()) {
            call += ", ";
        }
	}
    call += ")";
    emit(1, call);
	
	eapp->type = outputType->getType();
}

void Interpreter::visitEPIncr(EPIncr *eincr)
{
	eincr->type = eincr->exp_->type;

	std::string exp1;

  	eincr->exp_->accept(this);
  	exp1 = eincr->exp_->temporary;

  	std::string output = "%" + newTemporary() + " = add nsw " + getLLVMType(eincr->exp_->type) + " " + exp1 + ", 1";

  	emit(1, output);
	std::string tmp = getTemporary();
	std::string output1 = "store i32 %" + tmp + ", i32* %" + latestFunc + ", align 4";
	emit(1, output1);
	eincr->temporary = "%" + getTemporary();
}

void Interpreter::visitEPDecr(EPDecr *edecr)
{
	edecr->type = edecr->exp_->type;

	std::string exp1;

  	edecr->exp_->accept(this);
  	exp1 = edecr->exp_->temporary;

  	std::string output = "%" + newTemporary() + " = sub nsw " + getLLVMType(edecr->exp_->type) + exp1 + ", 1";

  	emit(1, output);
	
	std::string output1 = "store i32 %" + getTemporary() + ", i32* %" + latestFunc + ", align 4";
	emit(1, output1);
	edecr->temporary = "%" + getTemporary();
}

void Interpreter::visitEIncr(EIncr *eincr)
{
	eincr->type = eincr->exp_->type;

	std::string exp1;

  	eincr->exp_->accept(this);
  	exp1 = eincr->exp_->temporary;

  	std::string output = "%" + newTemporary() + " = add nsw " + getLLVMType(eincr->exp_->type) + exp1 + ", 1";

  	emit(1, output);
	
	std::string output1 = "store i32 %" + getTemporary() + ", i32* %" + latestFunc + ", allign 4";
	emit(1, output1);
	eincr->temporary = "%" + getTemporary();
}

void Interpreter::visitEDecr(EDecr *edecr)
{
	edecr->type = edecr->exp_->type;

	std::string exp1;

  	edecr->exp_->accept(this);
  	exp1 = edecr->exp_->temporary;

  	std::string output = "%" + newTemporary() + " = sub nsw " + getLLVMType(edecr->exp_->type) + exp1 + ", 1";

  	emit(1, output);
	
	std::string output1 = "store i32 %" + getTemporary() + ", i32* %" + latestFunc + ", align 4";
	emit(1, output1);
	edecr->temporary = "%" + getTemporary();
}

void Interpreter::visitETimes(ETimes *etimes)
{
    std::string exp1, exp2;

  	etimes->exp_1->accept(this);
  	exp1 = etimes->exp_1->temporary;
  	etimes->exp_2->accept(this);
  	exp2 = etimes->exp_2->temporary;

  	std::string output = "%" + newTemporary() + " = mul nsw " + getLLVMType(etimes->exp_1->type) + " " + exp1 + ", " + exp2;

  	emit(1, output);
	etimes->temporary = "%" + getTemporary();
}

void Interpreter::visitEDiv(EDiv *ediv)
{
    std::string exp1, exp2;

  	ediv->exp_1->accept(this);
  	exp1 = ediv->exp_1->temporary;
  	ediv->exp_2->accept(this);
  	exp2 = ediv->exp_2->temporary;

  	std::string output = "%" + newTemporary() + " = div nsw " + getLLVMType(ediv->exp_1->type) + " " + exp1 + ", " + exp2;

  	emit(1, output);
	ediv->temporary = "%" + getTemporary();
}

void Interpreter::visitEPlus(EPlus *eplus)
{
	std::string exp1, exp2;

  	eplus->exp_1->accept(this);
  	exp1 = eplus->exp_1->temporary;
  	eplus->exp_2->accept(this);
  	exp2 = eplus->exp_2->temporary;

  	std::string output = "%" + newTemporary() + " = add nsw " + getLLVMType(eplus->exp_1->type) + " " + exp1 + ", " + exp2;

  	emit(1, output);
	eplus->temporary = "%" + getTemporary();
}

void Interpreter::visitEMinus(EMinus *eminus)
{
	std::string exp1, exp2;

	eminus->exp_1->accept(this);
	exp1 = eminus->exp_1->temporary;
	eminus->exp_2->accept(this);
	exp2 = eminus->exp_2->temporary;

	std::string output = "%" + newTemporary() + " = sub nsw " + getLLVMType(eminus->exp_1->type) + " "+ exp1 + ", " + exp2;
	emit(1, output);
	eminus->temporary = "%" + getTemporary();
}

void Interpreter::visitELt(ELt *elt)
{
    std::string exp1, exp2;

  	elt->exp_1->accept(this);
  	exp1 = elt->exp_1->temporary;
  	elt->exp_2->accept(this);
  	exp2 = elt->exp_2->temporary;

  	std::string output = "%" + newTemporary() + " = icmp slt " + getLLVMType(elt->exp_1->type) + " " + exp1 + ", " + exp2;
  	emit(1, output);
	elt->temporary = "%" + getTemporary();
}

void Interpreter::visitEGt(EGt *egt)
{
    std::string exp1, exp2;

  	egt->exp_1->accept(this);
  	exp1 = egt->exp_1->temporary;
  	egt->exp_2->accept(this);
  	exp2 = egt->exp_2->temporary;

  	std::string output = "%" + newTemporary() + " = icmp sgt " + getLLVMType(egt->exp_1->type) + " " + exp1 + ", " + exp2;
  	emit(1, output);
	egt->temporary = "%" + getTemporary();
}

void Interpreter::visitELtEq(ELtEq *elteq)
{
    std::string exp1, exp2;

  	elteq->exp_1->accept(this);
  	exp1 = elteq->exp_1->temporary;
  	elteq->exp_2->accept(this);
  	exp2 = elteq->exp_2->temporary;

  	std::string output = "%" + newTemporary() + " = icmp sle " + getLLVMType(elteq->exp_1->type) + " " + exp1 + ", " + exp2;
  	emit(1, output);
	elteq->temporary = "%" + getTemporary();
}

void Interpreter::visitEGtEq(EGtEq *egteq)
{
    std::string exp1, exp2;

  	egteq->exp_1->accept(this);
  	exp1 = egteq->exp_1->temporary;
  	egteq->exp_2->accept(this);
  	exp2 = egteq->exp_2->temporary;

  	std::string output = "%" + newTemporary() + " = icmp sge " + getLLVMType(egteq->exp_1->type) + " " + exp1 + ", " + exp2;
  	emit(1, output);
	egteq->temporary = "%" + getTemporary();
}

void Interpreter::visitEEq(EEq *eeq)
{
    std::string exp1, exp2;

  	eeq->exp_1->accept(this);
  	exp1 = eeq->exp_1->temporary;
  	eeq->exp_2->accept(this);
  	exp2 = eeq->exp_2->temporary;

  	std::string output = "%" + newTemporary() + " = icmp eq " + getLLVMType(eeq->exp_1->type)  + " " + exp1 + ", " + exp2;
  	emit(1, output);
	eeq->temporary = "%" + getTemporary();
}

void Interpreter::visitENEq(ENEq *eneq)
{
    std::string exp1, exp2;

  	eneq->exp_1->accept(this);
	exp1 = eneq->exp_1->temporary;
  	eneq->exp_2->accept(this);
	exp2 = eneq->exp_2->temporary;

  	std::string output = "%" + newTemporary() + " = icmp ne " + getLLVMType(eneq->exp_1->type) + " " + exp1 + ", " + exp2;
  	emit(1, output);
	eneq->temporary = "%" + getTemporary();
}

void Interpreter::visitEAnd(EAnd *eand)
{
	std::string exp1, exp2;

    std::string andlabel = "label" + newLabel();
    std::string truelabel = "label" + newLabel();
    std::string nextlabel = "label" + newLabel();

	emit (1, "br label %" + andlabel);
    emit (1, andlabel + ":");
    eand->exp_1->accept(this);

    exp1 = eand->exp_1->temporary;
    emit (1, "br i1 " + exp1 + ", label %" + truelabel + ", label %" + nextlabel);

    emit (1, truelabel + ":");
    eand->exp_2->accept(this);
    exp2 = eand->exp_2->temporary;
    emit (1, "br i1 " + exp2 + ", label %" + nextlabel + ", label %" + nextlabel);

    emit (1, "br label %" + nextlabel);

    emit (1, nextlabel + ":");
}

void Interpreter::visitEOr(EOr *eor)
{
  	std::string andlabel = "label" + newLabel();
  	std::string falselabel = "label" + newLabel();
  	std::string nextlabel = "label" + newLabel();
  	std::string exp1, exp2;

	emit (1, "br label %" + andlabel);
  	emit (1, andlabel + ":");
  	eor->exp_1->accept(this);

  	exp1 = eor->exp_1->temporary;
  	emit (1, "br i1 " + exp1 + ", label %" + nextlabel + ", label %" + falselabel);

  	emit (1, falselabel + ":");
  	eor->exp_2->accept(this);
  	exp2 = eor->exp_2->temporary;
  	emit (1, "br i1 " + exp2 + ", label %" + nextlabel + ", label %" + nextlabel);

  	emit (1, "br label %" + nextlabel);

  	emit (1, nextlabel + ":");
}

void Interpreter::visitEAss(EAss *eass)
{
	std::string exp2;
	eass->exp_1->accept(this);
  	eass->exp_2->accept(this);
  	exp2 = eass->exp_2->temporary;

	//emit(1, "%" + exp2 + " = alloca " + getLLVMType(eass->exp_2->type) + ", align 4");

  	emit(0, "store " + getLLVMType(eass->exp_2->type) + " " + exp2 + ", " + getLLVMType(eass->exp_1->type) + "* ");
  	
  	emit(1,latestFunc + ", align 4");
}

void Interpreter::visitETyped(ETyped *etyped)
{
  	etyped->exp_->accept(this);
  	etyped->type_->accept(this);
}

void Interpreter::visitType_bool(Type_bool *type_bool)
{
}

void Interpreter::visitType_int(Type_int *type_int)
{
}

void Interpreter::visitType_double(Type_double *type_double)
{
}

void Interpreter::visitType_void(Type_void *type_void)
{
}

void Interpreter::visitType_string(Type_string *type_string)
{
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
}

void Interpreter::visitInteger(Integer x)
{
}

void Interpreter::visitChar(Char x)
{
}

void Interpreter::visitDouble(Double x)
{
}

void Interpreter::visitString(String x)
{
}

void Interpreter::visitIdent(Ident x)
{
}
