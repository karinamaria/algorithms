cmake_minimum_required(VERSION 3.5)
project(SortingAlgorithms VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable( driver_search
                src/app_search.cpp # This has the application main().
                src/sorting.cpp ) # This has the search functions implementation.

# define C++11 standard
set_property(TARGET driver_search PROPERTY CXX_STANDARD 11)


# The end
