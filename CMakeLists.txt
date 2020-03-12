cmake_minimum_required(VERSION 3.13)
project(untitled7)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_EXE Main.cpp)

#Parent&Children lib
set(SOURCE_LIB Checker.cpp)

set(SOURCE_LIB_hash_f HashFunction.cpp)

set(SOURCE_LIB_Tree BinTree.cpp)
set(SOURCE_LIB_Map HashMap.cpp)
set(SOURCE_LIB_Vect VecStd.cpp)
set(SOURCE_LIB_My MyHash.cpp)

add_executable(main ${SOURCE_EXE})

add_library(Checker STATIC ${SOURCE_LIB})
add_library(HashFunct STATIC ${SOURCE_LIB_hash_f})

add_library(BinTree STATIC ${SOURCE_LIB_Tree})
add_library(MapHash STATIC ${SOURCE_LIB_Map})
add_library(VecHash STATIC ${SOURCE_LIB_Vect})
add_library(MyHash STATIC ${SOURCE_LIB_My})

target_link_libraries(main Checker HashFunct BinTree MapHash VecHash MyHash)