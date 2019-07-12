#include <iostream>

struct X {
  char member;
  public:
  explicit X(char s): member(s) {}
  //int f;
};

int main() {
  X x1('d');
  //x1.member='d';
  std::cout<<int('d')<<std::endl;

  X x2{x1};             // copy ctor
  X x3{std::move(x2)};  // move ctor
  X x4 (' ');           
  x4 = x3;              // copy assignment
  X x5 (' ');               
  x5 = std::move(x4);   // move assignment
  std::cout << &(x1.member) << std::endl; //ddddd
  std::cout << &x2.member << std::endl; //dddd
  //std::cout << &x3.member << std::endl;
  std::cout << &x4.member << std::endl; //dd
  std::cout << &x5.member << std::endl; //d
  std::cout << &x3.member << std::endl; //ddd

  std::cout << &x3 << std::endl;
  std::cout << &x1 << std::endl;
  std::cout << &x2 << std::endl;
  std::cout << &x4 << std::endl;
  std::cout << &x5 << std::endl;

  return 0;
}
