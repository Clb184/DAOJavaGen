cmake_minimum_required(VERSION 3.6)
project(DAOJavaGen)
set(CMAKE_CXX_STANDARD 20)
file(DOWNLOAD https://github.com/nlohmann/json/releases/download/v3.12.0/json.hpp ${CMAKE_HOME_DIRECTORY}/include/json.hpp SHOW_PROGRESS)

add_executable(DAOJavaGen src/main.cpp)

set_target_properties(DAOJavaGen PROPERTIES DEBUGGER_WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/Tests)

target_include_directories(DAOJavaGen 
	PUBLIC include/)