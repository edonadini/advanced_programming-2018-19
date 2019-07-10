#include <iostream>

void swap(int a, int b);
int swapa(int a, int b);
int swapb(int a, int b);

int main() {
  int x{3}, y{7};
  std::cout << "before\t" << x << " " << y << std::endl;
  std::cout << "before\t" << &x << " " << &y << std::endl;
 
  //int t{x};
  
  //x = y;
  //y = t;

  //std::cout << "after\t" << x << " " << y << " e t "<< t<<std::endl;
  //std::cout << "before\t" << &x << " " << &y << " e t "<< &t<<std::endl;
  
  //swap(x,y);
  //std::cout << "se la funzione non ritorna\t" << x << " " << y << std::endl;
  //std::cout << "before\t" << &x << " " << &y << std::endl;
  
  //std::cout << "se le funzioni ritornano\t" << swapa(x,y)<< " " << swapb(x,y) << std::endl;
  //std::cout << "before\t" << &swapa(x,y)<< " " << &swapb(x,y) << std::endl;
  swapa(x,y);
  swapb(x,y);
  std::cout << "x,y dopo le funzioni di swap con ritorno\t" << x<< " " << y << std::endl;
  return 0;

}

void swap(int a, int b){
  int t{a};
  a = b;
  b = t;
  std::cout << "nella funzione\t" << a << " " << b << " "<< t<<std::endl;
}
int swapa(int a, int b){
  int t{a};
  a = b;
  b = t;
  return a;
}

int swapb(int a, int b){
  int t{a};
  a = b;
  b = t;
  return b;
}
