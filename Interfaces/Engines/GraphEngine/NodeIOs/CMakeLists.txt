file(GLOB_RECURSE NodeIOSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/NodeIOs/NodeIOInterface/*.h
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/NodeIOs/NodeIOInterface/*.cpp)


add_library(NodeIO SHARED ${NodeIOSources})

target_link_libraries(NodeIO PUBLIC imgui boost_filesystem)
target_link_libraries(NodeIO PRIVATE OpenCL::OpenCL)