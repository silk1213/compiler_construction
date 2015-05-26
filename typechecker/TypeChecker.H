#include "Env.C"

class TypeChecker : public Visitor
{
	public :
		~TypeChecker ( ) ;
		Type* typecheck ( Visitable* v ) ;
	private :
		Type* ty_ ;
	
	//class Env;
	Env env_ ;
} ;
