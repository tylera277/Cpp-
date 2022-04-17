
cmake_minimum_required(VERSION 3.21.1)
project(solar_eclipse)


add_subdirectory("simulation")
add_subdirectory("simulation/rungekutta")

add_executable(solar_eclipse main.cpp)

