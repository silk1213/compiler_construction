#include "Env.H"

		//Konstruktor mit anhängen an bestehende Liste
		LinkedVariableTypeMap::LinkedVariableTypeMap(LinkedVariableTypeMap* list) {
			env_ = new variableTypeMap();
			next = list;
		}

		//Konstruktor
		LinkedVariableTypeMap::LinkedVariableTypeMap() {
			env_ = new variableTypeMap();
			next = NULL;
		}

		//Destruktor
		LinkedVariableTypeMap::~LinkedVariableTypeMap() {
			next = NULL;
			env_->erase(env_->begin(), env_->end());
			env_ = NULL;
		}


		//Konstruktor (erstellt Liste mit erster Map)
		Env::Env() {
			var_env_size = 1;
			list_variable_env = new LinkedVariableTypeMap();
		}

		//Destruktor
		Env::~Env() {
			while (var_env_size > 0) {
				deleteEnv();
			}
		}

		//fügt neue Map an erste Position der Liste hinzu
		void Env::addEnv() {
			LinkedVariableTypeMap* temp = new LinkedVariableTypeMap(list_variable_env);
			if (temp == NULL) { std::cout << "could not allocate" << std::endl; }
			list_variable_env = temp;	
			var_env_size++;	
		//std::cout << "adding env\n" << std::endl;
		}

		//entfernt erstes Element der Liste
		void Env::deleteEnv() {
			LinkedVariableTypeMap* temp = list_variable_env->next;
			delete list_variable_env;			
			list_variable_env = temp;
			var_env_size--;
		//std::cout << "deleting env\n" << std::endl;
		}
		
		//fügt neue Variable in aktuelle(erste) VariabelMap
		void Env::updateVar(Id id ,Type* type) {
			list_variable_env->env_->insert (std::pair<Id,Type*>(id,type));
			//printAllVariableMaps(list_variable_env);
		}

		//fügt Funktion der FunktionMap hinzu
		void Env::updateFun(Id id ,ListArg* inputList, Type* output) {
			function_env.insert (std::pair<Id,std::pair<ListArg*,Type*> >(id,std::make_pair(inputList,output)));
			//printFunctionMap(function_env);
		}

		Type* Env::lookupVar(Id id) {
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

		Type* Env::lookuplatest(Id id) {
			variableTypeMap::iterator iter = list_variable_env->env_->find(id);

			if (iter != list_variable_env->env_->end()) {
				return iter->second;
			}

			return NULL; 
		}

		std::pair<ListArg*,Type*> Env::lookupFun(Id id) {
			functionTypeMap::iterator it = function_env.find(id);
			if (it != function_env.end()) {
				return it->second;
			}
			// ... else error handling
		}

		int* Env::checkFun(Id id) {
			functionTypeMap::iterator it = function_env.find(id);
			if (it == function_env.end()) {
				return NULL;
			}
		}

		std::pair<ListArg*,Type*> Env::lookupFun() {
			functionTypeMap::iterator it = --function_env.end();	
			if (it != function_env.end()) {
				return it->second;
			} else { std::cout << "fehler!!!!" << std::endl;}
			// ... else error handling
		}

		std::string Env::lookupVariable (Id id) {
			Type* type = lookupVar(id);
			if (type == NULL) {
				return "";
			} else {
				return type->getType();
			}
		}

		std::string Env::lookuplatestVar (Id id) {
			Type* type = lookuplatest(id);
			if (type == NULL) {
				return "";
			} else {
				return type->getType();
			}
		}

		void Env::printAllVariableMaps(LinkedVariableTypeMap* list) {
			LinkedVariableTypeMap* temp = list;
			for (int i = 0; i < var_env_size; i++) {
				std::cout << i << ". map" << std::endl;
				printVariableMap(temp->env_);
				temp = temp->next;
			}
		}

		void Env::printVariableMap(variableTypeMap* map){
			for(std::map<Id,Type*>::iterator iterator = map->begin(); iterator != map->end(); iterator++){
				std::cout<<"Key:"<<iterator->first<< std::endl;
				std::cout<<"Type:"<< iterator->second->getType() << std::endl;	
				//iterator->second->printType();
				std::cout << std::endl;		
			} 		
		}

		void Env::printFunctionMap(functionTypeMap map){
			std::cout << "Printiing..." << std::endl;
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
