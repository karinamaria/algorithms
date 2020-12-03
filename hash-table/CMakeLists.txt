cmake_minimum_required(VERSION 3.5)
project(hashtable VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

add_executable(driver_hash "src/account.cpp"
                           "src/teste.cpp")

# define C++11 standard
set_property(TARGET driver_hash PROPERTY CXX_STANDARD 11)

# The end
