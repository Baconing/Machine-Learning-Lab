cmake_minimum_required(VERSION 3.25)
project(Machine_Learning_Lab)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCL REQUIRED)

include_directories(.)
include_directories(ImNodes)
include_directories(Interfaces/Engines/ActivationEngine)
include_directories(Interfaces/Engines/ActivationEngine/ActivationEngineInterface)
include_directories(Interfaces/Engines/ActivationEngine/Activations)
include_directories(Interfaces/Engines/ActivationEngine/Activations/ActivationInterface)
include_directories(Interfaces/Engines/APIEngine)
include_directories(Interfaces/Engines/APIEngine/APIEngineInterface)
include_directories(Interfaces/Engines/APIEngine/APINode)
include_directories(Interfaces/Engines/APIEngine/APINode/APINodeInterface)
include_directories(Interfaces/Engines/APIEngine/Endpoint)
include_directories(Interfaces/Engines/APIEngine/Endpoint/EndpointInterface)
include_directories(Interfaces/Engines/DataBaseEngine)
include_directories(Interfaces/Engines/DataBaseEngine/DataBaseEngine)
include_directories(Interfaces/Engines/DataBaseEngine/DataBaseEngine/DataBaseEngineInterface)
include_directories(Interfaces/Engines/DynamicCodeExecutionEngine/DynamicCodeExecutionEngineInterface)
include_directories(Interfaces/Engines/DynamicCodeExecutionEngine/KernelInterface)
include_directories(Interfaces/Engines/DynamicCodeExecutionEngine/Languages)
include_directories(Interfaces/Engines/DynamicCodeExecutionEngine/Languages/LanguageInterface)
include_directories(Interfaces/Engines/DynamicCodeExecutionEngine/LibraryInterface)
include_directories(Interfaces/Engines/DynamicCodeExecutionEngine/Plugins)
include_directories(Interfaces/Engines/DynamicCodeExecutionEngine/Plugins/PluginInterface)
include_directories(Interfaces/Engines/DynamicCodeExecutionEngine/ScriptInterface)
include_directories(Interfaces/Engines/EngineInterface)
include_directories(Interfaces/Engines/GraphEngine/Attributes)
include_directories(Interfaces/Engines/GraphEngine/Attributes/AttributeInterface)
include_directories(Interfaces/Engines/GraphEngine/EdgeInterface/EdgeInterface)
include_directories(Interfaces/Engines/GraphEngine/GraphEngineInterface)
include_directories(Interfaces/Engines/GraphEngine/GraphInterface/GraphInterface)
include_directories(Interfaces/Engines/GraphEngine/NodeIOs/NodeIOInterface)
include_directories(Interfaces/Engines/GraphEngine/Nodes/NodeInterface)
include_directories(Interfaces/Engines/GraphEngine/Sorters)
include_directories(Interfaces/Engines/GraphEngine/Sorters/SorterInterface)
include_directories(Interfaces/Engines/LossEngine)
include_directories(Interfaces/Engines/LossEngine/LossEngineInterface)
include_directories(Interfaces/Engines/LossEngine/Losses)
include_directories(Interfaces/Engines/LossEngine/Losses/LossInterface)
include_directories(Interfaces/Engines/NetworkEngine)
include_directories(Interfaces/Engines/NetworkEngine/Client)
include_directories(Interfaces/Engines/NetworkEngine/Client/ClientInterface)
include_directories(Interfaces/Engines/NetworkEngine/LedgerInterface)
include_directories(Interfaces/Engines/NetworkEngine/LedgerInterface/LedgerInterface)
include_directories(Interfaces/Engines/NetworkEngine/NetworkEngineInterface)
include_directories(Interfaces/Engines/NetworkEngine/NetworkObject)
include_directories(Interfaces/Engines/NetworkEngine/NetworkObject/NetworkObjectInterface)
include_directories(Interfaces/Engines/NetworkEngine/Server)
include_directories(Interfaces/Engines/NetworkEngine/Server/ServerInterface)
include_directories(Interfaces/Engines/OptimizationEngine)
include_directories(Interfaces/Engines/OptimizationEngine/OptimizationEngineInterface)
include_directories(Interfaces/Engines/SerializationEngine)
include_directories(Interfaces/Engines/SerializationEngine/SerializableInterface)
include_directories(Interfaces/Engines/SerializationEngine/SerializableInterface/SerializableInterface)
include_directories(Interfaces/Engines/UIEngine)
include_directories(Interfaces/Engines/UIEngine/UIEngineInterface)

add_executable(Machine_Learning_Lab
        ImNodes/imnodes.cpp
        ImNodes/imnodes.h
        ImNodes/imnodes_internal.h
        Interfaces/Engines/ActivationEngine/ActivationEngineInterface/ActivationEngineInterface.h
        Interfaces/Engines/ActivationEngine/Activations/ActivationInterface/ActivationInterface.h
        Interfaces/Engines/APIEngine/APIEngineInterface/APIEngineInterface.h
        Interfaces/Engines/APIEngine/APINode/APINodeInterface/APINodeInterface.h
        Interfaces/Engines/APIEngine/Endpoint/EndpointInterface/EndPointInterface.h
        Interfaces/Engines/DataBaseEngine/DataBaseEngine/DataBaseEngineInterface/DataBaseEngineInterface.h
        Interfaces/Engines/DynamicCodeExecutionEngine/DynamicCodeExecutionEngineInterface/DynamicCodeExecutionEngineInterface.cpp
        Interfaces/Engines/DynamicCodeExecutionEngine/DynamicCodeExecutionEngineInterface/DynamicCodeExecutionEngineInterface.h
        Interfaces/Engines/DynamicCodeExecutionEngine/KernelInterface/KernelInterface.h
        Interfaces/Engines/DynamicCodeExecutionEngine/Languages/LanguageInterface/LanguageInterface.h
        Interfaces/Engines/DynamicCodeExecutionEngine/LibraryInterface/LibraryInterface.h
        Interfaces/Engines/DynamicCodeExecutionEngine/Plugins/PluginInterface/PluginInterface.h
        Interfaces/Engines/DynamicCodeExecutionEngine/ScriptInterface/ScriptInterface.h
        Interfaces/Engines/EngineInterface/EngineInterface.h
        Interfaces/Engines/GraphEngine/Attributes/AttributeInterface/AttributeInterface.h
        Interfaces/Engines/GraphEngine/EdgeInterface/EdgeInterface/EdgeInterface.cpp
        Interfaces/Engines/GraphEngine/EdgeInterface/EdgeInterface/EdgeInterface.h
        Interfaces/Engines/GraphEngine/GraphEngineInterface/GraphEngineInterface.cpp
        Interfaces/Engines/GraphEngine/GraphEngineInterface/GraphEngineInterface.h
        Interfaces/Engines/GraphEngine/GraphInterface/GraphInterface/GraphInterface.cpp
        Interfaces/Engines/GraphEngine/GraphInterface/GraphInterface/GraphInterface.h
        Interfaces/Engines/GraphEngine/NodeIOs/NodeIOInterface/NodeIOInterface.cpp
        Interfaces/Engines/GraphEngine/NodeIOs/NodeIOInterface/NodeIOInterface.h
        Interfaces/Engines/GraphEngine/Nodes/NodeInterface/NodeInterface.cpp
        Interfaces/Engines/GraphEngine/Nodes/NodeInterface/NodeInterface.h
        Interfaces/Engines/GraphEngine/Sorters/SorterInterface/SorterInterface.h
        Interfaces/Engines/LossEngine/LossEngineInterface/LossEngineInterface.h
        Interfaces/Engines/LossEngine/Losses/LossInterface/LossInterface.h
        Interfaces/Engines/NetworkEngine/Client/ClientInterface/ClientInterface.h
        Interfaces/Engines/NetworkEngine/LedgerInterface/LedgerInterface/LedgerInterface.h
        Interfaces/Engines/NetworkEngine/NetworkEngineInterface/NetworkEngineInterface.h
        Interfaces/Engines/NetworkEngine/NetworkObject/NetworkObjectInterface/NetworkObjectInterface.h
        Interfaces/Engines/NetworkEngine/Server/ServerInterface/ServerInterface.h
        Interfaces/Engines/OptimizationEngine/OptimizationEngineInterface/OptimizationEngineInterface.h
        Interfaces/Engines/SerializationEngine/SerializableInterface/SerializableInterface/SerializableInterface.h
        Interfaces/Engines/UIEngine/UIEngineInterface/UIEngineInterface.h
        "Machine Learning Labs/Machine Learning Labs.cpp"
        types.h)

target_link_libraries(Machine_Learning_Lab PUBLIC imgui boost_filesystem)
target_link_libraries(Machine_Learning_Lab PRIVATE OpenCL::OpenCL)

add_executable(Cleaner
        Cleaner/Cleaner.cpp)

target_link_libraries(Cleaner PUBLIC boost_filesystem)

add_subdirectory(Interfaces)