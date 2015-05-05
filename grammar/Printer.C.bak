/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include <string>
#include "Printer.H"


//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + 2;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == '}')
  {
     _n_ = _n_ - 2;
     backup();
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(c);
     bufAppend(' ');
  }
}
void PrintAbsyn::render(String s_)
{
  const char *s = s_.c_str() ;
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}
void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char* PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}
void PrintAbsyn::visitProgram(Program*p) {} //abstract class

void PrintAbsyn::visitProg(Prog* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listdefinition_) {_i_ = 0; p->listdefinition_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefinition(Definition*p) {} //abstract class

void PrintAbsyn::visitFunctionDefIn(FunctionDefIn* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("inline");
  _i_ = 0; p->type_->accept(this);
  _i_ = 0; p->id_->accept(this);
  _i_ = 0; p->argumentlist_->accept(this);
  _i_ = 0; p->body_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitFunctionDef(FunctionDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  _i_ = 0; p->id_->accept(this);
  _i_ = 0; p->argumentlist_->accept(this);
  _i_ = 0; p->body_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitFunction(Function* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  _i_ = 0; p->id_->accept(this);
  _i_ = 0; p->argumentlist_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitGlobVar(GlobVar* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->decl_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitGlobStruct(GlobStruct* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->struct_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitGlobTypeDef(GlobTypeDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->typedef_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitUsingNSDef(UsingNSDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("using");
  render("namespace");
  _i_ = 0; p->id_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitUsingDef(UsingDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("using");
  _i_ = 0; p->qcon_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListDefinition(ListDefinition *listdefinition)
{
  for (ListDefinition::const_iterator i = listdefinition->begin() ; i != listdefinition->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}

void PrintAbsyn::visitArgumentList(ArgumentList*p) {} //abstract class

void PrintAbsyn::visitArgumentListDef(ArgumentListDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('(');
  if(p->listargument_) {_i_ = 0; p->listargument_->accept(this);}  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListArgument(ListArgument *listargument)
{
  for (ListArgument::const_iterator i = listargument->begin() ; i != listargument->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listargument->end() - 1) render(',');
  }
}

void PrintAbsyn::visitArgument(Argument*p) {} //abstract class

void PrintAbsyn::visitArgumentConstDecl(ArgumentConstDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("const");
  _i_ = 0; p->type_->accept(this);
  _i_ = 0; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitArgumentDecl(ArgumentDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  _i_ = 0; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitArgumentConsttype(ArgumentConsttype* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("const");
  _i_ = 0; p->type_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitArgumentType(ArgumentType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBody(Body*p) {} //abstract class

void PrintAbsyn::visitFuntionBody(FuntionBody* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  if(p->liststm_) {_i_ = 0; p->liststm_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEmptyBody(EmptyBody* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  render(';');
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStm(Stm*p) {} //abstract class

void PrintAbsyn::visitStmDecl(StmDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->decl_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmReturn(StmReturn* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("return");
  _i_ = 0; p->exp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmExit(StmExit* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("exit");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmWhile(StmWhile* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("while");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmDoWhile(StmDoWhile* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("do");
  _i_ = 0; p->stm_->accept(this);
  render("while");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmFor(StmFor* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("for");
  render('(');
  _i_ = 0; p->decl_->accept(this);
  render(';');
  _i_ = 0; p->exp_1->accept(this);
  render(';');
  _i_ = 0; p->exp_2->accept(this);
  render(')');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmIfElse(StmIfElse* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->stm_1->accept(this);
  render("else");
  _i_ = 0; p->stm_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmIf(StmIf* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmBlock(StmBlock* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  if(p->liststm_) {_i_ = 0; p->liststm_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmEmptyBlock(StmEmptyBlock* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmTypeDef(StmTypeDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->typedef_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmeStruct(StmeStruct* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->struct_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStmExpression(StmExpression* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->exp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStm(ListStm *liststm)
{
  for (ListStm::const_iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}

void PrintAbsyn::visitStruct(Struct*p) {} //abstract class

void PrintAbsyn::visitStructDef(StructDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("struct");
  _i_ = 0; p->id_->accept(this);
  render('{');
  if(p->listdecl_) {_i_ = 0; p->listdecl_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTypeDef(TypeDef*p) {} //abstract class

void PrintAbsyn::visitTypeDefForm(TypeDefForm* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("typedef");
  _i_ = 0; p->type_->accept(this);
  _i_ = 0; p->id_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTypeDefForm2(TypeDefForm2* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("typedef");
  _i_ = 0; p->type_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDecl(Decl*p) {} //abstract class

void PrintAbsyn::visitConstDecl(ConstDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("const");
  _i_ = 0; p->type_->accept(this);
  if(p->listvar_) {_i_ = 0; p->listvar_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDeclaration(Declaration* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  if(p->listvar_) {_i_ = 0; p->listvar_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitVar(Var*p) {} //abstract class

void PrintAbsyn::visitVariableInitialization(VariableInitialization* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->id_->accept(this);
  render('=');
  _i_ = 0; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitVariableName(VariableName* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->id_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListVar(ListVar *listvar)
{
  for (ListVar::const_iterator i = listvar->begin() ; i != listvar->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listvar->end() - 1) render(',');
  }
}

void PrintAbsyn::visitListDecl(ListDecl *listdecl)
{
  for (ListDecl::const_iterator i = listdecl->begin() ; i != listdecl->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdecl->end() - 1) render(';');
  }
}

void PrintAbsyn::visitQCon(QCon*p) {} //abstract class

void PrintAbsyn::visitQualCon(QualCon* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->qcon_->accept(this);
  render("::");
  _i_ = 0; p->name_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitQualConN(QualConN* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->name_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitName(Name*p) {} //abstract class

void PrintAbsyn::visitIdName(IdName* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->id_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTempInstName(TempInstName* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->tempinst_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExp(Exp*p) {} //abstract class

void PrintAbsyn::visitEIdent(EIdent* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  _i_ = 0; p->id_->accept(this);

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELiteral(ELiteral* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  _i_ = 0; p->literal_->accept(this);

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEBracket(EBracket* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEIndex(EIndex* p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  _i_ = 15; p->exp_1->accept(this);
  render('[');
  _i_ = 0; p->exp_2->accept(this);
  render(']');

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEQCon(EQCon* p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  _i_ = 0; p->qcon_->accept(this);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEFunCall(EFunCall* p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  _i_ = 15; p->exp_->accept(this);
  render('(');
  if(p->listexp_) {_i_ = 0; p->listexp_->accept(this);}  render(')');

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEStrucProj(EStrucProj* p)
{
  int oldi = _i_;
  if (oldi > 14) render(_L_PAREN);

  _i_ = 15; p->exp_1->accept(this);
  render('.');
  _i_ = 15; p->exp_2->accept(this);

  if (oldi > 14) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEStrucPro(EStrucPro* p)
{
  int oldi = _i_;
  if (oldi > 14) render(_L_PAREN);

  _i_ = 15; p->exp_1->accept(this);
  render("->");
  _i_ = 15; p->exp_2->accept(this);

  if (oldi > 14) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEInC(EInC* p)
{
  int oldi = _i_;
  if (oldi > 14) render(_L_PAREN);

  _i_ = 15; p->exp_->accept(this);
  render("++");

  if (oldi > 14) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDeC(EDeC* p)
{
  int oldi = _i_;
  if (oldi > 14) render(_L_PAREN);

  _i_ = 15; p->exp_->accept(this);
  render("--");

  if (oldi > 14) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDeRef(EDeRef* p)
{
  int oldi = _i_;
  if (oldi > 14) render(_L_PAREN);

  render('*');
  _i_ = 15; p->exp_->accept(this);

  if (oldi > 14) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEInCr(EInCr* p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  render("++");
  _i_ = 14; p->exp_->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDeCr(EDeCr* p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  render("--");
  _i_ = 14; p->exp_->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENeg(ENeg* p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  render('!');
  _i_ = 14; p->exp_->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEMul(EMul* p)
{
  int oldi = _i_;
  if (oldi > 12) render(_L_PAREN);

  _i_ = 12; p->exp_1->accept(this);
  render('*');
  _i_ = 13; p->exp_2->accept(this);

  if (oldi > 12) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDiv(EDiv* p)
{
  int oldi = _i_;
  if (oldi > 12) render(_L_PAREN);

  _i_ = 12; p->exp_1->accept(this);
  render('/');
  _i_ = 13; p->exp_2->accept(this);

  if (oldi > 12) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitERem(ERem* p)
{
  int oldi = _i_;
  if (oldi > 12) render(_L_PAREN);

  _i_ = 12; p->exp_1->accept(this);
  render('%');
  _i_ = 13; p->exp_2->accept(this);

  if (oldi > 12) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAdd(EAdd* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  _i_ = 11; p->exp_1->accept(this);
  render('+');
  _i_ = 12; p->exp_2->accept(this);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitESub(ESub* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  _i_ = 11; p->exp_1->accept(this);
  render('-');
  _i_ = 12; p->exp_2->accept(this);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELSh(ELSh* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  _i_ = 10; p->exp_1->accept(this);
  render("<<");
  _i_ = 11; p->exp_2->accept(this);

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitERSh(ERSh* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  _i_ = 10; p->exp_1->accept(this);
  render(">>");
  _i_ = 11; p->exp_2->accept(this);

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEGT(EGT* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render('>');
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELT(ELT* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render('<');
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEGQ(EGQ* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render("=>");
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEGQ1(EGQ1* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render(">=");
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELQ(ELQ* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render("<=");
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELQ1(ELQ1* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render("=<");
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEQu(EQu* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->exp_1->accept(this);
  render("==");
  _i_ = 9; p->exp_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEIQ(EIQ* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->exp_1->accept(this);
  render("!=");
  _i_ = 9; p->exp_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAnd(EAnd* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 4; p->exp_1->accept(this);
  render("&&");
  _i_ = 5; p->exp_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEOr(EOr* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->exp_1->accept(this);
  render("||");
  _i_ = 4; p->exp_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEIs(EIs* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 2; p->exp_1->accept(this);
  render('=');
  _i_ = 3; p->exp_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEIsP(EIsP* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 2; p->exp_1->accept(this);
  render("+=");
  _i_ = 3; p->exp_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEIsM(EIsM* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 2; p->exp_1->accept(this);
  render("-=");
  _i_ = 3; p->exp_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitECond(ECond* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 2; p->exp_1->accept(this);
  render('?');
  _i_ = 3; p->exp_2->accept(this);
  render(':');
  _i_ = 3; p->exp_3->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEEx(EEx* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  render("throw");
  _i_ = 2; p->exp_->accept(this);

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListExp(ListExp *listexp)
{
  for (ListExp::const_iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexp->end() - 1) render(',');
  }
}

void PrintAbsyn::visitTempInst(TempInst*p) {} //abstract class

void PrintAbsyn::visitTemplateInst(TemplateInst* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->id_->accept(this);
  render('<');
  _i_ = 0; p->typelist_->accept(this);
  render('>');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTypeList(TypeList*p) {} //abstract class

void PrintAbsyn::visitTypeListDef(TypeListDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listtype_) {_i_ = 0; p->listtype_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListType(ListType *listtype)
{
  for (ListType::const_iterator i = listtype->begin() ; i != listtype->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listtype->end() - 1) render(',');
  }
}

void PrintAbsyn::visitType(Type*p) {} //abstract class

void PrintAbsyn::visitPointer(Pointer* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->btype_->accept(this);
  render('*');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitReference(Reference* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->btype_->accept(this);
  render('&');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBaseType(BaseType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->btype_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBType(BType*p) {} //abstract class

void PrintAbsyn::visitTQCon(TQCon* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->qcon_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTInt(TInt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("int");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTVoid(TVoid* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("void");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTBool(TBool* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("bool");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTDouble(TDouble* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("double");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLiteral(Literal*p) {} //abstract class

void PrintAbsyn::visitLStringList(LStringList* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->stringlist_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLInt(LInt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLDouble(LDouble* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitDouble(p->double_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLChar(LChar* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitChar(p->char_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStringList(StringList*p) {} //abstract class

void PrintAbsyn::visitLStringListDef(LStringListDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->stringlist_->accept(this);
  visitString(p->string_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLString(LString* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitString(p->string_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitId(Id*p) {} //abstract class

void PrintAbsyn::visitIdentif(Identif* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void PrintAbsyn::visitString(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void PrintAbsyn::visitIdent(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}

ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char* ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}
void ShowAbsyn::visitProgram(Program* p) {} //abstract class

void ShowAbsyn::visitProg(Prog* p)
{
  bufAppend('(');
  bufAppend("Prog");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdefinition_)  p->listdefinition_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDefinition(Definition* p) {} //abstract class

void ShowAbsyn::visitFunctionDefIn(FunctionDefIn* p)
{
  bufAppend('(');
  bufAppend("FunctionDefIn");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->argumentlist_)  p->argumentlist_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->body_)  p->body_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitFunctionDef(FunctionDef* p)
{
  bufAppend('(');
  bufAppend("FunctionDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->argumentlist_)  p->argumentlist_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->body_)  p->body_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitFunction(Function* p)
{
  bufAppend('(');
  bufAppend("Function");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->argumentlist_)  p->argumentlist_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitGlobVar(GlobVar* p)
{
  bufAppend('(');
  bufAppend("GlobVar");
  bufAppend(' ');
  bufAppend('[');
  if (p->decl_)  p->decl_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitGlobStruct(GlobStruct* p)
{
  bufAppend('(');
  bufAppend("GlobStruct");
  bufAppend(' ');
  bufAppend('[');
  if (p->struct_)  p->struct_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitGlobTypeDef(GlobTypeDef* p)
{
  bufAppend('(');
  bufAppend("GlobTypeDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->typedef_)  p->typedef_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitUsingNSDef(UsingNSDef* p)
{
  bufAppend('(');
  bufAppend("UsingNSDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitUsingDef(UsingDef* p)
{
  bufAppend('(');
  bufAppend("UsingDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->qcon_)  p->qcon_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListDefinition(ListDefinition *listdefinition)
{
  for (ListDefinition::const_iterator i = listdefinition->begin() ; i != listdefinition->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdefinition->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitArgumentList(ArgumentList* p) {} //abstract class

void ShowAbsyn::visitArgumentListDef(ArgumentListDef* p)
{
  bufAppend('(');
  bufAppend("ArgumentListDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->listargument_)  p->listargument_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListArgument(ListArgument *listargument)
{
  for (ListArgument::const_iterator i = listargument->begin() ; i != listargument->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listargument->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitArgument(Argument* p) {} //abstract class

void ShowAbsyn::visitArgumentConstDecl(ArgumentConstDecl* p)
{
  bufAppend('(');
  bufAppend("ArgumentConstDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitArgumentDecl(ArgumentDecl* p)
{
  bufAppend('(');
  bufAppend("ArgumentDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitArgumentConsttype(ArgumentConsttype* p)
{
  bufAppend('(');
  bufAppend("ArgumentConsttype");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitArgumentType(ArgumentType* p)
{
  bufAppend('(');
  bufAppend("ArgumentType");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitBody(Body* p) {} //abstract class

void ShowAbsyn::visitFuntionBody(FuntionBody* p)
{
  bufAppend('(');
  bufAppend("FuntionBody");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststm_)  p->liststm_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEmptyBody(EmptyBody* p)
{
  bufAppend("EmptyBody");
}
void ShowAbsyn::visitStm(Stm* p) {} //abstract class

void ShowAbsyn::visitStmDecl(StmDecl* p)
{
  bufAppend('(');
  bufAppend("StmDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->decl_)  p->decl_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmReturn(StmReturn* p)
{
  bufAppend('(');
  bufAppend("StmReturn");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmExit(StmExit* p)
{
  bufAppend('(');
  bufAppend("StmExit");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmWhile(StmWhile* p)
{
  bufAppend('(');
  bufAppend("StmWhile");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStmDoWhile(StmDoWhile* p)
{
  bufAppend('(');
  bufAppend("StmDoWhile");
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmFor(StmFor* p)
{
  bufAppend('(');
  bufAppend("StmFor");
  bufAppend(' ');
  bufAppend('[');
  if (p->decl_)  p->decl_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStmIfElse(StmIfElse* p)
{
  bufAppend('(');
  bufAppend("StmIfElse");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->stm_1->accept(this);
  bufAppend(' ');
  p->stm_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitStmIf(StmIf* p)
{
  bufAppend('(');
  bufAppend("StmIf");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStmBlock(StmBlock* p)
{
  bufAppend('(');
  bufAppend("StmBlock");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststm_)  p->liststm_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmEmptyBlock(StmEmptyBlock* p)
{
  bufAppend("StmEmptyBlock");
}
void ShowAbsyn::visitStmTypeDef(StmTypeDef* p)
{
  bufAppend('(');
  bufAppend("StmTypeDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->typedef_)  p->typedef_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStmeStruct(StmeStruct* p)
{
  bufAppend('(');
  bufAppend("StmeStruct");
  bufAppend(' ');
  bufAppend('[');
  if (p->struct_)  p->struct_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStmExpression(StmExpression* p)
{
  bufAppend('(');
  bufAppend("StmExpression");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListStm(ListStm *liststm)
{
  for (ListStm::const_iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststm->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitStruct(Struct* p) {} //abstract class

void ShowAbsyn::visitStructDef(StructDef* p)
{
  bufAppend('(');
  bufAppend("StructDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listdecl_)  p->listdecl_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitTypeDef(TypeDef* p) {} //abstract class

void ShowAbsyn::visitTypeDefForm(TypeDefForm* p)
{
  bufAppend('(');
  bufAppend("TypeDefForm");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitTypeDefForm2(TypeDefForm2* p)
{
  bufAppend('(');
  bufAppend("TypeDefForm2");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDecl(Decl* p) {} //abstract class

void ShowAbsyn::visitConstDecl(ConstDecl* p)
{
  bufAppend('(');
  bufAppend("ConstDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listvar_)  p->listvar_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDeclaration(Declaration* p)
{
  bufAppend('(');
  bufAppend("Declaration");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listvar_)  p->listvar_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitVar(Var* p) {} //abstract class

void ShowAbsyn::visitVariableInitialization(VariableInitialization* p)
{
  bufAppend('(');
  bufAppend("VariableInitialization");
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitVariableName(VariableName* p)
{
  bufAppend('(');
  bufAppend("VariableName");
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListVar(ListVar *listvar)
{
  for (ListVar::const_iterator i = listvar->begin() ; i != listvar->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listvar->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitListDecl(ListDecl *listdecl)
{
  for (ListDecl::const_iterator i = listdecl->begin() ; i != listdecl->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdecl->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitQCon(QCon* p) {} //abstract class

void ShowAbsyn::visitQualCon(QualCon* p)
{
  bufAppend('(');
  bufAppend("QualCon");
  bufAppend(' ');
  bufAppend('[');
  if (p->qcon_)  p->qcon_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->name_)  p->name_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitQualConN(QualConN* p)
{
  bufAppend('(');
  bufAppend("QualConN");
  bufAppend(' ');
  bufAppend('[');
  if (p->name_)  p->name_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitName(Name* p) {} //abstract class

void ShowAbsyn::visitIdName(IdName* p)
{
  bufAppend('(');
  bufAppend("IdName");
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTempInstName(TempInstName* p)
{
  bufAppend('(');
  bufAppend("TempInstName");
  bufAppend(' ');
  bufAppend('[');
  if (p->tempinst_)  p->tempinst_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitExp(Exp* p) {} //abstract class

void ShowAbsyn::visitEIdent(EIdent* p)
{
  bufAppend('(');
  bufAppend("EIdent");
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitELiteral(ELiteral* p)
{
  bufAppend('(');
  bufAppend("ELiteral");
  bufAppend(' ');
  bufAppend('[');
  if (p->literal_)  p->literal_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEBracket(EBracket* p)
{
  bufAppend('(');
  bufAppend("EBracket");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEIndex(EIndex* p)
{
  bufAppend('(');
  bufAppend("EIndex");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEQCon(EQCon* p)
{
  bufAppend('(');
  bufAppend("EQCon");
  bufAppend(' ');
  bufAppend('[');
  if (p->qcon_)  p->qcon_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEFunCall(EFunCall* p)
{
  bufAppend('(');
  bufAppend("EFunCall");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listexp_)  p->listexp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEStrucProj(EStrucProj* p)
{
  bufAppend('(');
  bufAppend("EStrucProj");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEStrucPro(EStrucPro* p)
{
  bufAppend('(');
  bufAppend("EStrucPro");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEInC(EInC* p)
{
  bufAppend('(');
  bufAppend("EInC");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEDeC(EDeC* p)
{
  bufAppend('(');
  bufAppend("EDeC");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEDeRef(EDeRef* p)
{
  bufAppend('(');
  bufAppend("EDeRef");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEInCr(EInCr* p)
{
  bufAppend('(');
  bufAppend("EInCr");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEDeCr(EDeCr* p)
{
  bufAppend('(');
  bufAppend("EDeCr");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitENeg(ENeg* p)
{
  bufAppend('(');
  bufAppend("ENeg");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEMul(EMul* p)
{
  bufAppend('(');
  bufAppend("EMul");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEDiv(EDiv* p)
{
  bufAppend('(');
  bufAppend("EDiv");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitERem(ERem* p)
{
  bufAppend('(');
  bufAppend("ERem");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEAdd(EAdd* p)
{
  bufAppend('(');
  bufAppend("EAdd");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitESub(ESub* p)
{
  bufAppend('(');
  bufAppend("ESub");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELSh(ELSh* p)
{
  bufAppend('(');
  bufAppend("ELSh");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitERSh(ERSh* p)
{
  bufAppend('(');
  bufAppend("ERSh");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEGT(EGT* p)
{
  bufAppend('(');
  bufAppend("EGT");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELT(ELT* p)
{
  bufAppend('(');
  bufAppend("ELT");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEGQ(EGQ* p)
{
  bufAppend('(');
  bufAppend("EGQ");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEGQ1(EGQ1* p)
{
  bufAppend('(');
  bufAppend("EGQ1");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELQ(ELQ* p)
{
  bufAppend('(');
  bufAppend("ELQ");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELQ1(ELQ1* p)
{
  bufAppend('(');
  bufAppend("ELQ1");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEQu(EQu* p)
{
  bufAppend('(');
  bufAppend("EQu");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEIQ(EIQ* p)
{
  bufAppend('(');
  bufAppend("EIQ");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEAnd(EAnd* p)
{
  bufAppend('(');
  bufAppend("EAnd");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEOr(EOr* p)
{
  bufAppend('(');
  bufAppend("EOr");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEIs(EIs* p)
{
  bufAppend('(');
  bufAppend("EIs");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEIsP(EIsP* p)
{
  bufAppend('(');
  bufAppend("EIsP");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEIsM(EIsM* p)
{
  bufAppend('(');
  bufAppend("EIsM");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitECond(ECond* p)
{
  bufAppend('(');
  bufAppend("ECond");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  p->exp_3->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEEx(EEx* p)
{
  bufAppend('(');
  bufAppend("EEx");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListExp(ListExp *listexp)
{
  for (ListExp::const_iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexp->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitTempInst(TempInst* p) {} //abstract class

void ShowAbsyn::visitTemplateInst(TemplateInst* p)
{
  bufAppend('(');
  bufAppend("TemplateInst");
  bufAppend(' ');
  bufAppend('[');
  if (p->id_)  p->id_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->typelist_)  p->typelist_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitTypeList(TypeList* p) {} //abstract class

void ShowAbsyn::visitTypeListDef(TypeListDef* p)
{
  bufAppend('(');
  bufAppend("TypeListDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->listtype_)  p->listtype_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListType(ListType *listtype)
{
  for (ListType::const_iterator i = listtype->begin() ; i != listtype->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listtype->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitType(Type* p) {} //abstract class

void ShowAbsyn::visitPointer(Pointer* p)
{
  bufAppend('(');
  bufAppend("Pointer");
  bufAppend(' ');
  bufAppend('[');
  if (p->btype_)  p->btype_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitReference(Reference* p)
{
  bufAppend('(');
  bufAppend("Reference");
  bufAppend(' ');
  bufAppend('[');
  if (p->btype_)  p->btype_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitBaseType(BaseType* p)
{
  bufAppend('(');
  bufAppend("BaseType");
  bufAppend(' ');
  bufAppend('[');
  if (p->btype_)  p->btype_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitBType(BType* p) {} //abstract class

void ShowAbsyn::visitTQCon(TQCon* p)
{
  bufAppend('(');
  bufAppend("TQCon");
  bufAppend(' ');
  bufAppend('[');
  if (p->qcon_)  p->qcon_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTInt(TInt* p)
{
  bufAppend("TInt");
}
void ShowAbsyn::visitTVoid(TVoid* p)
{
  bufAppend("TVoid");
}
void ShowAbsyn::visitTBool(TBool* p)
{
  bufAppend("TBool");
}
void ShowAbsyn::visitTDouble(TDouble* p)
{
  bufAppend("TDouble");
}
void ShowAbsyn::visitLiteral(Literal* p) {} //abstract class

void ShowAbsyn::visitLStringList(LStringList* p)
{
  bufAppend('(');
  bufAppend("LStringList");
  bufAppend(' ');
  bufAppend('[');
  if (p->stringlist_)  p->stringlist_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitLInt(LInt* p)
{
  bufAppend('(');
  bufAppend("LInt");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitLDouble(LDouble* p)
{
  bufAppend('(');
  bufAppend("LDouble");
  bufAppend(' ');
  visitDouble(p->double_);
  bufAppend(')');
}
void ShowAbsyn::visitLChar(LChar* p)
{
  bufAppend('(');
  bufAppend("LChar");
  bufAppend(' ');
  visitChar(p->char_);
  bufAppend(')');
}
void ShowAbsyn::visitStringList(StringList* p) {} //abstract class

void ShowAbsyn::visitLStringListDef(LStringListDef* p)
{
  bufAppend('(');
  bufAppend("LStringListDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->stringlist_)  p->stringlist_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitLString(LString* p)
{
  bufAppend('(');
  bufAppend("LString");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitId(Id* p) {} //abstract class

void ShowAbsyn::visitIdentif(Identif* p)
{
  bufAppend('(');
  bufAppend("Identif");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void ShowAbsyn::visitString(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void ShowAbsyn::visitIdent(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


