
#include <iostream>
#include <cmath>
#include <Eigen/Dense>

#include "simulation.hpp"
#include "rungekutta/rungekutta.hpp"
#include "edge_position_calculations/edge_position_calculations.hpp"


void Simulation::print_earth_position(){
  
  std::cout << "Earth's position: ";
  for(int i=0; i<3; i++){
    std::cout << EarthPos.at(i) << ",";
  }
  std::cout << std::endl;
  
}


void Simulation::print_moon_position(){
  
  std::cout << "Moon's position: ";
  for(int i=0; i<3; i++){
    std::cout << MoonPos.at(i) << ",";
  }
  std::cout << std::endl;
}


void Simulation::print_earth_position_magnitude(){
  double sum = pow(EarthPos.at(0),2) + pow(EarthPos.at(1),2) + pow(EarthPos.at(2),2);
  double result = pow(sum, 0.5);
  std::cout << "earth Magnitude: " << result << std::endl;
    
}

void Simulation::print_moon_position_magnitude(){
  double sum = pow(EarthPos.at(0),2) + pow(EarthPos.at(1),2) + pow(EarthPos.at(2),2);
  double result = pow(sum, 0.5);
  std::cout << "moon Magnitude: " << result << std::endl;
    
}


void Simulation::initialize_positions(){
  EarthPos.push_back(-1.439690864115037e11);
  EarthPos.push_back(-4.094127130121735e10);
  EarthPos.push_back(2.696304122088477e6);

  MoonPos.push_back(-1.438325034328278e11);
  MoonPos.push_back(-4.056280404695425e10);
  MoonPos.push_back(1.370504220401682e7);
}
void Simulation::initialize_velocities(){
  EarthVel.push_back(7.673964872561084e3);
  EarthVel.push_back(-2.877078252153603e4);
  EarthVel.push_back(3.654321209278777e-1);

  MoonVel.push_back(6.768380307273283e3);
  MoonVel.push_back(-2.842106186419318e4);
  MoonVel.push_back(8.521099522466180e1);
}

void Simulation::update_earths_position(double dt){
  /* Implementation of the runge-kutta algorithm for calculating
     the change in the positions of the respective bodies*/
  
  RungeKutta rk;

  const double sun_mass = 1.9891e30;

  double delT = dt;
  double x1 = EarthPos.at(0);
  double y1 = EarthPos.at(1);
  double z1 = EarthPos.at(2);

  double vx = EarthVel.at(0);
  double vy = EarthVel.at(1);
  double vz = EarthVel.at(2);

  EarthPos.clear();
  EarthVel.clear();
  
  double k1_x, k1_y, k1_z,  k1_vx, k1_vy, k1_vz;
  double k2_x, k2_y, k2_z,  k2_vx, k2_vy, k2_vz;
  double k3_x, k3_y, k3_z,  k3_vx, k3_vy, k3_vz;
  double k4_x, k4_y, k4_z,  k4_vx, k4_vy, k4_vz;


   k1_x = vx;
   k1_y = vy;
   k1_z = vz;
   k1_vx = rk.compute_x_accel(x1,y1,z1, sun_mass);
   k1_vy = rk.compute_y_accel(x1,y1,z1, sun_mass);
   k1_vz = rk.compute_z_accel(x1,y1,z1, sun_mass);


   k2_x = vx + (delT/2.0)*k1_vx;
   k2_y = vy + (delT/2.0)*k1_vy;
   k2_z = vz + (delT/2.0)*k1_vz;
   k2_vx = rk.compute_x_accel((x1+(delT/2.0)*k1_x), (y1+(delT/2.0)*k1_y), (z1+(delT/2.0)*k1_z), sun_mass);
   k2_vy = rk.compute_y_accel((x1+(delT/2.0)*k1_x), (y1+(delT/2.0)*k1_y), (z1+(delT/2.0)*k1_z), sun_mass);
   k2_vz = rk.compute_z_accel((x1+(delT/2.0)*k1_x), (y1+(delT/2.0)*k1_y), (z1+(delT/2.0)*k1_z), sun_mass);


   k3_x = vx + (delT/2.0)*k2_vx;
   k3_y = vy + (delT/2.0)*k2_vy;
   k3_z = vz + (delT/2.0)*k2_vz;
   k3_vx = rk.compute_x_accel((x1+(delT/2.0)*k2_x), (y1+(delT/2.0)*k2_y),(z1+(delT/2.0)*k2_z), sun_mass);
   k3_vy = rk.compute_y_accel((x1+(delT/2.0)*k2_x), (y1+(delT/2.0)*k2_y),(z1+(delT/2.0)*k2_z), sun_mass);
   k3_vz = rk.compute_z_accel((x1+(delT/2.0)*k2_x), (y1+(delT/2.0)*k2_y),(z1+(delT/2.0)*k2_z), sun_mass);

   
   k4_x = vx + delT*k3_vx;
   k4_y = vy + delT*k3_vy;
   k4_z = vz + delT*k3_vz;
   k4_vx = rk.compute_x_accel((x1+delT*k3_x), (y1+delT*k3_y), (z1+delT*k3_z), sun_mass);
   k4_vy = rk.compute_y_accel((x1+delT*k3_x), (y1+delT*k3_y), (z1+delT*k3_z), sun_mass);
   k4_vy = rk.compute_z_accel((x1+delT*k3_x), (y1+delT*k3_y), (z1+delT*k3_z), sun_mass);

   EarthPos.push_back( x1 + ((delT / 6) * (k1_x + 2 * k2_x + 2 * k3_x + k4_x)));
   EarthPos.push_back( y1 + ((delT / 6) * (k1_y + 2 * k2_y + 2 * k3_y + k4_y)));
   EarthPos.push_back( z1 + ((delT / 6) * (k1_z + 2 * k2_z + 2 * k3_z + k4_z)));

   EarthVel.push_back(vx + ((delT / 6) * (k1_vx + 2 * k2_vx + 2 * k3_vx + k4_vx)));
   EarthVel.push_back(vy + ((delT / 6) * (k1_vy + 2 * k2_vy + 2 * k3_vy + k4_vy)));
   EarthVel.push_back(vz + ((delT / 6) * (k1_vz + 2 * k2_vz + 2 * k3_vz + k4_vz)));
      
  
}

void Simulation::update_moons_position(double dt){
  RungeKutta rk;

  const double sun_mass = 1.9891e30;

  double delT = dt;
  double x1 = MoonPos.at(0);
  double y1 = MoonPos.at(1);
  double z1 = MoonPos.at(2);

  double vx = MoonVel.at(0);
  double vy = MoonVel.at(1);
  double vz = MoonVel.at(2);

  MoonPos.clear();
  MoonVel.clear();
  
  double k1_x, k1_y, k1_z,  k1_vx, k1_vy, k1_vz;
  double k2_x, k2_y, k2_z,  k2_vx, k2_vy, k2_vz;
  double k3_x, k3_y, k3_z,  k3_vx, k3_vy, k3_vz;
  double k4_x, k4_y, k4_z,  k4_vx, k4_vy, k4_vz;


   k1_x = vx;
   k1_y = vy;
   k1_z = vz;
   k1_vx = rk.compute_x_accel(x1,y1,z1, sun_mass);
   k1_vy = rk.compute_y_accel(x1,y1,z1, sun_mass);
   k1_vz = rk.compute_z_accel(x1,y1,z1, sun_mass);


   k2_x = vx + (delT/2.0)*k1_vx;
   k2_y = vy + (delT/2.0)*k1_vy;
   k2_z = vz + (delT/2.0)*k1_vz;
   k2_vx = rk.compute_x_accel((x1+(delT/2.0)*k1_x), (y1+(delT/2.0)*k1_y), (z1+(delT/2.0)*k1_z), sun_mass);
   k2_vy = rk.compute_y_accel((x1+(delT/2.0)*k1_x), (y1+(delT/2.0)*k1_y), (z1+(delT/2.0)*k1_z), sun_mass);
   k2_vz = rk.compute_z_accel((x1+(delT/2.0)*k1_x), (y1+(delT/2.0)*k1_y), (z1+(delT/2.0)*k1_z), sun_mass);


   k3_x = vx + (delT/2.0)*k2_vx;
   k3_y = vy + (delT/2.0)*k2_vy;
   k3_z = vz + (delT/2.0)*k2_vz;
   k3_vx = rk.compute_x_accel((x1+(delT/2.0)*k2_x), (y1+(delT/2.0)*k2_y),(z1+(delT/2.0)*k2_z), sun_mass);
   k3_vy = rk.compute_y_accel((x1+(delT/2.0)*k2_x), (y1+(delT/2.0)*k2_y),(z1+(delT/2.0)*k2_z), sun_mass);
   k3_vz = rk.compute_z_accel((x1+(delT/2.0)*k2_x), (y1+(delT/2.0)*k2_y),(z1+(delT/2.0)*k2_z), sun_mass);

   
   k4_x = vx + delT*k3_vx;
   k4_y = vy + delT*k3_vy;
   k4_z = vz + delT*k3_vz;
   k4_vx = rk.compute_x_accel((x1+delT*k3_x), (y1+delT*k3_y), (z1+delT*k3_z), sun_mass);
   k4_vy = rk.compute_y_accel((x1+delT*k3_x), (y1+delT*k3_y), (z1+delT*k3_z), sun_mass);
   k4_vz = rk.compute_z_accel((x1+delT*k3_x), (y1+delT*k3_y), (z1+delT*k3_z), sun_mass);

   MoonPos.push_back( x1 + ((delT / 6) * (k1_x + 2 * k2_x + 2 * k3_x + k4_x)));
   MoonPos.push_back( y1 + ((delT / 6) * (k1_y + 2 * k2_y + 2 * k3_y + k4_y)));
   MoonPos.push_back( z1 + ((delT / 6) * (k1_z + 2 * k2_z + 2 * k3_z + k4_z)));

   MoonVel.push_back(vx + ((delT / 6) * (k1_vx + 2 * k2_vx + 2 * k3_vx + k4_vx)));
   MoonVel.push_back(vy + ((delT / 6) * (k1_vy + 2 * k2_vy + 2 * k3_vy + k4_vy)));
   MoonVel.push_back(vz + ((delT / 6) * (k1_vz + 2 * k2_vz + 2 * k3_vz + k4_vz)));
       
}


double Simulation::determine_if_solar_eclipse(){

  EdgePositionCalculations epc;
    
  const Eigen::Vector3d earth(EarthPos.at(0), EarthPos.at(1), EarthPos.at(2));
  const Eigen::Vector3d moon(MoonPos.at(0), MoonPos.at(1), MoonPos.at(2));

  
  double a_b_dot = earth.dot(moon);
  double b_b_dot = moon.dot(moon);

  double inner_fraction = a_b_dot / b_b_dot;

  Eigen::Vector3d proj_b_a_parallel = inner_fraction * moon;
  //std::cout << "PARA: " << inner_fraction << std::endl;
    
  Eigen::Vector3d proj_b_a_perp = earth - proj_b_a_parallel;

  
  if(abs(proj_b_a_perp[0])<5.371e8 and abs(proj_b_a_perp[1])<5.371e8 and abs(proj_b_a_perp[2])<5.3718){
      std::cout << proj_b_a_perp << std::endl;
      std::cout << "." << std::endl;
  }


}
