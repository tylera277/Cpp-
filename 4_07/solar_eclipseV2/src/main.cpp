
#include <iostream>
#include <vector>

#include "simulation/simulation.hpp"


int main(){

  Simulation sim;

  int T = 365*86400*10;
  double dt = 86400.0/24.0;
  int t = 0;
  
    
  sim.initialize_positions();
  sim.initialize_velocities();
  
  sim.print_earth_position();
  //sim.print_moon_position();

  

  while(t<T){
    
    sim.update_earths_position(dt);
    sim.update_moons_position(dt);

    sim.determine_if_solar_eclipse();


    t += dt;
  }
  
}
