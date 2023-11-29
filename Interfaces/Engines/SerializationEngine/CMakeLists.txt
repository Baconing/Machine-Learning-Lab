file(GLOB_RECURSE SerializationEngineSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/OptimizationEngine/*.h
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/OptimizationEngine/*.cpp
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/OptimizationEngine/*.h)

add_library(SerializationEngine STATIC ${SerializationEngineSources})