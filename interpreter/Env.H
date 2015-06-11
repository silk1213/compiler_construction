#ifndef ENV_HEADER
#define ENV_HEADER
#include "Absyn.H"
#include <iostream>
#include <map>
#include <iterator>
#include <utility>
#include <list>

typedef std::map<Id,Type*> variableTypeMap;
typedef std::map<Id,std::pair<ListArg*,Type*> > functionTypeMap;

class LinkedVariableTypeMap;
class Env;

class LinkedVariableTypeMap {
	public: 
		//Map für Variabeln
		variableTypeMap* env_;

		//Zeiger auf nächste Map
		LinkedVariableTypeMap* next;

		//Konstruktor mit anhängen an bestehende Liste
		LinkedVariableTypeMap(LinkedVariableTypeMap* list);

		//Konstruktor
		LinkedVariableTypeMap();

		//Destruktor
		~LinkedVariableTypeMap();
};

class Env {
	private:
		LinkedVariableTypeMap* list_variable_env;
		int var_env_size;
		functionTypeMap function_env;
	

	public:
		//Konstruktor (erstellt Liste mit erster Map)
		Env();

		//Destruktor
		~Env();

		//fügt neue Map an erste Position der Liste hinzu
		void addEnv();

		//entfernt erstes Element der Liste
		void deleteEnv();
		
		//fügt neue Variable in aktuelle(erste) VariabelMap
		void updateVar(Id id ,Type* type);

		//fügt Funktion der FunktionMap hinzu
		void updateFun(Id id ,ListArg* inputList, Type* output);

		Type* lookupVar(Id id);

		Type* lookuplatest(Id id);

		std::pair<ListArg*,Type*> lookupFun(Id id);

		int* checkFun(Id id);

		std::pair<ListArg*,Type*> lookupFun();

		std::string lookupVariable (Id id);

		std::string lookuplatestVar (Id id);

		void printAllVariableMaps(LinkedVariableTypeMap* list);

		void printVariableMap(variableTypeMap* map);

		void printFunctionMap(functionTypeMap map);
};
#endif
