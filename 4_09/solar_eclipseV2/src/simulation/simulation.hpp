
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>


class Simulation
{

private:
  
  std::vector<long double> MoonPos;
  std::vector<long double> EarthPos;

  std::vector<long double> MoonVel;
  std::vector<long double> EarthVel;

public:

  void initialize_positions();

  void initialize_velocities();

  void print_earth_position();
  void print_earth_position_magnitude();
  void print_moon_position();
  void print_moon_position_magnitude();

  void update_earths_position_rk(double dt);
  void update_moons_position_rk(double dt);

  void update_earths_position_sv(double dt);
  void update_moons_position_sv(double dt);

  double determine_if_solar_eclipse(double time);

  void export_position_data_to_csv(std::string filename1);
};

#endif
