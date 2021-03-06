#include "Interpreter.H"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <utility>
#include <iterator>

Interpreter::Interpreter() {
	env_ = new Env();
	tmpcounter = 0;
	multivarcounter = 0;
	labelcounter = 0;
	multicondition = 0;
	label = "";
	truelabel = "";
	falselabel = "";
	nextlabel = "";
	ret_flag = 0;
	return_int = 0;
	return_double = 0;
	ret_exp = 0;
	store = false;

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
void Interpreter::emit(bool b, bool a, std::string str) {
	out.open ("output.ll", std::ios::app);
	if (b) {
		if (a) {
			out << "  " + str + "\n";
			std::cout << "  " + str << std::endl;
		} else {
			out << str + "\n";
			std::cout << str << std::endl;
		}
	} else {
		if (a) {
			out << "  " + str;
			std::cout << "  " + str;
		} else {
			out << str;
			std::cout << str;
		}
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

	tmpcounter = 0;

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
	emit (1, 0, output);
	for (it = dfun->listarg_->begin(); it != dfun->listarg_->end(); ++it) {
		emit(0, 1, "%" + newTemporary() + " = alloca " + (*it)->getType()->getLLVMType());
		if ((*it)->getType()->getType() == "int") {
			emit(1, 0, ", align 4");
		} else if ((*it)->getType()->getType() == "double") {
			emit(1, 0, ", align 8");
		}
		emit(0, 1, "store " + (*it)->getType()->getLLVMType() + " %" + (*it)->getId() + ", " + (*it)->getType()->getLLVMType() + "* %" + 
			getTemporary());
		if ((*it)->getType()->getType() == "int") {
			emit(1, 0, ", align 4");
		} else if ((*it)->getType()->getType() == "double") {
			emit(1, 0, ", align 8");
		}
		argmap.insert(std::pair<std::string, std::string>((*it)->getId(), getTemporary()));
	}
	dfun->liststm_->accept(this);
	
	env_->deleteEnv();
	argmap.erase(argmap.begin(), argmap.end());
	
	if ( dfun->type_->getType() == "void" ) {
		emit(1, 1, "ret void");
	}
	
	emit (1, 0, "}");
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
			emit (0, 1, "%" + (*i) + tmp + " = alloca " + type);
			if (sdecls->type_->getType() == "int") {
				emit(1, 0, ", align 4");
			} else if (sdecls->type_->getType() == "double") {
				emit(1, 0, ", align 8");
			} else if (sdecls->type_->getType() == "bool") {
				emit(1, 0, ", align 1");
			}
		} else {
			env_->updateVar((*i), sdecls->type_);
			emit (0, 1, "%" + (*i) + " = alloca " + type);
			if (sdecls->type_->getType() == "int") {
				emit(1, 0, ", align 4");
			} else if (sdecls->type_->getType() == "double") {
				emit(1, 0, ", align 8");
			} else if (sdecls->type_->getType() == "bool") {
				emit(1, 0, ", align 1");
			}
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
			emit (0, 1, "%" + sinit->id_ + tmp + " = alloca " + sinit->type_->getLLVMType());
			if (sinit->type_->getType() == "int") {
				emit(1, 0, ", align 4");
			} else if (sinit->type_->getType() == "double") {
				emit(1, 0, ", align 8");
			} else if (sinit->type_->getType() == "bool") {
				emit(1, 0, ", align 1");
			}
			if (getLLVMType(sinit->exp_->type) == "double" && sinit->exp_->temporary == "0") {
				emit(0, 1, "store " + getLLVMType(sinit->exp_->type)+ " " + "0.0" );
			} else {
				emit (0, 1, "store " + getLLVMType(sinit->exp_->type)+ " " + sinit->exp_->temporary);
			}
			emit (0, 0, ", " + sinit->type_->getLLVMType() + "* %" + sinit->id_ + tmp);
			if (sinit->type_->getType() == "int") {
				emit(1, 0, ", align 4");
			} else if (sinit->type_->getType() == "double") {
				emit(1, 0, ", align 8");
			} else if (sinit->type_->getType() == "bool") {
				emit(1, 0, ", align 1");
			}
		} else {
			env_->updateVar(sinit->id_, sinit->type_);
			sinit->exp_->accept(this);
			emit (0, 1, "%" + sinit->id_ + " = alloca " + sinit->type_->getLLVMType());
			if (sinit->type_->getType() == "int") {
				emit(1, 0, ", align 4");
			} else if (sinit->type_->getType() == "double") {
				emit(1, 0, ", align 8");
			} else if (sinit->type_->getType() == "bool") {
				emit(1, 0, ", align 1");
			}
			if (getLLVMType(sinit->exp_->type) == "double" && sinit->exp_->temporary == "0") {
				emit(0, 1, "store " + getLLVMType(sinit->exp_->type)+ " " + "0.0" );
			} else {
				emit (0, 1, "store " + getLLVMType(sinit->exp_->type)+ " " + sinit->exp_->temporary);
			}
			emit (0, 0, ", " + sinit->type_->getLLVMType() + "* %" + sinit->id_);
			if (sinit->type_->getType() == "int") {
				emit(1, 0, ", align 4");
			} else if (sinit->type_->getType() == "double") {
				emit(1, 0, ", align 8");
			} else if (sinit->type_->getType() == "bool") {
				emit(1, 0, ", align 1");
			}
		}
	env_->updateVar(sinit->id_, sinit->type_);
}

void Interpreter::visitSReturn(SReturn *sreturn)
{
	ret_flag = 1;
  	sreturn->exp_->accept(this);
	/*if (ret_exp == 0) {
		if (sreturn->exp_->type == "int") {
			std::string ret_int;
			std::ostringstream convert;
			convert << return_int;
			ret_int = convert.str();
			std::string exp = getLLVMType(sreturn->exp_->type) + " " + ret_int;
			emit (1, 1, "ret "+ exp + " ");
		} else if (sreturn->exp_->type == "double") {
			std::string ret_double;
			std::ostringstream convert;
			convert << return_double;
			ret_double = convert.str();
			std::string exp = getLLVMType(sreturn->exp_->type) + " " + ret_double;
			emit (1, 1, "ret "+ exp + " ");
		}		
	} else {
		std::string exp = getLLVMType(sreturn->exp_->type) + " %" + getTemporary();
		emit (1, 1, "ret "+ exp + " ");
	}*/
	
	emit(1, 1, "ret " + getLLVMType(sreturn->exp_->type) + " " + sreturn->exp_->temporary + " ");
	
	ret_flag = 0;
	ret_exp = 0;
}

void Interpreter::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
}

void Interpreter::visitSWhile(SWhile *swhile)
{
	label = "label" + newLabel();
	truelabel = "label" + newLabel();
	falselabel = "label" + newLabel();
	std::string tmp, truetmp, falsetmp;

	tmp = label;
	truetmp = truelabel;
	falsetmp = falselabel;

	emit (1, 1, "br label %" + label);
	emit (1, 1, " ");
    emit (1, 1, label + ":");

    swhile->exp_->accept(this);
	
	if (multicondition == 0) {
		emit (0, 1, "br i1 %" + getTemporary());
		std::string output_while = ", label %" + truelabel + ", label %" + falselabel;
		emit (1, 0, output_while);		
	}
	
	multicondition = 0;
	emit (1, 1, " ");
	emit (1, 1, truelabel + ":");
  	swhile->stm_->accept(this);
	emit (1, 1, "br label %" + tmp);
	emit (1, 1, " ");
	emit (1, 1, falsetmp + ":");

	
}

void Interpreter::visitSBlock(SBlock *sblock)
{
  	env_->addEnv();
  	sblock->liststm_->accept(this);
	env_->deleteEnv();
}

void Interpreter::visitSIfElse(SIfElse *sifelse)
{
	label = "label" + newLabel();
	truelabel = "label" + newLabel();
	falselabel = "label" + newLabel();
	nextlabel = "label" + newLabel();

	std::string tmp, truetmp, falsetmp, nexttmp;

	tmp = label;
	truetmp = truelabel;
	falsetmp = falselabel;
	nexttmp = nextlabel;

	sifelse->exp_->accept(this);

	if (multicondition == 0) {
		emit (1, 1, "br i1 " + sifelse->exp_->temporary + ", label %" + truelabel + ", label %" + falselabel);		
	}
	multicondition = 0;
	emit (1, 1, " ");
	emit (1, 1, truelabel + ":");
  	sifelse->stm_1->accept(this);
	emit (1, 1, "br label %" + nexttmp);
	emit (1, 1, " ");
	emit (1, 1, falsetmp + ":");
  	sifelse->stm_2->accept(this);
	emit (1, 1, "br label %" + nexttmp);
	emit (1, 1, " ");
	emit (1, 1, nexttmp + ":");
	
}

void Interpreter::visitETrue(ETrue *etrue)
{
	etrue->type = "bool";
	etrue->temporary = "1";
	store = false;
}

void Interpreter::visitEFalse(EFalse *efalse)
{
	efalse->type = "bool";
	efalse->temporary = "0";
	store = false;
}

void Interpreter::visitEInt(EInt *eint)
{
  	visitInteger(eint->integer_);
	std::ostringstream convert;
	convert << eint->integer_;
	eint->temporary = convert.str();
	store = false;
	if (ret_flag == 1) {
		return_int = eint->integer_;
	}

	eint->type = "int";
}

void Interpreter::visitEDouble(EDouble *edouble)
{
  	visitDouble(edouble->double_);
	std::ostringstream convert;
	convert << edouble->double_;
	edouble->temporary = convert.str();
	store = false;

	int tmp1 = edouble->double_;
	double tmp2 = tmp1;
	if (tmp2 == edouble->double_) {
		edouble->temporary += ".0";
	}	

	if (ret_flag == 1) {
		return_double = edouble->double_;
	}

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
	store = true;
	std::pair<Type*,int> var = env_->lookupVarIp(eid->id_);
	std::string output;

	if (ret_flag == 1) {
		ret_exp = 1; 
	}

	if(var.second == 0) {

		std::map<std::string, std::string>::iterator arg = argmap.find(eid->id_);
		if (arg == argmap.end()) {
			if (var.first->getType() == "int") {
				output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_ + " , align 4";
			} else if (var.first->getType() == "double") {
				output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_ + " , align 8";
			} else if (var.first->getType() == "bool") {
				output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_ + " , align 1";
			}
			latestFunc = eid->id_;
		} else {
			if (var.first->getType() == "int") {
				output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + arg->second + " , align 4";
			} else if (var.first->getType() == "double") {
				output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + arg->second + " , align 8";
			} else if (var.first->getType() == "bool") {
				output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + arg->second + " , align 1";
			}
			latestFunc = arg->second;
		}
	} else {
 		std::string temporary;
		std::ostringstream convert;
		convert << var.second;
		temporary = convert.str();
		if (var.first->getType() == "int") {
			output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_ + temporary + " , align 4";
		} else if (var.first->getType() == "double") {
			output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_ + temporary + " , align 8";
		} else if (var.first->getType() == "bool") {
			output = "%" + newTemporary() + " = load " + var.first->getLLVMType() + "* %" + eid->id_ + temporary + " , align 1";
		}
		latestFunc = eid->id_ + temporary;
	}
	eid->temporary = "%" + getTemporary();
	emit(1, 1, output);
	eid->type = var.first->getType();
}

void Interpreter::visitEApp(EApp *eapp)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}
	store = false;
  	visitId(eapp->id_);
 
	std::pair<ListArg*,Type*> func = env_->lookupFun (eapp->id_);
	ListArg* inputTypes = func.first;
	Type* outputType = func.second;
	ListArg::iterator it;
	ListExp::iterator it_exp;
	std::string call = "";
	std::string tmp = "";

    call += "call " + outputType->getLLVMType() + " @" + eapp->id_ + "(";
    int i = 0;
    for (it_exp = eapp->listexp_->begin(), it = inputTypes->begin() ; it_exp != eapp->listexp_->end(); ++it_exp, ++it) {
        (*it_exp)->accept(this);

        std::string tmp = (*it_exp)->temporary;
        call += (*it)->getType()->getLLVMType() + " " + tmp;
        if ((it+1) != inputTypes->end()) {
            call += ", ";
        }
	}
    call += ")";
    if ( outputType->getType() != "void" ) {
		tmp = "%" + newTemporary() + " = ";
		eapp->temporary = "%" + getTemporary();
    }	
    emit(1, 1, tmp + call);
	
	eapp->type = outputType->getType();
}

void Interpreter::visitEPIncr(EPIncr *eincr)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}
	
	eincr->type = eincr->exp_->type;

	std::string exp1;

  	eincr->exp_->accept(this);
  	exp1 = eincr->exp_->temporary;

	std::string output;

  	if (eincr->exp_->type == "int") {
  		output = "%" + newTemporary() + " = add nsw " + getLLVMType(eincr->exp_->type) + " " + exp1 + ", 1";
	} else if (eincr->exp_->type == "double") {
		output = "%" + newTemporary() + " = fadd " + getLLVMType(eincr->exp_->type) + " " + exp1 + ", 1.0";
	}

  	emit(1, 1, output);
	if(store) {
		std::string tmp = getTemporary();
		std::string output1 = "store " + getLLVMType(eincr->exp_->type) + " %" + tmp + ", " + getLLVMType(eincr->exp_->type) + "* %" + latestFunc;

		if (eincr->exp_->type == "int") {
			output1 += ", align 4";
		} else if (eincr->exp_->type == "double") {
			output1 += ", align 8";
		}
		emit(1, 1, output1);
	}
	eincr->temporary = "%" + getTemporary();
}

void Interpreter::visitEPDecr(EPDecr *edecr)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

	edecr->type = edecr->exp_->type;

	std::string exp1;

  	edecr->exp_->accept(this);
  	exp1 = edecr->exp_->temporary;

	std::string output;

	if (edecr->exp_->type == "int") {
  		output = "%" + newTemporary() + " = add nsw " + getLLVMType(edecr->exp_->type) + " " + exp1 + ", -1";
	} else if (edecr->exp_->type == "double") {
		output = "%" + newTemporary() + " = fadd " + getLLVMType(edecr->exp_->type) + " " + exp1 + ", -1.0";
	}
  	emit(1, 1, output);
	if (store) {
		std::string tmp = getTemporary();
		std::string output1 = "store " + getLLVMType(edecr->exp_->type) + " %" + tmp + ", " + getLLVMType(edecr->exp_->type) + "* %" + latestFunc;
		if (edecr->exp_->type == "int") {
			output1 += ", align 4";
		} else if (edecr->exp_->type == "double") {
			output1 += ", align 8";
		}	
		emit(1, 1, output1);
	}
	edecr->temporary = "%" + getTemporary();
}

void Interpreter::visitEIncr(EIncr *eincr)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

	eincr->type = eincr->exp_->type;

	std::string exp1;

  	eincr->exp_->accept(this);
  	exp1 = eincr->exp_->temporary;

	std::string output;

  	if (eincr->exp_->type == "int") {
  		output = "%" + newTemporary() + " = add nsw " + getLLVMType(eincr->exp_->type) + " " + exp1 + ", 1";
	} else if (eincr->exp_->type == "double") {
		output = "%" + newTemporary() + " = fadd " + getLLVMType(eincr->exp_->type) + " " + exp1 + ", 1.0";
	}
  	emit(1, 1, output);
	if (store) {
		std::string tmp = getTemporary();
		std::string output1 = "store " + getLLVMType(eincr->exp_->type) + " %" + tmp + ", " + getLLVMType(eincr->exp_->type) + "* %" + latestFunc;
		if (eincr->exp_->type == "int") {
			output1 += ", align 4";
		} else if (eincr->exp_->type == "double") {
			output1 += ", align 8";
		}
		emit(1, 1, output1);
	}
	eincr->temporary = "%" + getTemporary();
}

void Interpreter::visitEDecr(EDecr *edecr)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

	edecr->type = edecr->exp_->type;

	std::string exp1;

  	edecr->exp_->accept(this);
  	exp1 = edecr->exp_->temporary;

  	std::string output;

	if (edecr->exp_->type == "int") {
  		output = "%" + newTemporary() + " = add nsw " + getLLVMType(edecr->exp_->type) + " " + exp1 + ", -1";
	} else if (edecr->exp_->type == "double") {
		output = "%" + newTemporary() + " = fadd " + getLLVMType(edecr->exp_->type) + " " + exp1 + ", -1.0";
	}
  	emit(1, 1, output);
	if (store) {
		std::string tmp = getTemporary();
		std::string output1 = "store " + getLLVMType(edecr->exp_->type) + " %" + tmp + ", " + getLLVMType(edecr->exp_->type) + "* %" + latestFunc;
		if (edecr->exp_->type == "int") {
			output1 += ", align 4";
		} else if (edecr->exp_->type == "double") {
			output1 += ", align 8";
		}	
		emit(1, 1, output1);
	}
	edecr->temporary = "%" + getTemporary();
}

void Interpreter::visitETimes(ETimes *etimes)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

    std::string exp1, exp2;

  	etimes->exp_1->accept(this);
  	exp1 = etimes->exp_1->temporary;
  	etimes->exp_2->accept(this);
  	exp2 = etimes->exp_2->temporary;
	
	std::string output;

  	if (etimes->exp_1->type == "int" && etimes->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = mul nsw " + getLLVMType(etimes->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(etimes->exp_1->type == "double" && etimes->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fmul " + getLLVMType(etimes->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(etimes->exp_1->type == "int" && etimes->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fmul " + getLLVMType(etimes->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (etimes->exp_1->type == "double" && etimes->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fmul " + getLLVMType(etimes->exp_1->type) + " " + exp1 + ", " + exp2;
	}
  	emit(1, 1, output);
	etimes->temporary = "%" + getTemporary();
}

void Interpreter::visitEDiv(EDiv *ediv)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

    std::string exp1, exp2;

  	ediv->exp_1->accept(this);
  	exp1 = ediv->exp_1->temporary;
  	ediv->exp_2->accept(this);
  	exp2 = ediv->exp_2->temporary;

	std::string output;

  	if (ediv->exp_1->type == "int" && ediv->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = sdiv " + getLLVMType(ediv->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(ediv->exp_1->type == "double" && ediv->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fdiv " + getLLVMType(ediv->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(ediv->exp_1->type == "int" && ediv->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fdiv " + getLLVMType(ediv->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (ediv->exp_1->type == "double" && ediv->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fdiv " + getLLVMType(ediv->exp_1->type) + " " + exp1 + ", " + exp2;
	}

  	emit(1, 1, output);
	ediv->temporary = "%" + getTemporary();
}

void Interpreter::visitEPlus(EPlus *eplus)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

	std::string exp1, exp2;

  	eplus->exp_1->accept(this);
  	exp1 = eplus->exp_1->temporary;
  	eplus->exp_2->accept(this);
  	exp2 = eplus->exp_2->temporary;

	std::string output;		

	if (eplus->exp_1->type == "int" && eplus->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = add nsw " + getLLVMType(eplus->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(eplus->exp_1->type == "double" && eplus->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fadd " + getLLVMType(eplus->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(eplus->exp_1->type == "int" && eplus->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fadd " + getLLVMType(eplus->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (eplus->exp_1->type == "double" && eplus->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fadd " + getLLVMType(eplus->exp_1->type) + " " + exp1 + ", " + exp2;
	}
  	emit(1, 1, output);
	eplus->temporary = "%" + getTemporary();
}

void Interpreter::visitEMinus(EMinus *eminus)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

	std::string exp1, exp2;

	eminus->exp_1->accept(this);
	exp1 = eminus->exp_1->temporary;
	eminus->exp_2->accept(this);
	exp2 = eminus->exp_2->temporary;

	std::string output;		

	if (eminus->exp_1->type == "int" && eminus->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = sub nsw " + getLLVMType(eminus->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(eminus->exp_1->type == "double" && eminus->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fsub " + getLLVMType(eminus->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(eminus->exp_1->type == "int" && eminus->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fsub " + getLLVMType(eminus->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (eminus->exp_1->type == "double" && eminus->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fsub " + getLLVMType(eminus->exp_1->type) + " " + exp1 + ", " + exp2;
	}
	emit(1, 1, output);
	eminus->temporary = "%" + getTemporary();
}

void Interpreter::visitELt(ELt *elt)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

    std::string exp1, exp2;

  	elt->exp_1->accept(this);
  	exp1 = elt->exp_1->temporary;
  	elt->exp_2->accept(this);
  	exp2 = elt->exp_2->temporary;

	std::string output;

	if (elt->exp_1->type == "int" && elt->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = icmp slt " + getLLVMType(elt->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(elt->exp_1->type == "double" && elt->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp olt " + getLLVMType(elt->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(elt->exp_1->type == "int" && elt->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp olt " + getLLVMType(elt->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (elt->exp_1->type == "double" && elt->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fcmp olt " + getLLVMType(elt->exp_1->type) + " " + exp1 + ", " + exp2;
	}
  	emit(1, 1, output);
	elt->temporary = "%" + getTemporary();
}

void Interpreter::visitEGt(EGt *egt)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

    std::string exp1, exp2;

  	egt->exp_1->accept(this);
  	exp1 = egt->exp_1->temporary;
  	egt->exp_2->accept(this);
  	exp2 = egt->exp_2->temporary;

	std::string output;

	if (egt->exp_1->type == "int" && egt->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = icmp sgt " + getLLVMType(egt->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(egt->exp_1->type == "double" && egt->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp ogt " + getLLVMType(egt->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(egt->exp_1->type == "int" && egt->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp ogt " + getLLVMType(egt->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (egt->exp_1->type == "double" && egt->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fcmp ogt " + getLLVMType(egt->exp_1->type) + " " + exp1 + ", " + exp2;
	}
  	emit(1, 1, output);
	egt->temporary = "%" + getTemporary();
}

void Interpreter::visitELtEq(ELtEq *elteq)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

    std::string exp1, exp2;

  	elteq->exp_1->accept(this);
  	exp1 = elteq->exp_1->temporary;
  	elteq->exp_2->accept(this);
  	exp2 = elteq->exp_2->temporary;

	std::string output;	

	if (elteq->exp_1->type == "int" && elteq->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = icmp sle " + getLLVMType(elteq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(elteq->exp_1->type == "double" && elteq->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp ole " + getLLVMType(elteq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(elteq->exp_1->type == "int" && elteq->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp ole " + getLLVMType(elteq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (elteq->exp_1->type == "double" && elteq->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fcmp ole " + getLLVMType(elteq->exp_1->type) + " " + exp1 + ", " + exp2;
	}
  	emit(1, 1, output);
	elteq->temporary = "%" + getTemporary();
}

void Interpreter::visitEGtEq(EGtEq *egteq)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

    std::string exp1, exp2;

  	egteq->exp_1->accept(this);
  	exp1 = egteq->exp_1->temporary;
  	egteq->exp_2->accept(this);
  	exp2 = egteq->exp_2->temporary;

	std::string output;	

	if (egteq->exp_1->type == "int" && egteq->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = icmp sge " + getLLVMType(egteq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(egteq->exp_1->type == "double" && egteq->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp oge " + getLLVMType(egteq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(egteq->exp_1->type == "int" && egteq->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp oge " + getLLVMType(egteq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (egteq->exp_1->type == "double" && egteq->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fcmp oge " + getLLVMType(egteq->exp_1->type) + " " + exp1 + ", " + exp2;
	}
  	emit(1, 1, output);
	egteq->temporary = "%" + getTemporary();
}

void Interpreter::visitEEq(EEq *eeq)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

    std::string exp1, exp2;

  	eeq->exp_1->accept(this);
  	exp1 = eeq->exp_1->temporary;
  	eeq->exp_2->accept(this);
  	exp2 = eeq->exp_2->temporary;

	std::string output;	

	if (eeq->exp_1->type == "int" && eeq->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = icmp eq " + getLLVMType(eeq->exp_1->type)  + " " + exp1 + ", " + exp2;
	} else if(eeq->exp_1->type == "double" && eeq->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp oeq " + getLLVMType(eeq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(eeq->exp_1->type == "int" && eeq->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp oeq " + getLLVMType(eeq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (eeq->exp_1->type == "double" && eeq->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fcmp oeq " + getLLVMType(eeq->exp_1->type) + " " + exp1 + ", " + exp2;
	}
  	emit(1, 1, output);
	eeq->temporary = "%" + getTemporary();
}

void Interpreter::visitENEq(ENEq *eneq)
{
	if (ret_flag ==1) {
		ret_exp = 1;
	}

    std::string exp1, exp2;

  	eneq->exp_1->accept(this);
	exp1 = eneq->exp_1->temporary;
  	eneq->exp_2->accept(this);
	exp2 = eneq->exp_2->temporary;

	std::string output;	

	if (eneq->exp_1->type == "int" && eneq->exp_2->type == "int") {
  		output = "%" + newTemporary() + " = icmp ne " + getLLVMType(eneq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(eneq->exp_1->type == "double" && eneq->exp_2->type == "int") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp2 + " to double");
		exp2 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp une " + getLLVMType(eneq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if(eneq->exp_1->type == "int" && eneq->exp_2->type == "double") {
		emit(1, 1, "%" + newTemporary() + " = sitofp i32 " + exp1 + " to double");
		exp1 = "%" + getTemporary();
		output = "%" + newTemporary() + " = fcmp une " + getLLVMType(eneq->exp_1->type) + " " + exp1 + ", " + exp2;
	} else if (eneq->exp_1->type == "double" && eneq->exp_2->type == "double") {
		output = "%" + newTemporary() + " = fcmp une " + getLLVMType(eneq->exp_1->type) + " " + exp1 + ", " + exp2;
	}
  	emit(1, 1, output);
	eneq->temporary = "%" + getTemporary();
}

void Interpreter::visitEAnd(EAnd *eand)
{
	std::string exp1, exp2;

    std::string andtruelabel = "label" + newLabel();
	std::string truetmp = truelabel;
	truelabel = andtruelabel;

    eand->exp_1->accept(this);

	if (multicondition == 0) {
    	exp1 = eand->exp_1->temporary;
    	emit (1, 1, "br i1 " + exp1 + ", label %" + andtruelabel + ", label %" + falselabel);
	}

	emit (1, 1, " ");
    emit (1, 1, andtruelabel + ":");
    eand->exp_2->accept(this);
    exp2 = eand->exp_2->temporary;
    emit (1, 1, "br i1 " + exp2 + ", label %" + truetmp + ", label %" + falselabel);
	
	truelabel = truetmp;	
	multicondition = 1;
}

void Interpreter::visitEOr(EOr *eor)
{
	

  	std::string orfalselabel = "label" + newLabel();
  	std::string exp1, exp2;
	std::string falsetmp = falselabel;
	falselabel = orfalselabel;

  	eor->exp_1->accept(this);

	if (multicondition == 0) {
  		exp1 = eor->exp_1->temporary;
  		emit (1, 1, "br i1 " + exp1 + ", label %" + truelabel + ", label %" + orfalselabel);
	}

	falselabel = falsetmp;

	emit (1, 1, " ");
  	emit (1, 1, orfalselabel + ":");

  	eor->exp_2->accept(this);
  	exp2 = eor->exp_2->temporary;
	
  	emit (1, 1, "br i1 " + exp2 + ", label %" + truelabel + ", label %" + falselabel);
	multicondition = 1;
}

void Interpreter::visitEAss(EAss *eass)
{
	std::string exp2;
	eass->exp_2->accept(this);
	eass->exp_1->accept(this);
  	
  	exp2 = eass->exp_2->temporary;

	if (getLLVMType(eass->exp_2->type) == "double" && eass->exp_2->temporary == "0") {
		emit(0, 1, "store " + getLLVMType(eass->exp_2->type)+ " " + "0.0" );
		eass->temporary = "0.0";
	} else {
		emit (0, 1, "store " + getLLVMType(eass->exp_2->type)+ " " + eass->exp_2->temporary);
		eass->temporary = eass->exp_2->temporary;
	}
  	
  	emit(0, 0, ", " + getLLVMType(eass->exp_1->type) + "* %" + latestFunc);
	if (eass->exp_1->type == "int") {
		emit(1, 0, ", align 4");
	} else if (eass->exp_1->type == "double") {
		emit(1, 0, ", align 8");
	} else if (eass->exp_1->type == "bool") {
		emit(1, 0, ", align 1");
	}
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
