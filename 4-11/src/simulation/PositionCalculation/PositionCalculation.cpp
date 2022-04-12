
#include "PositionCalculation.hpp"

#include <cmath>
#include <iostream>


std::vector<double> PositionCalculation::Calculate_lat_and_long(std::vector<double> EarthPos,
						   std::vector<double> MoonPos){

  const double PI = 3.14159265;

  double R_e = 6.371e6;
  double x_e = EarthPos.at(0);
  double y_e = EarthPos.at(1);
  double z_e = EarthPos.at(2);
  
  double x_m = MoonPos.at(0);
  double y_m = MoonPos.at(1);
  double z_m = MoonPos.at(2);

  double theta_m_rad = atan((pow(pow(x_m,2)+pow(y_m,2),1.0/2.0))/z_m);
  double phi_m_rad = this->phi(x_m, y_m);

  double D_x = x_e*sin(theta_m_rad)*cos(phi_m_rad);
  double D_y = y_e*sin(theta_m_rad)*sin(phi_m_rad);
  double D_z = z_e*cos(theta_m_rad);
  double D = D_x + D_y + D_z;

  double dist_sun_2_earthSurface = D - (pow((pow(D,2) + pow(R_e,2) - pow(x_e,2)-pow(y_e,2)-pow(z_e,2)),1.0/2.0));

  // Spot on earth where shadow is hitting
  double x_d = x_e - dist_sun_2_earthSurface * sin(theta_m_rad) * cos(phi_m_rad);
  double y_d = y_e - dist_sun_2_earthSurface * sin(theta_m_rad) * sin(phi_m_rad);
  double z_d = z_e - dist_sun_2_earthSurface * cos(theta_m_rad);

  /*
  std::cout << "ANGLES_m: " << theta_m_rad << " " << phi_m_rad << " \n";
  std::cout << "MEH1: " << x_d << "   "<< y_d << " " << z_d << "\n";
  std::cout << "MEH2: " << x_e << "   "<< y_e << " " << z_e << "\n";
  */
  
  double rho_d = pow(pow(x_d,2)+pow(y_d,2)+pow(z_d,2),1.0/2.0);
  double theta_d_rad =  atan(pow(pow(x_d,2)+pow(y_d,2),1.0/2.0)/z_d);
  double phi_d_rad = this->phi(x_d, y_d);

  /*
  std::cout << "D: " << D << "\n";
  std::cout << "dist: " << dist_sun_2_earthSurface << "\n";
  std::cout << "ANGLES_d: " << theta_d_rad << " " << phi_d_rad << " \n";
  std::cout << "RADIUS: " << rho_d << "\n";
  */

  double latitude_on_earth = 0;
  double longitude_on_earth = 0;

  if(theta_d_rad >= (PI/2.0))
    {
      latitude_on_earth = (PI/2.0)-theta_d_rad;
    }
  else
    {
      latitude_on_earth = -(PI/2.0) + theta_d_rad;
    }

  if(phi_d_rad<0)
    {
      longitude_on_earth = phi_d_rad+2*PI;
    }
  else
    {
      longitude_on_earth = phi_d_rad;
    }
  
  

  std::vector<double> results;
  results.push_back(latitude_on_earth);
  results.push_back(longitude_on_earth);
  
  return results;
  
}

double PositionCalculation::phi(double x_m, double y_m){
  const double PI = 3.14159265;
  
  if(x_m>0)
    {
    return atan(y_m/x_m);
    }
  else if(x_m<0 and y_m>=0)
    {
      return atan(y_m/x_m)+PI;
    }
  else if(x_m<0 and y_m<0)
    {
      return atan(y_m/x_m)-PI;
    }
  else if(x_m==0 and y_m>0)
    {
      return PI/2.0;
    }
  else if(x_m==0 and y_m<0)
    {
      std::cout << "YEPPERS!\n";
      return -PI/2.0;
    }
  else
    {
      std::cout << "UNDEFINED PHI ANGLE!" << "\n";
    }

}
