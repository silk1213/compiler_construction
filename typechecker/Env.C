#include "Absyn.H"
#include <iostream>
#include <map>
#include <iterator>
#include <utility>

class Env {
	public:
		typedef std::map<Id,Type*> valueTypeMap;

		valueTypeMap simple_env ;

		void updateVar(Id id ,Type* ty) {
			simple_env.insert (std::pair<Id,Type*>(id,ty));
		}

		Type* lookup(Id id) {
			std::map<Id,Type* >::iterator it = simple_env.find(id);
			if (it != simple_env.end()) {
				return it->second;
			}
			// ... else error handling
		}
};
