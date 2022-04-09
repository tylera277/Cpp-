
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>


#include "simulation/simulation.hpp"


int main(){

  Simulation sim;

  int T =365*86400*2;
  double dt = 400;
  double t = 0;
  
    
  sim.initialize_positions();
  sim.initialize_velocities();
  
  //sim.print_earth_position();
  //sim.print_moon_position();
  std::string filename1 = "output.csv";
    
  std::ofstream myfile;
  myfile.open(filename1, std::ios::trunc);
  myfile <<"\n";
  myfile.close();
  

  while(t<T){
    //sim.print_moon_position();

    //sim.update_earths_position_rk(dt);
    //sim.update_moons_position_rk(dt);

    sim.update_earths_position_sv(dt);
    sim.update_moons_position_sv(dt);

    
    sim.determine_if_solar_eclipse(t);
   
    
    sim.export_position_data_to_csv(filename1);

    t += dt;
  }
  
}
