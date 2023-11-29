file(GLOB_RECURSE OptimizationEngineSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/OptimizationEngine/*.h
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/OptimizationEngine/*.cpp
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/OptimizationEngine/*.h)

add_library(OptimizationEngine STATIC ${OptimizationEngineSources})