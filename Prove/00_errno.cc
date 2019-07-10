#include <cmath>
#include <iostream>
#include "std_lib_facilities.h"

int main() {
  int x{-9};
  double d = std::sqrt(x);
  std::cout << d << " " << errno <<std::endl;
  
  if(errno==EDOM) std::cout<< EDOM + 6 <<" ok"<<std::endl; //EDOM non ha un indirizzo in memoria
  if(x<=0) error(" radice di un numero negativo!");
  return 0;
}
