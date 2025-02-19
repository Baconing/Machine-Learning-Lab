#include <DynamicCodeExecutionEngineInterface.h>
#include <NodeInterface.h>
#include <LanguageInterface.h>
#include <GraphEngineInterface.h>
#include <AttributeInterface.h>
#include <UIEngineInterface.h>
#include <string>


class InputDataSetNode : public NodeInterface {
    std::vector<double> values = { 0 };
public:
    InputDataSetNode() {
        TypeID = "InputDataSetNode";
    }

    void Process(bool DirectionForward) override {
        if (DirectionForward) {
            nlohmann::json data = nlohmann::json::object();
            data["Data"] = values;
            data["Type"] = "Vector";
            GetOutputDataByIndex(0) = data;
        }
    }

    void Init() override {
        //json array
        Description=nlohmann::json::array();
        MakeOutput(0, "Output", "double", 0);
        MakeAttribute(0, new AttributeInterface([this]() {
			ImGui::PushItemWidth(100);
			int size = values.size();
			ImGui::InputInt("Size", &size);
			if (size <= 0) size = 1;
			values.resize(size);
			}));

        MakeAttribute(1, new AttributeInterface([this]() {
			ImGui::PushItemWidth(100);
            for (int i = 0; i < values.size(); i++) {
                ImGui::InputDouble(std::to_string(i).c_str(), &values[i]);
            }
            }));
    }

    //void DrawNodeTitle();

    NodeInterface* GetInstance() {
        InputDataSetNode* node = new InputDataSetNode();
        return node;
    }

    nlohmann::json Serialize() override {
        nlohmann::json data = NodeInterface::Serialize();

        //values
        data["values"] = nlohmann::json::array();
        for (auto value : values) {
			data["values"].push_back(value);
		}

        return data;
    }

    void DeSerialize(nlohmann::json data, void* DCEE) override {
        NodeInterface::DeSerialize(data, DCEE);

		//values
		values.clear();
        for (auto value : data["values"]) {
            values.push_back(value);
        }

        Attributes.push_back(new AttributeInterface([this]() {
            ImGui::PushItemWidth(100);
            int size = values.size();
            ImGui::InputInt("Size", &size);
            if (size <= 0) size = 1;
            values.resize(size);
            }));

        Attributes.push_back(new AttributeInterface([this]() {
            ImGui::PushItemWidth(100);
            for (int i = 0; i < values.size(); i++) {
                ImGui::InputDouble(std::to_string(i).c_str(), &values[i]);
            }
            }));
    }
};


extern "C" {
    // Define a function that returns the result of adding two numbers
    __declspec(dllexport) NodeInterface* GetInstance() {
        return new InputDataSetNode();
    }
}