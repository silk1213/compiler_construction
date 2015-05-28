#include "Absyn.H"
#include <iostream>
#include <map>
#include <iterator>
#include <utility>
#include <list>

class Env {
	public:
		typedef std::map<Id,Type*> variableTypeMap;
		typedef std::map<Id,std::pair<ListArg*,Type*> > functionTypeMap;

		variableTypeMap variable_env;
		functionTypeMap function_env;

		void updateVar(Id id ,Type* type) {
			variable_env.insert (std::pair<Id,Type*>(id,type));
			printVariableMap(variable_env);
		}

		void updateFun(Id id ,ListArg* inputList, Type* output) {
			function_env.insert (std::pair<Id,std::pair<ListArg*,Type*> >(id,std::make_pair(inputList,output)));
			printFunctionMap(function_env);
		}

		Type* lookupVar(Id id) {
			std::map<Id,Type* >::iterator it = variable_env.find(id);
			if (it != variable_env.end()) {
				return it->second;
			}
			// ... else error handling
		}

		std::pair<ListArg*,Type*> lookupFun(Id id) {
			functionTypeMap::iterator it = function_env.find(id);
			if (it != function_env.end()) {
				return it->second;
			}
			// ... else error handling
		}

		std::string lookupVariable (Id id) {
			std::string type = lookupVar(id)->getType();
			return type;
		}

		void printVariableMap(variableTypeMap map){
			typedef std::map<Id,Type*>::iterator it_variable;
			for(it_variable iterator = map.begin(); iterator != map.end(); iterator++){
				std::cout<<"Key:"<<iterator->first<< std::endl;
				std::cout<<"Value:"<< iterator->second->getType() << std::endl;	
				//iterator->second->printType();
				std::cout << std::endl;		
			} 		
		}

		void printFunctionMap(functionTypeMap map){
			typedef functionTypeMap::iterator it_function;
			for(it_function iterator = map.begin(); iterator != map.end(); iterator++){
				std::cout<<"Key:"<<iterator->first<< std::endl;
				std::cout<<"Input Arguments:"<< std::endl;

				ListArg* inputTypes = iterator->second.first;
				Type* outputType = iterator->second.second;
				ListArg::iterator it;
				for (it = inputTypes->begin(); it != inputTypes->end(); ++it) {
					std::cout << *it->getType() << std::endl;				
				}
				std::cout<<"Output Type:"<< outputType->getType() << std::endl;	
				//iterator->second->printType();
				std::cout << std::endl;		
			} 		
		}
};
