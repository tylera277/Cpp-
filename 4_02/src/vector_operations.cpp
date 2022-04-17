

#include <vector>
#include <iostream>

#include "vector.hpp"

using namespace std;



vector<double> add(vector<double> a, vector<double> b){
  vector<double> result;
  
  for(int i=0; i < a.size(); i++){
    result.push_back(a.at(i) + b.at(i));
  }
  cout << "ADDING" << endl;
  return result;
}

vector<double> subtract(vector<double> a, vector<double> b){
  vector<double> result;
  
  for(int i=0; i < a.size(); i++){
    result.push_back(a.at(i) - b.at(i));
  }
  
  return result;
}

double dot_multiply(vector<double> a, vector<double> b){
  double result;
  
  for(int i=0; i < a.size(); i++){
    result += (a.at(i)*b.at(i));
  }
  return result;
}

vector<double> scalar_multiply(double scalar, vector<double> a){
  vector<double> result;
  
  for(int i=0; i < a.size(); i++){
    result.push_back(scalar*a.at(i));
  }
  return result;
}

void print_vector(vector <double> a) {
   cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++){
   cout << a.at(i) << ' ';
   }
   cout << endl;
}
