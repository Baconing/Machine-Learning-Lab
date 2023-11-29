file(GLOB_RECURSE GraphAttributeSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/Attributes/AttributeInterface/*.h)


add_library(GraphAttribute SHARED ${GraphAttributeSources})

target_link_libraries(GraphAttribute PUBLIC imgui boost_filesystem)
target_link_libraries(GraphAttribute PRIVATE OpenCL::OpenCL)

set_target_properties(GraphAttribute PROPERTIES LINKER_LANGUAGE CXX)