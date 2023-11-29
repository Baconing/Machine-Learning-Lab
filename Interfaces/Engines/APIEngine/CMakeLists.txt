file(GLOB_RECURSE APIEngineSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/APIEngine/*.h
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/APIEngine*.cpp)


add_library(APIEngine SHARED ${APIEngineSources})

target_link_libraries(APIEngine PUBLIC imgui boost_filesystem)
target_link_libraries(APIEngine PRIVATE OpenCL::OpenCL)