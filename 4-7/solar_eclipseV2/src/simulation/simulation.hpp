
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>


class Simulation
{

private:
  
  std::vector<double> MoonPos;
  std::vector<double> EarthPos;

  std::vector<double> MoonVel;
  std::vector<double> EarthVel;

public:

  void initialize_positions();

  void initialize_velocities();

  void print_earth_position();
  void print_earth_position_magnitude();
  void print_moon_position();
  void print_moon_position_magnitude();

  void update_earths_position(double dt);
  void update_moons_position(double dt);

  double determine_if_solar_eclipse();
  
};

#endif
