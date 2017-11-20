cmake_minimum_required(VERSION 3.8)
project(pr6_eedd)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Diccionario.h Diccionario.cpp Palabra.h Palabra.cpp Sucesor.h Sucesor.cpp TextoPredictivo.h TextoPredictivo.cpp Usuario.cpp Usuario.h)
add_executable(pr6_eedd ${SOURCE_FILES})