file(GLOB_RECURSE LossEngineSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/LossEngine/*.h)

file(GLOB_RECURSE LossInterface
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/LossEngine/Losses/LossInterface.h)

file(GLOB_RECURSE MSELossSources
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/LossEngine/Losses/MSELoss/*.cpp)

file(GLOB_RECURSE ScriptLossSources
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/LossEngine/Losses/ScriptLoss/*.cpp)

add_library(LossEngine SHARED ${LossEngineSources})

add_library(MSELoss SHARED ${MSELossSources})
add_library(ScriptLoss SHARED ${ScriptLossSources})

set_target_properties(LossEngine PROPERTIES LINKER_LANGUAGE CXX)