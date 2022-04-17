
#include <iostream>

#include "./simulation/simulation.hpp"


int main(){

  Simulation sim;

  int T = 100;
  double dt = 1;
  int t = 0;
  std::vector<double> vectorino;
  vectorino.push_back(12);
  
    
  sim.initialize_positions();

  sim.print_earth_position();
  sim.print_moon_position();

  
  sim.update_earths_position(dt, vectorino);
  /*
  while(t<T){
    
    sim.update_positions(dt);


    t += dt;
  }
  */
  
}
