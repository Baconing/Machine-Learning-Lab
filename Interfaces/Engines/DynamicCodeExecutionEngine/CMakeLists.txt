file(GLOB_RECURSE DCEESources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/DynamicCodeExecutionEngine/*.h
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/DynamicCodeExecutionEngine/*.cpp
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/DynamicCodeExecutionEngine/*.cpp)


add_library(DCEE SHARED ${DCEESources})

target_link_libraries(DCEE PUBLIC imgui boost_filesystem)
target_link_libraries(DCEE PRIVATE OpenCL::OpenCL)

add_subdirectory(Languages)