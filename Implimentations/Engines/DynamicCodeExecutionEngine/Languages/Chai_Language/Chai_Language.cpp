#include <LanguageInterface.h>
#include <ScriptInterface.h>
#include <NodeInterface.h>
#include <AttributeInterface.h>

#include <chaiscript/chaiscript.hpp>
#include <iostream>
#include <string>
#include <vector>

class Chai_Language : public LanguageInterface {
	chaiscript::ChaiScript chai;
public:

	std::string GetExtension() override {
		return ".chai";
	}

	std::string GetName() override {
		return "ChaiScript";
	}

	void SetVariable(const char* name, int value) override {


	}

	void SetVariable(const char* name, std::string value) override {
	}

	void SetVariable(const char* name, float value) override {
	}

	void SetVariable(const char* name, double value) override {
	}

	void SetVariable(const char* name, bool value) override {
	}

	void SetVariable(const char* name, void* value, std::string type) override {
	}

	int GetVariableInt(const char* name) override {
		return 0;
	}

	std::string GetVariableString(const char* name) override {
		return "";
	}

	float GetVariableFloat(const char* name)  override {
		return 0.0f;
	}

	double GetVariableDouble(const char* name) override {
		return 0.0;
	}

	bool GetVariableBool(const char* name) override {
		return false;
	}

	void* GetVariablePointer(const char* name, std::string* type) override {
		return nullptr;
	}

	void LoadScript(ScriptInterface* script) override {
	}

	void RunScript(ScriptInterface* script) override {
	}

	void RunString(std::string script) override {
	}

	void RunFile(std::string path) override {
	}

	void CallFunction(const char* name, std::vector<void*> args, std::vector<std::string> types, void* ret) override {
	}

	class ScriptNode : public ScriptInterface, public NodeInterface {};

	//Activation
	double Activation_Activate(double input) override {
		return 0;
	}

	double Activation_ActivateDerivative(double input) override {
		return 0;
	}

	//Loss
	double Loss_CalculateLoss(double input, double target) override {
		return 0;
	}

	double Loss_CalculateLossDerivative(double input, double target) override {
		return 0;
	}

	void CreateNode(void* node) {
		ScriptNode* snode = (ScriptNode*)node;
		//create node in chai

	}

	void RegisterFunctions() {
		/*
				lua_pushcfunction(L, Node_MakeInput);
				lua_setglobal(L, "Node_MakeInput");
				lua_pushcfunction(L, Node_MakeOutput);
				lua_setglobal(L, "Node_MakeOutput");
				lua_pushcfunction(L, Node_MakeAttribute);
				lua_setglobal(L, "Node_MakeAttribute");
				lua_pushcfunction(L, Node_GetInputDataByIndex);
				lua_setglobal(L, "Node_GetInputDataByIndex");
				lua_pushcfunction(L, Node_GetOutputDataByIndex);
				lua_setglobal(L, "Node_GetOutputDataByIndex");
				lua_pushcfunction(L, Node_SetInputDataByIndex);
				lua_setglobal(L, "Node_SetInputDataByIndex");
				lua_pushcfunction(L, Node_SetOutputDataByIndex);
				lua_setglobal(L, "Node_SetOutputDataByIndex");
				lua_pushcfunction(L, Node_ImGuiPushItemWidth);
				lua_setglobal(L, "Node_ImGuiPushItemWidth");
				lua_pushcfunction(L, Node_ImGuiInputInt);
				lua_setglobal(L, "Node_ImGuiInputInt");
				lua_pushcfunction(L, Node_ImGuiInputFloat);
				lua_setglobal(L, "Node_ImGuiInputFloat");
		*/
		chai.add(chaiscript::fun(&ScriptNode::MakeInput), "Node_MakeInput");
		chai.add(chaiscript::fun(&ScriptNode::MakeOutput), "Node_MakeOutput");
		chai.add(chaiscript::fun(&ScriptNode::MakeAttribute), "Node_MakeAttribute");
		chai.add(chaiscript::fun(&ScriptNode::GetInputDataByIndex), "Node_GetInputDataByIndex");
		chai.add(chaiscript::fun(&ScriptNode::GetOutputDataByIndex), "Node_GetOutputDataByIndex");
		


	}

	void Node_Init(void* node) override {
		ScriptNode* snode = (ScriptNode*)node;

		RegisterFunctions();


	}

	void Node_Process(void* node, bool forward) override {
		ScriptNode* snode = (ScriptNode*)node;
		RegisterFunctions();

	}

	Chai_Language() {
		//setup chai
		chai.add(chaiscript::fun(&Chai_Language::CreateNode), "CreateNode");

	}
};

static Chai_Language instance = Chai_Language();

extern "C" {
	//Define a function that returns the result of adding two numbers
	__declspec(dllexport) LanguageInterface* GetInstance() {
		return &instance;
	}
}