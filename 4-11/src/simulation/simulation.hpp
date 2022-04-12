
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

  void update_earths_position_rk(double);
  void update_moons_position_rk(double);

  void update_earths_position_sv(double);
  void update_moons_position_sv(double);

  double determine_if_solar_eclipse(std::string, double);

  void export_position_data_to_csv(std::string);
};

#endif
