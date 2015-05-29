#include "Absyn.H"
#include <iostream>
#include <map>
#include <iterator>
#include <utility>
#include <list>

typedef std::map<Id,Type*> variableTypeMap;
typedef std::map<Id,std::pair<ListArg*,Type*> > functionTypeMap;

class LinkedVariableTypeMap {
	public: 
		//Map für Variabeln
		variableTypeMap* env_;

		//Zeiger auf nächste Map
		LinkedVariableTypeMap* next;

		//Zeiger auf vorherige Map
		LinkedVariableTypeMap* prev;

		//Konstruktor mit anhängen an bestehende Liste
		LinkedVariableTypeMap(LinkedVariableTypeMap* list) {
			env_ = new variableTypeMap();
			next = list;
			prev = NULL;
		}

		//Konstruktor
		LinkedVariableTypeMap() {
			env_ = new variableTypeMap();
			next = NULL;
			prev = NULL;
		}

		//Destruktor
		~LinkedVariableTypeMap() {
			next = NULL;
			prev = NULL;
			delete(env_);
		}
};

class Env {
	private:
		LinkedVariableTypeMap* list_variable_env;
		int var_env_size;
		functionTypeMap function_env;
	

	public:
		//Konstruktor (erstellt Liste mit erster Map)
		Env() {
			var_env_size = 0;
		}

		//Destruktor
		~Env() {
			for (int i = 0; i < var_env_size; i++) {
				deleteEnv();
			}
		}

		//fügt neue Map an erste Position der Liste hinzu
		void addEnv() {
			LinkedVariableTypeMap* temp = new LinkedVariableTypeMap(list_variable_env);
			list_variable_env->prev = temp;
			list_variable_env = temp;	
			var_env_size++;	
		}

		//entfernt erstes Element der Liste
		void deleteEnv() {
			LinkedVariableTypeMap* temp = list_variable_env->next;
			delete list_variable_env;
			temp->prev = NULL;
			list_variable_env = temp;
			var_env_size--;
		}
		
		//fügt neue Variable in aktuelle(erste) VariabelMap
		void updateVar(Id id ,Type* type) {
			list_variable_env->env_->insert (std::pair<Id,Type*>(id,type));
			printAllVariableMaps(list_variable_env);
		}

		//fügt Funktion der FunktionMap hinzu
		void updateFun(Id id ,ListArg* inputList, Type* output) {
			function_env.insert (std::pair<Id,std::pair<ListArg*,Type*> >(id,std::make_pair(inputList,output)));
			printFunctionMap(function_env);
			addEnv();
			ListArg::iterator it;
				for (it = inputList->begin(); it != inputList->end(); ++it) {
					updateVar((*it)->getId(), (*it)->getType());				
				}
			
		}

		Type* lookupVar(Id id) {
			LinkedVariableTypeMap* temp = list_variable_env;
			variableTypeMap::iterator map_iter;
			for (int i = 0; i < var_env_size; i++) {
				map_iter = temp->env_->find(id);

				if (map_iter != temp->env_->end()) {
					return map_iter->second;
				} else {
					temp = temp->next;
				}
			}
			return NULL;
		}

		/*Type* lookupVar(Id id) {
			for(std::list<variableTypeMap>::iterator list_it = list_variable_env.end(); list_it != list_variable_env.begin(); list_it--){
				variableTypeMap::iterator map_it = list_it->find(id);

				if (it != *iterator.end()) {
					return it->second;
				}
			}
			// ... else error handling
		}*/

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

		void printAllVariableMaps(LinkedVariableTypeMap* list) {
			LinkedVariableTypeMap* temp = list;
			for (int i = 0; i < var_env_size; i++) {
				std::cout << i << ". map" << std::endl;
				printVariableMap(temp->env_);
				temp = temp->next;
			}
		}

		void printVariableMap(variableTypeMap* map){
			for(std::map<Id,Type*>::iterator iterator = map->begin(); iterator != map->end(); iterator++){
				std::cout<<"Key:"<<iterator->first<< std::endl;
				std::cout<<"Type:"<< iterator->second->getType() << std::endl;	
				//iterator->second->printType();
				std::cout << std::endl;		
			} 		
		}

		void printFunctionMap(functionTypeMap map){
			for(functionTypeMap::iterator iterator = map.begin(); iterator != map.end(); iterator++){
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
