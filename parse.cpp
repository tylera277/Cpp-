

#include <sstream>
#include <iostream>

#include "main.h"


Numbers *parse(int argc, char **argv){

  Numbers *numbers = NULL;
  

  if(argc!=3){
    std::cerr << "Too many/Not enough numbers entered!" << std::endl;
  }
  else{
    numbers = new Numbers;
    numbers -> number1 = 0;
    numbers -> number2 = 0;

    {
      std::istringstream stream(argv[1]);
      stream >> numbers->number1;
    }
    {
      std::istringstream stream(argv[2]);
      stream >> numbers->number2;
    }
    
  }

  return numbers;

};



