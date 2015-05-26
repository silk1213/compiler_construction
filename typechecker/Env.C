#include "Absyn.H"
#include <iostream>
#include <map>
#include <iterator>
#include <utility>
#include <list>

class Env {
	public:
		typedef std::map<Id,Type*> variableTypeMap;
		typedef std::map<Id,std::pair<std::list<Type*>,Type*> > functionTypeMap;

		variableTypeMap variable_env;
		functionTypeMap function_env;

		void updateVar(Id id ,Type* type) {
			variable_env.insert (std::pair<Id,Type*>(id,type));
			printVariableMap(variable_env);
		}

		void updateFun(Id id ,std::list<Type*> inputList, Type* output) {
			function_env.insert (std::pair<Id,std::pair<std::list<Type*>,Type*> >(id,std::make_pair(inputList,output)));
		}

		Type* lookup(Id id) {
			std::map<Id,Type* >::iterator it = variable_env.find(id);
			if (it != variable_env.end()) {
				return it->second;
			}
			// ... else error handling
		}

		void printVariableMap(variableTypeMap map){
			typedef std::map<Id,Type*>::iterator it_variable;
			for(it_variable iterator = map.begin(); iterator != map.end(); iterator++){
				std::cout<<"Key:"<<iterator->first<< std::endl;
				std::cout<<"Value:"<<iterator->second<< std::endl;			
			} 		
		}
};
