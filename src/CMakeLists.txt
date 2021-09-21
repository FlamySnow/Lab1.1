cmake_minimum_required(VERSION 3.20)
project(Lab_1_1)

set(CMAKE_CXX_STANDARD 23)

add_library(FoliumOfDescartes STATIC ../lib/folium_of_Descartes.cpp)

set (APP_EXE libTest)

add_executable(${APP_EXE} main.cpp)

TARGET_LINK_LIBRARIES(${APP_EXE} FoliumOfDescartes)