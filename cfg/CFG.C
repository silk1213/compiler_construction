/*** BNFC-Generated Visitor Design Pattern CFG. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "CFG.H"
#include <iostream>
#include <stdlib.h>
#include <sstream>


CFG::CFG() {
	if (remove("graph.gv")) {
		std::cout << "ERROR: Failed to delete File"<< std::endl;
	}
	tmpcounter = 0;
	switcher = 0;
	blockcounter = blockcolor = 0;
}

std::string CFG::getTMP() {
	std::ostringstream convert;
	convert << tmpcounter;
	std::string result = "tmp_" + convert.str();
	tmpcounter++;
	return result;
}

void CFG::switchform(std::string output) {
	switch (switcher) {
		case 0:	emit(true, false, "\"" + temporary1 + "\" -> \"" + output + "\";"); break;
		case 1: emit(true, false, "\"" + temporary1 + "\" -> \"" + output + "\";"); emit(true, false, "\"" + temporary2 + "\" -> \"" + output + "\";"); switcher = 0; break;
		case 2: emit(true, false, "\"" + temporary1 + "\":se -> \"" + output + "\":n[label=\"false\",weight=10];"); switcher = 0; break;
		case 3: emit(true, false, "\"" + temporary1 + "\":sw -> \"" + output + "\":n[label=\"true\",weight=10];"); switcher = 0;	break;
		default: switcher = 0; break;
	}
}

void CFG::emit(bool b, bool a, std::string str) {
	out.open ("graph.gv", std::ios::app);
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

void CFG::visitProgram(Program* t) {} //abstract class
void CFG::visitDef(Def* t) {} //abstract class
void CFG::visitArg(Arg* t) {} //abstract class
void CFG::visitStm(Stm* t) {} //abstract class
void CFG::visitExp(Exp* t) {} //abstract class
void CFG::visitType(Type* t) {} //abstract class

void CFG::visitPDefs(PDefs *pdefs)
{
  /* Code For PDefs Goes Here */
	
  pdefs->listdef_->accept(this);
}

void CFG::visitDFun(DFun *dfun)
{
  /* Code For DFun Goes Here */

	switcher = 0;
	ret = false;

  dfun->type_->accept(this);
  visitId(dfun->id_);
  dfun->listarg_->accept(this);

	emit(true, false, "Digraph " + dfun->id_+ " {");
	emit(true, false, "label = \"function: " + dfun->id_ + "\";");
	emit(true, false, "clusterrank = sink;");
	temporary1 = "Start";
	
  dfun->liststm_->accept(this);

	if(!ret && dfun->type_->getType() == "void") {
		switchform("End");
	}
	emit(true, false, "}");
}

void CFG::visitADecl(ADecl *adecl)
{
  /* Code For ADecl Goes Here */

  adecl->type_->accept(this);
  visitId(adecl->id_);

}

void CFG::visitSExp(SExp *sexp)
{
  /* Code For SExp Goes Here */

	sexp->exp_->accept(this);

	switchform(sexp->exp_->temporary);
  
	temporary1 = sexp->exp_->temporary;
}

void CFG::visitSDecls(SDecls *sdecls)
{
  /* Code For SDecls Goes Here */

  sdecls->type_->accept(this);
  sdecls->listid_->accept(this);

	std::string tmp;

	for (ListId::iterator i = sdecls->listid_->begin() ; i != sdecls->listid_->end() ; ++i)
  {
    if((i+1) != sdecls->listid_->end()){
			tmp += *i + ", ";
		} else {
			tmp += *i;
		}
  }

	switchform("Declaration " + tmp);
	temporary1 = "Declaration " + tmp;
}

void CFG::visitSInit(SInit *sinit)
{
  /* Code For SInit Goes Here */

  sinit->type_->accept(this);
  visitId(sinit->id_);
  sinit->exp_->accept(this);

	switchform("Initialization " + sinit->id_);
	temporary1 = "Initialization " + sinit->id_;
}

void CFG::visitSReturn(SReturn *sreturn)
{
  /* Code For SReturn Goes Here */

  sreturn->exp_->accept(this);
	switchform("return " + sreturn->exp_->temporary);
	emit(true, false, "\"return " + sreturn->exp_->temporary + "\" -> End;");

	switcher = 4;
	ret = true;
}

void CFG::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
  /* Code For SReturnVoid Goes Here */

	switchform("End");
	switcher = 4;
	ret = true;
}

void CFG::visitSWhile(SWhile *swhile)
{
  /* Code For SWhile Goes Here */
	
  swhile->exp_->accept(this);

	std::string output = "Branch " + swhile->exp_->temporary;
	switchform(output);
	temporary1 = output;

	switcher = 3;
  swhile->stm_->accept(this);

	switchform(output);
	//emit(false, false, "\"" + output + "\"");

	switcher = 2;
	ret = false;
	temporary1 = output;
}

void CFG::visitSBlock(SBlock *sblock)
{
  /* Code For SBlock Goes Here */

	blockcounter++;
	blockcolor++;
	std::ostringstream convert;
	convert << blockcounter;
	std::string counter = convert.str();

	if (!sblock->liststm_->empty()) {
		emit(true, false, "subgraph cluster" + counter + " {");
		emit(true, false, "label = \"block #" + counter + "\"");
		emit(true, false, "clusterrank = sink;");
		emit(true, false, "labelloc = b;");
		//emit(true, false, "rank = min;");

		if(blockcolor % 2 == 1 ){
			emit(true, false, "node [style=filled,color=white,rank=sink];");
			emit(true, false, "style=filled;");
			emit(true, false, "color=grey;");
		}	else {
			emit(true, false, "node [style=filled,color=grey,rank=sink];");
			emit(true, false, "style=filled;");
			emit(true, false, "color=white;");
		}
  	sblock->liststm_->accept(this);
		emit(true, false, "}");
	} 
	blockcolor--;
}

void CFG::visitSIfElse(SIfElse *sifelse)
{
  /* Code For SIfElse Goes Here */

  sifelse->exp_->accept(this);
	
	bool rettmp = ret;
	bool ret1, ret2;
	ret1 = ret2 = false;

	std::string output = "branch " + sifelse->exp_->temporary;

	switchform(output);
	//emit(false, false, "\"" + output + "\"");

	temporary1 = output;
	switcher = 3;
	sifelse->stm_1->accept(this);
	temporary2 = temporary1;
	
	if(!rettmp){
		ret1 = ret;
		ret = false;
	}

	switcher = 2;
	temporary1 = output;
	//emit(false, false, "\"" + output + "\"");
  sifelse->stm_2->accept(this);
	
	if(!rettmp){
		ret2 = ret;
		ret = ret1 && ret2;
	}

	switcher = 1;
}

void CFG::visitETrue(ETrue *etrue)
{
  /* Code For ETrue Goes Here */
	
	etrue->temporary = "true";
}

void CFG::visitEFalse(EFalse *efalse)
{
  /* Code For EFalse Goes Here */

	efalse->temporary = "false";
}

void CFG::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */

  visitInteger(eint->integer_);
	std::ostringstream convert;
	convert << eint->integer_;
	eint->temporary = convert.str();
}

void CFG::visitEDouble(EDouble *edouble)
{
  /* Code For EDouble Goes Here */

  visitDouble(edouble->double_);
	std::ostringstream convert;
	convert << edouble->double_;
	edouble->temporary = convert.str();
}

void CFG::visitEString(EString *estring)
{
  /* Code For EString Goes Here */

  visitString(estring->string_);
	estring->temporary = estring->string_;
}

void CFG::visitEId(EId *eid)
{
  /* Code For EId Goes Here */

  visitId(eid->id_);
	eid->temporary = eid->id_;
}

void CFG::visitEApp(EApp *eapp)
{
  /* Code For EApp Goes Here */

  visitId(eapp->id_);
  std::string tmp = "";
	for (ListExp::iterator i = eapp->listexp_->begin() ; i != eapp->listexp_->end() ; ++i)
  {
    (*i)->accept(this);
		if ((i+1) != eapp->listexp_->end()) {
			tmp += (*i)->temporary + ", ";
		} else {
			tmp += (*i)->temporary;
		}
  }
	eapp->temporary = eapp->id_ + "(" + tmp + ")";
}

void CFG::visitEPIncr(EPIncr *epincr)
{
  /* Code For EPIncr Goes Here */

  epincr->exp_->accept(this);
	epincr->temporary = epincr->exp_->temporary + "++";
}

void CFG::visitEPDecr(EPDecr *epdecr)
{
  /* Code For EPDecr Goes Here */

  epdecr->exp_->accept(this);
	epdecr->temporary = epdecr->exp_->temporary + "--";
}

void CFG::visitEIncr(EIncr *eincr)
{
  /* Code For EIncr Goes Here */

  eincr->exp_->accept(this);
	eincr->temporary = eincr->exp_->temporary + "++";
}

void CFG::visitEDecr(EDecr *edecr)
{
  /* Code For EDecr Goes Here */

  edecr->exp_->accept(this);
	edecr->temporary = edecr->exp_->temporary + "--";
}

void CFG::visitETimes(ETimes *etimes)
{
  /* Code For ETimes Goes Here */

  etimes->exp_1->accept(this);
  etimes->exp_2->accept(this);
	etimes->temporary = etimes->exp_1->temporary + " * " + etimes->exp_2->temporary;
}

void CFG::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */

  ediv->exp_1->accept(this);
  ediv->exp_2->accept(this);
	ediv->temporary = ediv->exp_1->temporary + " / " + ediv->exp_2->temporary;
}

void CFG::visitEPlus(EPlus *eplus)
{
  /* Code For EPlus Goes Here */

  eplus->exp_1->accept(this);
  eplus->exp_2->accept(this);
	eplus->temporary = eplus->exp_1->temporary + " + " + eplus->exp_2->temporary;
}

void CFG::visitEMinus(EMinus *eminus)
{
  /* Code For EMinus Goes Here */

  eminus->exp_1->accept(this);
  eminus->exp_2->accept(this);
	eminus->temporary = eminus->exp_1->temporary + " - " + eminus->exp_2->temporary;
}

void CFG::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */

  elt->exp_1->accept(this);
  elt->exp_2->accept(this);
	elt->temporary = elt->exp_1->temporary + " < " + elt->exp_2->temporary;
}

void CFG::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */

  egt->exp_1->accept(this);
  egt->exp_2->accept(this);
	egt->temporary = egt->exp_1->temporary + " > " + egt->exp_2->temporary;
}

void CFG::visitELtEq(ELtEq *elteq)
{
  /* Code For ELtEq Goes Here */

  elteq->exp_1->accept(this);
  elteq->exp_2->accept(this);
	elteq->temporary = elteq->exp_1->temporary + " <= " + elteq->exp_2->temporary;
}

void CFG::visitEGtEq(EGtEq *egteq)
{
  /* Code For EGtEq Goes Here */

  egteq->exp_1->accept(this);
  egteq->exp_2->accept(this);
	egteq->temporary = egteq->exp_1->temporary + " >= " + egteq->exp_2->temporary;
}

void CFG::visitEEq(EEq *eeq)
{
  /* Code For EEq Goes Here */

  eeq->exp_1->accept(this);
  eeq->exp_2->accept(this);
	eeq->temporary = eeq->exp_1->temporary + " == " + eeq->exp_2->temporary;
}

void CFG::visitENEq(ENEq *eneq)
{
  /* Code For ENEq Goes Here */

  eneq->exp_1->accept(this);
  eneq->exp_2->accept(this);
	eneq->temporary = eneq->exp_1->temporary + " != " + eneq->exp_2->temporary;
}

void CFG::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */

  eand->exp_1->accept(this);
  eand->exp_2->accept(this);
	eand->temporary = eand->exp_1->temporary + " && " + eand->exp_2->temporary;
}

void CFG::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */

  eor->exp_1->accept(this);
  eor->exp_2->accept(this);
	eor->temporary = eor->exp_1->temporary + " || " + eor->exp_2->temporary;
}

void CFG::visitEAss(EAss *eass)
{
  /* Code For EAss Goes Here */

  eass->exp_1->accept(this);
  eass->exp_2->accept(this);
	eass->temporary = eass->exp_1->temporary + " = " + eass->exp_2->temporary;
}

void CFG::visitETyped(ETyped *etyped)
{
  /* Code For ETyped Goes Here */

  etyped->exp_->accept(this);
  etyped->type_->accept(this);

}

void CFG::visitType_bool(Type_bool *type_bool)
{
  /* Code For Type_bool Goes Here */


}

void CFG::visitType_int(Type_int *type_int)
{
  /* Code For Type_int Goes Here */


}

void CFG::visitType_double(Type_double *type_double)
{
  /* Code For Type_double Goes Here */


}

void CFG::visitType_void(Type_void *type_void)
{
  /* Code For Type_void Goes Here */


}

void CFG::visitType_string(Type_string *type_string)
{
  /* Code For Type_string Goes Here */


}


void CFG::visitListDef(ListDef* listdef)
{
  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void CFG::visitListArg(ListArg* listarg)
{
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void CFG::visitListStm(ListStm* liststm)
{
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void CFG::visitListExp(ListExp* listexp)
{
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void CFG::visitListId(ListId* listid)
{
  for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
  {
    visitId(*i) ;
  }
}


void CFG::visitId(Id x)
{
  /* Code for Id Goes Here */
}

void CFG::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void CFG::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void CFG::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void CFG::visitString(String x)
{
  /* Code for String Goes Here */
}

void CFG::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}


