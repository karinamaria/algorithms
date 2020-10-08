cmake_minimum_required(VERSION 3.5)
project(Trabalho2 VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------


# define the sources for the project
add_executable( q01
                questao1.cpp) # This has the search functions implementation.
add_executable( q04
                questao4.cpp)
add_executable( q07
                questao7.cpp)
add_executable( q08
                questao8.cpp)
add_executable( q12
                questao12.cpp)
add_executable( q14
                questao14.cpp)