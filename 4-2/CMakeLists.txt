
cmake_minimum_required(VERSION 3.23.0)
project(myApp)
set(CMAKE_BUILD_TYPE Release)



include_directories(include)


file(GLOB SOURCES "src/*.cpp")


add_library(main STATIC ${SOURCES})


install(TARGETS main DESTINATION /Users/Library/)


