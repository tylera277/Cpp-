
#ifndef MAIN_H_
#define MAIN_H_


struct Numbers{
  int number1;
  int number2;
};


Numbers *parse(int argc, char ** argv);

int multiply(Numbers *numbers);

void print(int number);



#endif
