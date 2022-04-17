
#include <iostream>
#include <vector>
#include <cmath>

#include "rungekutta.hpp"


const double G = 6.67e-11;


double RungeKutta::compute_x_accel(double x1, double y1, double z1, double center_mass){
  
  double a_x = (G*center_mass*(-x1))/(pow((pow(x1,2)+pow(y1,2)+pow(z1,2)),1.5));

        return a_x;
}

double RungeKutta::compute_y_accel(double x1, double y1, double z1,  double center_mass){

  
  double a_y = (G*center_mass*(-y1))/(pow((pow(x1,2)+pow(y1,2)+pow(z1,2)),1.5));

        return a_y;
}

double RungeKutta::compute_z_accel(double x1, double y1, double z1, double center_mass){

  
  double a_z = (G*center_mass*(-z1))/(pow((pow(x1,2)+pow(y1,2)+pow(z1,2)),1.5));

        return a_z;
}



