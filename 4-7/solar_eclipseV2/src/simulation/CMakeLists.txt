

add_library(simulation STATIC simulation.cpp simulation.hpp)

add_subdirectory("rungekutta")
add_subdirectory("edge_position_calculations")


target_link_libraries(simulation PUBLIC rungekutta)
target_link_libraries(simulation PUBLIC edge_position_calculations)
include_directories("/usr/local/include/eigen3")
