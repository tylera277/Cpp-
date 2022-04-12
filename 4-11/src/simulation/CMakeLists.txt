

add_library(simulation STATIC simulation.cpp simulation.hpp)

add_subdirectory("rungekutta")
add_subdirectory("stormerverlet")
add_subdirectory("MiscTools")
add_subdirectory("PositionCalculation")


target_link_libraries(simulation PUBLIC rungekutta)
target_link_libraries(simulation PUBLIC stormerverlet)
target_link_libraries(simulation PUBLIC MiscTools)
target_link_libraries(simulation PUBLIC PositionCalculation)

include_directories("/usr/local/include/eigen3")
