file(GLOB_RECURSE EngineInterfaceSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/EngineInterface/*.h)


add_library(Engine SHARED ${EngineInterfaceSources})

target_link_libraries(Engine PUBLIC imgui boost_filesystem)
target_link_libraries(Engine PRIVATE OpenCL::OpenCL)

set_target_properties(Engine PROPERTIES LINKER_LANGUAGE CXX)