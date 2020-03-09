cmake_minimum_required(VERSION 3.15)
project(untitled7)


set(CMAKE_CXX_STANDARD 11)

set(SOURCE_EXE main.cpp)
#Parent&Children lib
set(SOURCE_LIB checker.cpp)


set(SOURCE_LIB_HM hashMap.cpp)
set(SOURCE_LIB_Bin binHash.cpp)
set(SOURCE_LIB_MyH VecHash.cpp)
set(SOURCE_LIB_Vect MyHash.cpp)

add_executable(main ${SOURCE_EXE})

add_library(virtL STATIC ${SOURCE_LIB})

add_library(binHash STATIC ${SOURCE_LIB_Bin})
add_library(mapHash STATIC ${SOURCE_LIB_HM})
add_library(myHash STATIC ${SOURCE_LIB_MyH})
add_library(vecHash STATIC ${SOURCE_LIB_Vect})

target_link_libraries(main virtL binHash mapHash myHash vecHash)