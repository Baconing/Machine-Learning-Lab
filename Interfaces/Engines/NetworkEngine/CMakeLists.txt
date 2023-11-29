file(GLOB_RECURSE NetworkEngineSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/NetworkEngine/*.h
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/NetworkEngine/*.cpp)

add_library(NetworkEngine STATIC ${NetworkEngineSources})