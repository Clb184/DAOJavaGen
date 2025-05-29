cmake_minimum_required(VERSION 3.6)
project(DAOJavaGen)
set(CMAKE_CXX_STANDARD 20)
file(DOWNLOAD https://github.com/nlohmann/json/releases/download/v3.12.0/json.hpp ${CMAKE_HOME_DIRECTORY}/include/json.hpp SHOW_PROGRESS)
file(DOWNLOAD https://raw.githubusercontent.com/tronkko/dirent/master/include/dirent.h ${CMAKE_HOME_DIRECTORY}/include/dirent.h SHOW_PROGRESS)

# Hot Reload for MSVC
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

file(GLOB src src/*.cpp)

add_executable(DAOJavaGen ${src})
if(MSVC)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()
set_target_properties(DAOJavaGen PROPERTIES DEBUGGER_WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/Tests)

target_include_directories(DAOJavaGen 
	PUBLIC include/)