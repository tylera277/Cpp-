

add_library(simulation STATIC simulation.cpp simulation.hpp)

target_link_libraries(simulation PUBLIC solar_eclipse)
