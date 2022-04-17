#include "MiscTools.hpp"

#include <iostream>
#include <fstream>


void MiscTools::clear_file(std::string filename1)
{

  std::ofstream myfile;
  myfile.open(filename1, std::ios::trunc);
  myfile <<"\n";
  myfile.close();
}
/*
std::string MiscTools::ConvertSecondsToDate(std::string start_date, double seconds)
{
  //return seconds/86400.0;
}
*/

