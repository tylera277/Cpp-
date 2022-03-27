#include <iostream>

using namespace std;


class CarModels{
private:
  string make;
  int year;
  double mileage;
  
  
public:
  CarModels(string="",int=0,double=0);
  void set_make(string);
  void set_year(int);
  void set_mileage(double);

  void print_make();
  void print_year();
  void print_mileage();

};

CarModels::CarModels(string makeName, int yearNumber, double mileageNumber){
  make = makeName;
  year = yearNumber;
  mileage = mileageNumber;
}

void CarModels::set_make(string makeName){
  this->make = makeName;
}
void CarModels::set_year(int yearNumber){
  this->year = yearNumber;
}
void CarModels::set_mileage(double mileageNumber){
  this->mileage = mileageNumber;
}

void CarModels::print_make(){
  cout <<"Make: "<< this->make << endl;
}
void CarModels::print_year(){
  cout << "Year: " << this->year << endl;
}
void CarModels::print_mileage(){
  cout << "Mileage:" <<  this->mileage << endl;
}


int main(){

  CarModels car1, car2;

  car1.set_make("Ford");
  car1.set_year(2003);
  car1.set_mileage(1002.0);

  car1.print_make();
  car1.print_year();
  car1.print_mileage();

  
  car2.set_make("Tesla");
  car2.set_year(2022);
  car2.set_mileage(1002.0);

  car2.print_make();
  car2.print_year();
  car2.print_mileage();


  
}
