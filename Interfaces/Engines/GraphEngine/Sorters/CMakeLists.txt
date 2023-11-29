file(GLOB_RECURSE SorterInterface
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/Sorters/SorterInterface/*.h)

file(GLOB_RECURSE DefaultSorter
        ${CMAKE_SOURCE_DIR}/Interfaces/Engines/GraphEngine/Sorters/DefaultSorter/*.cpp)

add_library(DefaultSorter SHARED ${SorterInterface} ${DefaultSorter})

set_target_properties(DefaultSorter PROPERTIES LINKER_LANGUAGE CXX)