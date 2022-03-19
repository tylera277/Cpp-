
//Date: 3/19/2022
//Goal: Multiply two numbers entered in terminal

#include "main.h"


int main(int argc, char **argv){

  // Get the numbers values from the terminal
  Numbers *numbers =  parse(argc, argv);

  // Multiply the numbers together
  int sum = multiply(numbers);

  // Print out the product to the terminal
  print(sum);
  
  return 0;
}
