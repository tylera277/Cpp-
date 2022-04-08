
#ifndef RUNGEKUTTA_HPP
#define RUNGEKUTTA_HPP


#include <vector>


class RungeKutta{
private:


public:

  double compute_x_accel(double, double, double, double);

  double compute_y_accel(double, double, double, double);
  
  double compute_z_accel(double, double, double, double);
 
};

#endif
