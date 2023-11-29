file(GLOB_RECURSE GraphEdgeSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/EdgeInterface/EdgeInterface/*.h
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/EdgeInterface/EdgeInterface/*.cpp)


add_library(GraphEdge SHARED ${GraphEdgeSources})

target_link_libraries(GraphEdge PUBLIC imgui boost_filesystem)
target_link_libraries(GraphEdge PRIVATE OpenCL::OpenCL)