#include <iostream>

int main() {
  double* vect{new double};
  double* point=vect;
  *vect=7.6;
  std::cout<<vect[0]<<std::endl; //7.6
  std::cout<<vect<<std::endl;//0x556a286abe70
  std::cout<<&vect<<std::endl;//0x7ffec9d15498
  std::cout<<*point<<std::endl;//7.6
  std::cout<<point<<std::endl;//0x556a286abe70
  delete vect;
  *point=4.6;
  std::cout<<*vect<<std::endl;//4.6
  std::cout<<vect<<std::endl;//0x556a286abe70
  delete [] point;

  //free(): double free detected in tcache 2
  //Aborted (core dumped)
  double d{7.7};
  double * p{&d};
  std::cout<<*p<<std::endl;
  return 0;
}
