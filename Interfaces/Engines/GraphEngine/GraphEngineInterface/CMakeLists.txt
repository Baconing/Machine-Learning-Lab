file(GLOB_RECURSE GraphEngineSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/GraphEngineInterface/*.h
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/GraphEngineInterface/*.cpp
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/GraphEngine/GraphEngine/*.cpp)


add_library(GraphEngine SHARED ${GraphEngineSources})

target_link_libraries(GraphEngine PUBLIC imgui boost_filesystem)
target_link_libraries(GraphEngine PRIVATE OpenCL::OpenCL)