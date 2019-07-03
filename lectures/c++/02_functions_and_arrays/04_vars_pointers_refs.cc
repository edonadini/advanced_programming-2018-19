#include <iostream>

int main() {
  double d{9.9};
  double& ref{d};
  double* ptr{&d};//double* ptr{&d} is wrong
  std::cout << "content of\t   d: " << d << std::endl;//9.9
  std::cout << "content of\t ref: " << ref << std::endl;//9.9
  std::cout << "content of\t ptr: " << ptr << std::endl << std::endl;//0x7fff08943dd8
  
  std::cout << "se deferenzio \t ptr: " << *ptr << std::endl << std::endl;//9.9
  std::cout << "address of\t ptr deferenziato: " << &*ptr << std::endl << std::endl;//0x7fff08943dd8
  std::cout << "address of\t ptr deferenziato: " << *&ptr << std::endl << std::endl;//0x7fff08943dd8
  std::cout << **&ptr << std::endl << std::endl;//9.9
  std::cout << *&*ptr << std::endl << std::endl;//9.9
  std::cout << &**ptr << std::endl << std::endl;//non é corretto

  std::cout << "address of\t   d: " << &d << std::endl;//0x7fff08943dd8
  std::cout << "address of\t ref: " << &ref << std::endl;//0x7fff08943dd8
  std::cout << "address of\t ptr: " << &ptr << std::endl << std::endl;//0x7fff08943de0
 
  std::cout << *d << std::endl<< std::endl; //non é corretto
  std::cout << *ref << std::endl<< std::endl; //non é corretto
  std::cout << **ptr << std::endl << std::endl;//non é corretto (in generale non posso aggiungere piú stelline)
  std::cout << ***&ptr << std::endl << std::endl;//non é corretto
  std::cout << *&*&ptr << std::endl << std::endl;//0x7fff08943dd8
  
  //sembra che le operazioni di & e * siano complementari per i pointer
  //non posso infatti deferenziare referenze e variabili

  // the content of variable d can be changed through either ref or
  // ptr as follows
  ref = 7.7;
  std::cout << "ref = 7.7;\n";
  std::cout << "content of\t   d: " << d << std::endl << std::endl;//7.7
  *ptr = 5.5;
  std::cout << "*ptr = 5.5;\n";
  std::cout << "content of\t   d: " << d << std::endl << std::endl;//5.5

  // but not from another variable of the same type
  double copy{d};
  std::cout << "content of\tcopy: " << copy << std::endl << std::endl;//5.5

  copy = 0;
  std::cout << "copy = 0;\n";//0
  std::cout << "content of\tcopy: " << copy << std::endl;//0
  std::cout << "content of\t   d: " << d << std::endl;//5.5
}
