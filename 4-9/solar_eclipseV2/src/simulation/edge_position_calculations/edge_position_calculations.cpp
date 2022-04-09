

#include "edge_position_calculations.hpp"

#include <cmath>


double EdgePositionCalculations::calculate_x_moon(double angle){
  const double radius_moon = 1737400;
  double result = cos(angle) * radius_moon;

  return result;
}

double EdgePositionCalculations::calculate_z_moon(double angle){
  const double radius_moon = 1737400;
  double result = sin(angle) * radius_moon;

  return result;
}

double EdgePositionCalculations::calculate_x_earth(double angle){
  const double radius_earth = 6371000;
  double result = cos(angle) * radius_earth;

  return result;
}

double EdgePositionCalculations::calculate_z_earth(double angle){
  const double radius_earth = 6371000;
  double result = sin(angle) * radius_earth;

  return result;
}

