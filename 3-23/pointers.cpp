
#include <iostream>


int main(){

  int array[] = {11,22,33,44,55};

  int length_of_array = sizeof(array)/sizeof(array[0]);
  
  
  for(int i=0; i<length_of_array; i++){
    std::cout<< "i=" << i <<"->"<< array[i]<< std::endl;

  }

  ///////////////////////////////////////////////
  std::cout << "//////////// NEW SECTION  ////////////" << std::endl;
  ///////////////////////////////////////////////

  int array2[] = {1,4,6,8,9};

  int length_of_array2 = sizeof(array2)/sizeof(array2[0]);
  int *starting_pointer = &array2[0];

  for(int i=0; i<length_of_array2;i++){
    std::cout << "i= " << i <<"->" << *(starting_pointer+i) << std::endl;

  }

  ///////////////////////////////////////////////
  std::cout << "//////////// NEW SECTION  ////////////" << std::endl;
  ///////////////////////////////////////////////


  int array3[] = {43,54,65,76};

  int *starting_point = &array3[0];

  int size_of_array = sizeof(array3) / sizeof(array3[0]);

  for(int i=0; i<size_of_array; i++){
    std::cout << &array3[i] << std::endl;
    
  }

  ///////////////////////////////////////////////
  std::cout << "//////////// NEW SECTION  ////////////" << std::endl;
  ///////////////////////////////////////////////

  int dist[7];
  int miles[]= {15, 22, 16, 18, 27, 23, 20};

  int length_of_miles = sizeof(miles) / sizeof(miles[0]);

  int iterator = 0;

  while(iterator < length_of_miles){
    dist[iterator] = miles[iterator];

    iterator += 1;
  }

  for(int i=0; i<7; i++){
    std::cout << dist[i] << std::endl;
  }
  
 
}

