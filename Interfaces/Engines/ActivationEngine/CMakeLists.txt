file(GLOB_RECURSE ActivationEngineSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/ActivationEngine/*.h
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/ActivationEngine/ActivationEngine/*.cpp)

file(GLOB_RECURSE ActivationInterface
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/ActivationEngine/Activations/*.h)

file(GLOB_RECURSE LeakyReLUActivationSource
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/ActivationEngine/Activations/LeakyReLUActivation/*.cpp)

file(GLOB_RECURSE ReLUActivationSource
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/ActivationEngine/Activations/ReLUActivation/*.cpp)

file(GLOB_RECURSE ScriptActivationSource
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/ActivationEngine/Activations/ScriptActivation/*.cpp)

file(GLOB_RECURSE SigmoidActivationSource
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/ActivationEngine/Activations/SigmoidActivation/*.cpp)


add_library(ActivationEngine SHARED ${ActivationEngineSources})

add_library(LeakyReLUActivation SHARED ${LeakyReLUActivationSource} ${ActivationInterface})
add_library(ReLUActivation SHARED ${ReLUActivationSource} ${ActivationInterface})
add_library(ScriptActivation SHARED ${ScriptActivationSource} ${ActivationInterface})
add_library(SigmoidActivation SHARED ${SigmoidActivationSource} ${ActivationInterface})

target_link_libraries(ActivationEngine PUBLIC imgui boost_filesystem)
target_link_libraries(ActivationEngine PRIVATE OpenCL::OpenCL)