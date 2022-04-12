
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>


#include "simulation/simulation.hpp"
#include "simulation/MiscTools/MiscTools.hpp"

int main(){

  Simulation sim;
  MiscTools tool;

  int T =365*86400;
  double dt = 400;
  double t = 0;
  
    
  sim.initialize_positions();
  sim.initialize_velocities();
  
  //sim.print_earth_position();
  //sim.print_moon_position();
  std::string filename1 = "output.csv";
  std::string start_date = "01/01/2022";

  tool.clear_file(filename1);

  while(t<T){

    sim.update_earths_position_sv(dt);
    sim.update_moons_position_sv(dt);

    
    sim.determine_if_solar_eclipse(start_date, t);
   
    
    sim.export_position_data_to_csv(filename1);

    t += dt;
  }
  
}
