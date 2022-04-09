
#include "stormerverlet.hpp"

#include <cmath>


double StormerVerlet::computeXAccel(double x1, double y1, double z1, double x2, double y2, double z2, double center_mass){
  double G = 6.67e-11;
  double a_x = (G*center_mass*(x2-x1))/pow((pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2)),1.5);

  return a_x;
}

double StormerVerlet:: computeYAccel(double x1, double y1, double z1, double x2, double y2, double z2, double center_mass){
  double G = 6.67e-11;
  double a_y = (G*center_mass*(y2-y1))/pow((pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2)),1.5);

  return a_y;
}

double StormerVerlet::computeZAccel(double x1, double y1, double z1, double x2, double y2, double z2, double center_mass){
  double G = 6.67e-11;
    
  double a_z = (G*center_mass*(z2-z1))/pow((pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2)),1.5);

  return a_z;
	
}
