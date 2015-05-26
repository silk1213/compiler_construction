/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"
#include "TypeChecker.H"
#include <stdio.h>

void Skeleton::visitProgram(Program* t) {} //abstract class
void Skeleton::visitDef(Def* t) {} //abstract class
void Skeleton::visitArg(Arg* t) {} //abstract class
void Skeleton::visitStm(Stm* t) {} //abstract class
void Skeleton::visitExp(Exp* t) {} //abstract class
void Skeleton::visitType(Type* t) {} //abstract class

void Skeleton::visitPDefs(PDefs *pdefs)
{
  /* Code For PDefs Goes Here */
  printf("visitPDefs\n");

  pdefs->listdef_->accept(this);

}

void Skeleton::visitDFun(DFun *dfun)
{
  /* Code For DFun Goes Here */
  printf("visitDFun\n");

  dfun->type_->accept(this);
  visitId(dfun->id_);
  dfun->listarg_->accept(this);
  dfun->liststm_->accept(this);

}

void Skeleton::visitADecl(ADecl *adecl)
{
  /* Code For ADecl Goes Here */
  printf("visitADecl\n");

  adecl->type_->accept(this);
  visitId(adecl->id_);

}

void Skeleton::visitSExp(SExp *sexp)
{
  /* Code For SExp Goes Here */
  printf("visitSExp\n");

  sexp->exp_->accept(this);

}

void Skeleton::visitSDecls(SDecls *sdecls)
{
  /* Code For SDecls Goes Here */
  printf("visitSDecls\n");

  sdecls->type_->accept(this);
  sdecls->listid_->accept(this);

}

void Skeleton::visitSInit(SInit *sinit)
{
  /* Code For SInit Goes Here */
  printf("visitSInit\n");

  sinit->type_->accept(this);
  visitId(sinit->id_);
  sinit->exp_->accept(this);

}

void Skeleton::visitSReturn(SReturn *sreturn)
{
  /* Code For SReturn Goes Here */
  printf("visitSReturn\n");

  sreturn->exp_->accept(this);

}

void Skeleton::visitSReturnVoid(SReturnVoid *sreturnvoid)
{
  /* Code For SReturnVoid Goes Here */
  printf("visitSReturnVoid\n");


}

void Skeleton::visitSWhile(SWhile *swhile)
{
  /* Code For SWhile Goes Here */
  printf("visitSWhile\n");

  swhile->exp_->accept(this);
  swhile->stm_->accept(this);

}

void Skeleton::visitSBlock(SBlock *sblock)
{
  /* Code For SBlock Goes Here */
  printf("visitSBlock\n");

  sblock->liststm_->accept(this);

}

void Skeleton::visitSIfElse(SIfElse *sifelse)
{
  /* Code For SIfElse Goes Here */
  printf("visitSIfElse\n");

  sifelse->exp_->accept(this);
  sifelse->stm_1->accept(this);
  sifelse->stm_2->accept(this);

}

void Skeleton::visitETrue(ETrue *etrue)
{
  /* Code For ETrue Goes Here */
  printf("visitETrue\n");


}

void Skeleton::visitEFalse(EFalse *efalse)
{
  /* Code For EFalse Goes Here */
  printf("visitEFalse\n");


}

void Skeleton::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */
  printf("visitEInt\n");

  visitInteger(eint->integer_);

}

void Skeleton::visitEDouble(EDouble *edouble)
{
  /* Code For EDouble Goes Here */
  printf("visitEDouble\n");

  visitDouble(edouble->double_);

}

void Skeleton::visitEString(EString *estring)
{
  /* Code For EString Goes Here */
  printf("visitEString\n");

  visitString(estring->string_);

}

void Skeleton::visitEId(EId *eid)
{
  /* Code For EId Goes Here */
  printf("visitEId\n");

  visitId(eid->id_);

}

void Skeleton::visitEApp(EApp *eapp)
{
  /* Code For EApp Goes Here */
  printf("visitEApp\n");

  visitId(eapp->id_);
  eapp->listexp_->accept(this);

}

void Skeleton::visitEPIncr(EPIncr *epincr)
{
  /* Code For EPIncr Goes Here */
  printf("visitEPIncr\n");

  epincr->exp_->accept(this);

}

void Skeleton::visitEPDecr(EPDecr *epdecr)
{
  /* Code For EPDecr Goes Here */
  printf("visitEPDecr\n");

  epdecr->exp_->accept(this);

}

void Skeleton::visitEIncr(EIncr *eincr)
{
  /* Code For EIncr Goes Here */
  printf("visitEIncr\n");

  eincr->exp_->accept(this);

}

void Skeleton::visitEDecr(EDecr *edecr)
{
  /* Code For EDecr Goes Here */
  printf("visitEDecr\n");

  edecr->exp_->accept(this);

}

void Skeleton::visitETimes(ETimes *etimes)
{
  /* Code For ETimes Goes Here */
  printf("visitETimes\n");

  etimes->exp_1->accept(this);
  etimes->exp_2->accept(this);

}

void Skeleton::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */
  printf("visitEDiv\n");

  ediv->exp_1->accept(this);
  ediv->exp_2->accept(this);

}

void Skeleton::visitEPlus(EPlus *eplus)
{
  /* Code For EPlus Goes Here */
  printf("visitEPlus\n");

  eplus->exp_1->accept(this);
  eplus->exp_2->accept(this);

}

void Skeleton::visitEMinus(EMinus *eminus)
{
  /* Code For EMinus Goes Here */
  printf("visitEMinus\n");

  eminus->exp_1->accept(this);
  eminus->exp_2->accept(this);

}

void Skeleton::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */
  printf("visitELt\n");

  elt->exp_1->accept(this);
  elt->exp_2->accept(this);

}

void Skeleton::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */
  printf("visitEGt\n");

  egt->exp_1->accept(this);
  egt->exp_2->accept(this);

}

void Skeleton::visitELtEq(ELtEq *elteq)
{
  /* Code For ELtEq Goes Here */
  printf("visitELtEq\n");

  elteq->exp_1->accept(this);
  elteq->exp_2->accept(this);

}

void Skeleton::visitEGtEq(EGtEq *egteq)
{
  /* Code For EGtEq Goes Here */
  printf("visitEGtEq\n");

  egteq->exp_1->accept(this);
  egteq->exp_2->accept(this);

}

void Skeleton::visitEEq(EEq *eeq)
{
  /* Code For EEq Goes Here */
  printf("visitEEq\n");

  eeq->exp_1->accept(this);
  eeq->exp_2->accept(this);

}

void Skeleton::visitENEq(ENEq *eneq)
{
  /* Code For ENEq Goes Here */
  printf("visitENEq\n");

  eneq->exp_1->accept(this);
  eneq->exp_2->accept(this);

}

void Skeleton::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */
  printf("visitEAnd\n");

  eand->exp_1->accept(this);
  eand->exp_2->accept(this);

}

void Skeleton::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */
  printf("visitEOr\n");

  eor->exp_1->accept(this);
  eor->exp_2->accept(this);

}

void Skeleton::visitEAss(EAss *eass)
{
  /* Code For EAss Goes Here */
  printf("visitEAss\n");

  eass->exp_1->accept(this);
  eass->exp_2->accept(this);

}

void Skeleton::visitETyped(ETyped *etyped)
{
  /* Code For ETyped Goes Here */
  printf("visitETyped\n");

  etyped->exp_->accept(this);
  etyped->type_->accept(this);

}

void Skeleton::visitType_bool(Type_bool *type_bool)
{
  /* Code For Type_bool Goes Here */
  printf("visitType_bool\n");


}

void Skeleton::visitType_int(Type_int *type_int)
{
  /* Code For Type_int Goes Here */
  printf("visitType_int\n");


}

void Skeleton::visitType_double(Type_double *type_double)
{
  /* Code For Type_double Goes Here */
  printf("visitType_double\n");


}

void Skeleton::visitType_void(Type_void *type_void)
{
  /* Code For Type_void Goes Here */
  printf("visitType_void\n");


}

void Skeleton::visitType_string(Type_string *type_string)
{
  /* Code For Type_string Goes Here */
  printf("visitType_string\n");


}


void Skeleton::visitListDef(ListDef* listdef)
{
  printf("visitListDef\n");
  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListArg(ListArg* listarg)
{
  printf("visitListArg\n");
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStm(ListStm* liststm)
{
  printf("visitListStm\n");
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListExp(ListExp* listexp)
{
  printf("visitListExp\n");
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListId(ListId* listid)
{
  printf("visitListId\n");
  for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
  {
    visitId(*i) ;
  }
}


void Skeleton::visitId(Id x)
{
  /* Code for Id Goes Here */
  printf("visitId\n");
}

void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
  printf("visitIneteger\n");
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
  printf("visitChar\n");
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
  printf("visitDouble\n");
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
  printf("visitString\n");
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
  printf("visitIdent\n");
}



