

#include <iostream>


// Declaration section
class MathOperations
{
private:
  double sum;

public:
  MathOperations(double=0.0);
  void set_sum(double);
  void increment_sum();
  void print_sum();
  
};


// Implementation section
MathOperations::MathOperations(double number)
{
  sum = number;
}

void MathOperations::set_sum(double number)
{
  sum = number;
  std::cout << "Setting!" << std::endl;


}

void MathOperations::increment_sum()
{
  sum += 1;
  std::cout << "Incrementing!" << std::endl;

}

void MathOperations::print_sum()
{
  std::cout << "Sum is: " << sum << std::endl;

}


////////////////////////////

int main(){
  
  MathOperations math;
  math.set_sum(5.0);
  math.print_sum();
  math.increment_sum();
  math.print_sum();
 



/////////////

  std::cout << "//////////// NEW SECTION ////////////" << std::endl;

////////////


  int random_number = rand();

  std::cout << random_number << std::endl;

}
