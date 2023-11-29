file(GLOB_RECURSE DataBaseEngineSources
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/DataBaseEngine/*.h
        ${CMAKE_SOURCE_DIR}/Implimentations/Engines/DataBaseEngine/*.cpp)


add_library(DataBaseEngine SHARED ${DataBaseEngineSources})

target_link_libraries(DataBaseEngine PUBLIC imgui boost_filesystem)
target_link_libraries(DataBaseEngine PRIVATE OpenCL::OpenCL)