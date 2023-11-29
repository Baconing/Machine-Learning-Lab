file(GLOB_RECURSE GraphInterfaceSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/GraphInterface/GraphInterface/*.h
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/GraphInterface/GraphInterface/*.cpp)


add_library(GraphInterface SHARED ${GraphInterfaceSources})

target_link_libraries(GraphInterface PUBLIC imgui boost_filesystem)
target_link_libraries(GraphInterface PRIVATE OpenCL::OpenCL)