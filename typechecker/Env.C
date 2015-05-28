#include "Absyn.H"
#include <iostream>
#include <map>
#include <iterator>
#include <utility>
#include <list>

typedef std::map<Id,Type*> variableTypeMap;
typedef std::map<Id,std::pair<ListArg*,Type*> > functionTypeMap;

class Env {
	private:
		std::list<variableTypeMap> list_variable_env;
		functionTypeMap function_env;
		variableTypeMap varMap;

	public:
		void addEnv() {
			list_variable_env.push_back();		
		}

		void deleteEnv() {
			list_variable_env.pop_back();
		}
		
		void updateVar(Id id ,Type* type) {
			list_variable_env.back().insert (std::pair<Id,Type*>(id,type));
			printVariableMap(list_variable_env);
		}

		void updateFun(Id id ,ListArg* inputList, Type* output) {
			function_env.insert (std::pair<Id,std::pair<ListArg*,Type*> >(id,std::make_pair(inputList,output)));
			printFunctionMap(function_env);
		}

		Type* lookupVar(Id id) {
			typedef std::list<variableTypeMap>::iterator it_variable;
			for(it_variable iterator = list_variable_env.end(); iterator != list_variable_env.begin(); iterator--){
				std::map<Id,Type* >::iterator it = *iterator.find(id);

				if (it != *iterator.end()) {
					return it->second;
				}
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
					std::cout << "Id:" << (*it)->getId() << "\t Type:" << (*it)->getType()->getType() << std::endl;				
				}
				std::cout<<"Output Type:"<< outputType->getType() << std::endl;	
				//iterator->second->printType();
				std::cout << std::endl;		
			} 		
		}
};
