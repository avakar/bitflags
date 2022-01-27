cmake_minimum_required(VERSION 3.19)
project(avakar.bitflags)

include(FetchContent)
FetchContent_Declare(avakar.mutest SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/deps/mutest")
FetchContent_MakeAvailable(avakar.mutest)

add_library(avakar.bitflags INTERFACE
	include/avakar/bitflags.h
	)
add_library(avakar::bitflags ALIAS avakar.bitflags)

target_include_directories(avakar.bitflags INTERFACE include)
target_compile_features(avakar.bitflags INTERFACE cxx_std_11)

add_mutest(test/test.cpp avakar::bitflags)
