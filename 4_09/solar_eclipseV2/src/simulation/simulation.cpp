
#include <iostream>
#include <fstream>
#include <cmath>
#include <Eigen/Dense>

#include "simulation.hpp"
#include "rungekutta/rungekutta.hpp"
#include "stormerverlet/stormerverlet.hpp"
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
  EarthPos.push_back(-2.612780096546947e10);
  EarthPos.push_back(1.447690394649218e11);
  EarthPos.push_back(-6.818981980018318e6);

  MoonPos.push_back(-2.621966950910588e10);
  MoonPos.push_back(1.444221966223293e11);
  MoonPos.push_back(-1.481725083564967e7);
  //MoonPos.push_back(1.365829786759039e8);
  //MoonPos.push_back(3.784672542630986e8);
  //MoonPos.push_back(1.100873808192814e7);
}
void Simulation::initialize_velocities(){
  EarthVel.push_back(-2.981220585156541e4);
  EarthVel.push_back(-5.400900344650754e3);
  EarthVel.push_back(1.529691363091334e0);

  MoonVel.push_back(-2.875116306376557e4);
  MoonVel.push_back(-5.658509151145958e3);
  MoonVel.push_back(-9.393652162458199e1);
  //MoonVel.push_back(-9.055845652878003e2);
  //MoonVel.push_back(3.497206573428444e2);
  //MoonVel.push_back(8.484556310373507e1);
}

void Simulation::update_earths_position_rk(double dt){
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

void Simulation::update_moons_position_rk(double dt){
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


void Simulation::update_earths_position_sv(double dt){

  StormerVerlet sv;
  
  double x1 = EarthPos.at(0);
  double y1 = EarthPos.at(1);
  double z1 = EarthPos.at(2);
  
  double x2 = 0;
  double y2 = 0;
  double z2 = 0;
  
  double vx1 = EarthVel.at(0);
  double vy1 = EarthVel.at(1);
  double vz1 = EarthVel.at(2);
  
  double G = 6.67e-11;
  double center_mass = 1.989e30;

    
    
    
     
  double oldxAcceleration = sv.computeXAccel(x1,y1,z1,x2,y2,z2,center_mass);
  double oldyAcceleration = sv.computeYAccel(x1,y1,z1,x2,y2,z2,center_mass);
  double oldzAcceleration = sv.computeZAccel(x1,y1,z1,x2,y2,z2,center_mass);

  x1 += vx1*dt + (1.0/2.0) * oldxAcceleration * pow(dt,2);
  y1 += vy1*dt + (1.0/2.0) * oldyAcceleration * pow(dt,2);
  z1 += vz1*dt + (1.0/2.0) * oldzAcceleration * pow(dt,2);
  

  double newxAcceleration = sv.computeXAccel(x1,y1,z1,x2,y2,z2,center_mass);
  double newyAcceleration = sv.computeYAccel(x1,y1,z1,x2,y2,z2,center_mass);
  double newzAcceleration = sv.computeZAccel(x1,y1,z1,x2,y2,z2,center_mass);
     
  vx1 += (1.0/2.0) * (oldxAcceleration + newxAcceleration) * dt;
  vy1 += (1.0/2.0) * (oldyAcceleration + newyAcceleration) * dt;
  vz1 += (1.0/2.0) * (oldzAcceleration + newzAcceleration) * dt;

  EarthPos.clear();
  EarthPos.push_back(x1);
  EarthPos.push_back(y1);
  EarthPos.push_back(z1);
  
  EarthVel.clear();
  EarthVel.push_back(vx1);
  EarthVel.push_back(vy1);
  EarthVel.push_back(vz1);


	
}



void Simulation::update_moons_position_sv(double dt){
  StormerVerlet sv;
  
  double x1 = MoonPos.at(0);
  double y1 = MoonPos.at(1);
  double z1 = MoonPos.at(2);
  
  double x2 = EarthPos.at(0);
  double y2 = EarthPos.at(1);
  double z2 = EarthPos.at(2);
  
  //double x2 =0;
  //double y2 = 0;
  //double z2 = 0;
  
  double vx1 = MoonVel.at(0);
  double vy1 = MoonVel.at(1);
  double vz1 = MoonVel.at(2);
  
  double G = 6.67e-11;
  double earth_mass = 5.972e24;
  double sun_mass = 1.989e30;

    
    
    
     
  long double oldxAcceleration = sv.computeXAccel(x1,y1,z1,x2,y2,z2,earth_mass);
  double oldyAcceleration = sv.computeYAccel(x1,y1,z1,x2,y2,z2,earth_mass);
  double oldzAcceleration = sv.computeZAccel(x1,y1,z1,x2,y2,z2,earth_mass);

  oldxAcceleration += sv.computeXAccel(x1,y1,z1,0,0,0,sun_mass);
  oldyAcceleration += sv.computeYAccel(x1,y1,z1,0,0,0,sun_mass);
  oldzAcceleration += sv.computeZAccel(x1,y1,z1,0,0,0,sun_mass);


  x1 += (vx1*dt + (1.0/2.0) * oldxAcceleration * pow(dt,2));
  y1 += (vy1*dt + (1.0/2.0) * oldyAcceleration * pow(dt,2));
  z1 += (vz1*dt + (1.0/2.0) * oldzAcceleration * pow(dt,2));
  

  double newxAcceleration = sv.computeXAccel(x1,y1,z1,x2,y2,z2,earth_mass);
  double newyAcceleration = sv.computeYAccel(x1,y1,z1,x2,y2,z2,earth_mass);
  double newzAcceleration = sv.computeZAccel(x1,y1,z1,x2,y2,z2,earth_mass);

  newxAcceleration += sv.computeXAccel(x1,y1,z1,0,0,0,sun_mass);
  newyAcceleration += sv.computeYAccel(x1,y1,z1,0,0,0,sun_mass);
  newzAcceleration += sv.computeZAccel(x1,y1,z1,0,0,0,sun_mass);
     
  vx1 += ((1.0/2.0) * (oldxAcceleration + newxAcceleration) * dt);
  vy1 += ((1.0/2.0) * (oldyAcceleration + newyAcceleration) * dt);
  vz1 += ((1.0/2.0) * (oldzAcceleration + newzAcceleration) * dt);

  MoonPos.clear();
  MoonPos.push_back(x1);
  MoonPos.push_back(y1);
  MoonPos.push_back(z1);
  
  MoonVel.clear();
  MoonVel.push_back(vx1);
  MoonVel.push_back(vy1);
  MoonVel.push_back(vz1);


	
}




double Simulation::determine_if_solar_eclipse(double time){
    
  Eigen::Vector3d earth(EarthPos.at(0), EarthPos.at(1), EarthPos.at(2));
  Eigen::Vector3d moon(MoonPos.at(0), MoonPos.at(1), MoonPos.at(2));

  
  double a_b_dot = earth.dot(moon);
  double b_b_dot = moon.dot(moon);
  
  double inner_fraction = a_b_dot / b_b_dot;
  
  Eigen::Vector3d proj_b_a_parallel = inner_fraction * moon;
    
  Eigen::Vector3d proj_b_a_perp = earth - proj_b_a_parallel;
  
  
  
  if(abs(proj_b_a_perp.norm())<((6.371e6))){
      std::cout << proj_b_a_perp << std::endl;
      std::cout << "NORM: " << proj_b_a_perp.norm() << std::endl;
      std::cout << "TIME: " << time/86400.0 << std::endl;
      std::cout << "." << std::endl;
  }


}

void Simulation::export_position_data_to_csv(std::string filename1){
  std::ofstream myfile;
  myfile.open(filename1, std::ios::app);
  myfile << EarthPos.at(0) << "," << EarthPos.at(1) << "," << EarthPos.at(2) <<",";
  myfile << MoonPos.at(0) << "," << MoonPos.at(1) << "," << MoonPos.at(2) << std::endl;
  myfile.close();


}
