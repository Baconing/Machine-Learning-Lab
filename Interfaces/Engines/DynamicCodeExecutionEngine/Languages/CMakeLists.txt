file(GLOB_RECURSE LanguageHeaders ${CMAKE_SOURCE_DIR}/Interfaces/Languages/*.h)

file(GLOB_RECURSE ChaiLanguage ${CMAKE_SOURCE_DIR}/Implimentations/Engines/DynamicCodeExecutionEngine/Languages/Chai_Language/*.cpp)
file(GLOB_RECURSE JavaLanguage ${CMAKE_SOURCE_DIR}/Implimentations/Engines/DynamicCodeExecutionEngine/Languages/Java_Language/*.cpp)
file(GLOB_RECURSE JavaScriptLanguage ${CMAKE_SOURCE_DIR}/Implimentations/Engines/DynamicCodeExecutionEngine/Languages/JavaScript_Language/*.cpp)
file(GLOB_RECURSE LuaLanguage ${CMAKE_SOURCE_DIR}/Implimentations/Engines/DynamicCodeExecutionEngine/Languages/Lua_Language/*.cpp)
file(GLOB_RECURSE PythonLanguage ${CMAKE_SOURCE_DIR}/Implimentations/Engines/DynamicCodeExecutionEngine/Languages/Python_Language/*.cpp)

add_library(ChaiLanguage STATIC ${LanguageHeaders} ${ChaiLanguage})
add_library(JavaLanguage STATIC ${LanguageHeaders} ${JavaLanguage})
add_library(JavaScriptLanguage STATIC ${LanguageHeaders} ${JavaScriptLanguage})
add_library(LuaLanguage STATIC ${LanguageHeaders} ${LuaLanguage})
add_library(PythonLanguage STATIC ${LanguageHeaders} ${PythonLanguage})

target_link_libraries(ChaiLanguage ChaiScript)