#include "Interpreter.H"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>

Interpreter::Interpreter() {
	env_ = new Env();
	tmpcounter = 0;
	multivarcounter = 0;

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
			sinit->exp_->accept(this);
			emit (1, "%" + sinit->id_ + tmp + " = alloca " + sinit->type_->getLLVMType() + ", align 4");
			emit (0, "store " + getLLVMType(sinit->exp_->type)+ " %" + getTemporary());
			
			emit (1, ", " + sinit->type_->getLLVMType() + "* %" + sinit->id_ + tmp + ", align 4");
		} else {
			env_->updateVar(sinit->id_, sinit->type_);
			sinit->exp_->accept(this);
			emit (1, "%" + sinit->id_ + " = alloca " + sinit->type_->getLLVMType() + ", align 4");
			emit (0, "store " + getLLVMType(sinit->exp_->type) + " %" + getTemporary());
			
			emit (1, ", " + sinit->type_->getLLVMType() + "* %" + sinit->id_ + ", align 4");
		}

	

	env_->updateVar(sinit->id_, sinit->type_);
}

void Interpreter::visitSReturn(SReturn *sreturn)
{
  	/* Code For SReturn Goes Here */

  	sreturn->exp_->accept(this);
	std::string exp = "%"+getTemporary();
	emit (1, "ret "+ exp + " ");
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
	emit (0, "br i1 ");
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
	
	std::pair<Type*,int> var = env_->lookupVarIp(eid->id_);
	std::string output;

	if(var.second == 0) {

		output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_;
		
	} else {
 		std::string temporary;
		std::ostringstream convert;
		convert << var.second;
		temporary = convert.str();
		output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_ + temporary;

	}

	emit( 1, output);
	eid->type = var.first->getType();
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

    std::string call = "call " + outputType->getLLVMType() + " @" + eapp->id_ + "(";
    int i = 0;
    for (it_exp = eapp->listexp_->begin(), it = inputTypes->begin() ; it_exp != eapp->listexp_->end(); ++it_exp, ++it) {
        (*it_exp)->accept(this);

        std::string tmp = "%" + getTemporary();
        call += (*it)->getType()->getLLVMType() + tmp;
        if ((it+1) != inputTypes->end()) {
            call += ", ";
        }


        //emit(1, tmp + " = load " + (*it)->getLLVMType() + "* " + lookupVarIp((*it)->Id))

	}
    call += ")";
    emit(1, call);
	
	eapp->type = outputType->getType();
}

void Interpreter::visitEPIncr(EPIncr *eincr)
{
  	/* Code For EIncr Goes Here */
  	//printf("visitEIncr\n");	
	eincr->type = eincr->exp_->type;

	std::string exp1;

  	eincr->exp_->accept(this);
  	exp1 = "%" + getTemporary();

  	std::string output = "%" + newTemporary() + " = add nsw " + getLLVMType(eincr->exp_->type) + exp1 + ", 1";

  	emit(1, output);
	
	std::string output1 = "store i32 %" + getTemporary() + ", i32* %" + newTemporary() + ", allign 4";
	emit(1, output);
}

void Interpreter::visitEPDecr(EPDecr *edecr)
{
  // Code For EDecr Goes Here 
  // printf("visitEDecr\n");

	edecr->type = edecr->exp_->type;

	std::string exp1;

  	edecr->exp_->accept(this);
  	exp1 = "%" + getTemporary();

  	std::string output = "%" + newTemporary() + " = sub nsw " + getLLVMType(edecr->exp_->type) + exp1 + ", 1";

  	emit(1, output);
	
	std::string output1 = "store i32 %" + getTemporary() + ", i32* %" + newTemporary() + ", allign 4";
	emit(1, output);

}

void Interpreter::visitEIncr(EIncr *eincr)
{
  	/* Code For EIncr Goes Here */
  	//printf("visitEIncr\n");	
	eincr->type = eincr->exp_->type;

	std::string exp1;

  	eincr->exp_->accept(this);
  	exp1 = "%" + getTemporary();

  	std::string output = "%" + newTemporary() + " = add nsw " + getLLVMType(eincr->exp_->type) + exp1 + ", 1";

  	emit(1, output);
	
	std::string output1 = "store i32 %" + getTemporary() + ", i32* %" + newTemporary() + ", allign 4";
	emit(1, output);
}

void Interpreter::visitEDecr(EDecr *edecr)
{
  // Code For EDecr Goes Here 
  // printf("visitEDecr\n");

	edecr->type = edecr->exp_->type;

	std::string exp1;

  	edecr->exp_->accept(this);
  	exp1 = "%" + getTemporary();

  	std::string output = "%" + newTemporary() + " = sub nsw " + getLLVMType(edecr->exp_->type) + exp1 + ", 1";

  	emit(1, output);
	
	std::string output1 = "store i32 %" + getTemporary() + ", i32* %" + newTemporary() + ", allign 4";
	emit(1, output);

}

void Interpreter::visitETimes(ETimes *etimes)
{
  /* Code For ETimes Goes Here */
  //printf("visitETimes\n");

    std::string exp1, exp2;

  etimes->exp_1->accept(this);
  exp1 = "%" + getTemporary();
  etimes->exp_2->accept(this);
  exp2 = "%" + getTemporary();

  std::string output = "%" + newTemporary() + " mul nsw " + getLLVMType(etimes->exp_1->type) + " " + exp1 + ", " + exp2;

  emit(1, output);
}

void Interpreter::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */
  //printf("visitEDiv\n");

    std::string exp1, exp2;

  ediv->exp_1->accept(this);
  exp1 = "%" + getTemporary();
  ediv->exp_2->accept(this);
  exp2 = "%" + getTemporary();

  std::string output = "%" + newTemporary() + " = div nsw " + getLLVMType(ediv->exp_1->type) + " " + exp1 + ", " + exp2;

  emit(1, output);

}

void Interpreter::visitEPlus(EPlus *eplus)
{
  /* Code For EPlus Goes Here */
  //printf("visitEPlus\n");
std::string exp1, exp2;

  eplus->exp_1->accept(this);
  exp1 = "%" + getTemporary();
  eplus->exp_2->accept(this);
  exp2 = "%" + getTemporary();

  std::string output = "%" + newTemporary() + " = add nsw " + getLLVMType(eplus->exp_1->type) + " " + exp1 + ", " + exp2;

  emit(1, output);
}

void Interpreter::visitEMinus(EMinus *eminus)
{
  /* Code For EMinus Goes Here */
  //printf("visitEMinus\n");

    std::string exp1, exp2;

  eminus->exp_1->accept(this);
  exp1 = "%" + getTemporary();
  eminus->exp_2->accept(this);
  exp2 = "%" + getTemporary();


  std::string output = "%" + newTemporary() + " = sub nsw " + getLLVMType(eminus->exp_1->type) + " "+ exp1 + ", " + exp2;
  emit(1, output);

}

void Interpreter::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */
  //printf("visitELt\n");
    std::string exp1, exp2;

  elt->exp_1->accept(this);
  exp1 = "%" + getTemporary();
  elt->exp_2->accept(this);
  exp2 = "%" + getTemporary();

  std::string output = "%" + newTemporary() + " = icmp slt" + getLLVMType(elt->exp_1->type) + " " + exp1 + ", " + exp2;
  emit(1, output);



}

void Interpreter::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */
  //printf("visitEGt\n");
    std::string exp1, exp2;

  egt->exp_1->accept(this);
  exp1 = "%" + getTemporary();
  egt->exp_2->accept(this);
  exp2 = "%" + getTemporary();

  std::string output = "%" + newTemporary() + " = icmp sgt" + getLLVMType(egt->exp_1->type) + " " + exp1 + ", " + exp2;
  emit(1, output);

}

void Interpreter::visitELtEq(ELtEq *elteq)
{
  /* Code For ELtEq Goes Here */
  //printf("visitELtEq\n");
    std::string exp1, exp2;

  elteq->exp_1->accept(this);
  exp1 = "%" + getTemporary();
  elteq->exp_2->accept(this);
  exp2 = "%" + getTemporary();

  std::string output = "%" + newTemporary() + " = icmp sle" + getLLVMType(elteq->exp_1->type) + " " + exp1 + ", " + exp2;
  emit(1, output);

}

void Interpreter::visitEGtEq(EGtEq *egteq)
{
  /* Code For EGtEq Goes Here */
  //printf("visitEGtEq\n");
    std::string exp1, exp2;

  egteq->exp_1->accept(this);
  exp1 = "%" + getTemporary();
  egteq->exp_2->accept(this);
  exp2 = "%" + getTemporary();

  std::string output = "%" + newTemporary() + " = icmp sge" + getLLVMType(egteq->exp_1->type) + " " + exp1 + ", " + exp2;
  emit(1, output);


}

void Interpreter::visitEEq(EEq *eeq)
{
  /* Code For EEq Goes Here */
  //printf("visitEEq\n");
    std::string exp1, exp2;

  eeq->exp_1->accept(this);
  exp1 = "%" + getTemporary();
  eeq->exp_2->accept(this);
  exp2 = "%" + getTemporary();

  std::string output = "%" + newTemporary() + " = icmp eq " + getLLVMType(eeq->exp_1->type)  + " " + exp1 + ", " + exp2;
  emit(1, output);


}

void Interpreter::visitENEq(ENEq *eneq)
{
  /* Code For ENEq Goes Here */
  //printf("visitENEq\n");

    std::string exp1, exp2;

  eneq->exp_1->accept(this);

  exp1 = "%" + getTemporary();
  eneq->exp_2->accept(this);

  exp2 = "%" + getTemporary();

  std::string output = "%" + newTemporary() + " = icmp ne" + getLLVMType(eneq->exp_1->type) + " " + exp1 + ", " + exp2;
  emit(1, output);
}

void Interpreter::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */
  //printf("visitEAnd\n");

std::string exp1, exp2;

    std::string andlabel = "label" + newTemporary();
    std::string truelabel = "label" + newTemporary();
    std::string nextlabel = "label" + newTemporary();

    emit (1, andlabel + ":");
    eand->exp_1->accept(this);

    exp1 = "%" + getTemporary();
    emit (1, "br i1 " + exp1 + ", label %" + truelabel + ", label %" + nextlabel);

    emit (1, truelabel + ":");
    eand->exp_2->accept(this);
    exp2 = "%" + getTemporary();
    emit (1, "br i1 " + exp2 + ", label %" + nextlabel + ", label %" + nextlabel);

    emit (1, "br label %" + nextlabel);

    emit (1, nextlabel + ":");
}

void Interpreter::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */
  //printf("visitEOr\n");


  std::string andlabel = "label" + newTemporary();
  std::string falselabel = "label" + newTemporary();
  std::string nextlabel = "label" + newTemporary();
  std::string exp1, exp2;

  emit (1, andlabel + ":");
  eor->exp_1->accept(this);

  exp1 = "%" + getTemporary();
  emit (1, "br i1 " + exp1 + ", label %" + nextlabel + ", label %" + falselabel);

  emit (1, falselabel + ":");
  eor->exp_2->accept(this);
  exp2 = "%" + getTemporary();
  emit (1, "br i1 " + exp2 + ", label %" + nextlabel + ", label %" + nextlabel);

  emit (1, "br label %" + nextlabel);

  emit (1, nextlabel + ":");

}

void Interpreter::visitEAss(EAss *eass)
{
  /* Code For EAss Goes Here */
  //printf("visitEAss\n");
std::string exp2;

  eass->exp_2->accept(this);
  exp2 = "%" + getTemporary();

  emit(0, "store " + getLLVMType(eass->exp_2->type) + " " + exp2 + ", " + getLLVMType(eass->exp_1->type) + "* ");
  eass->exp_1->accept(this);
  emit(1,", align 4");
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
