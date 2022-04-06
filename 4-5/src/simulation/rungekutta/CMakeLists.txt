
add_library(rungekutta STATIC rungekutta.cpp rungekutta.hpp)

target_link_libraries(rungekutta PUBLIC simulation)
