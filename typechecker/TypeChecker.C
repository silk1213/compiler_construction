#include "TypeChecker.H"

TypeChecker::~TypeChecker() {}
Type* TypeChecker::typecheck (Visitable* v) {
	v->accept (this);
	return ty_;
}
