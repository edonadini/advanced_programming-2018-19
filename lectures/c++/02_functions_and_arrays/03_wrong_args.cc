#include <iostream>

void swap(int a, int b);
int swapx(int a, int b);
int swapy(int a, int b);

int main() {
  int x{3}, y{7};
  std::cout << "before\t" << x << " " << y << std::endl;//3 7
  std::cout << "before\t" << &x << " " << &y << std::endl;//0x7ec 0x7f0
  
  int t{x};
  x = y;
  y = t;
  std::cout << "after swap nel main\t" << x << " " << y << " " << t <<std::endl;//7 3 3 ottengo lo swap se non uso la funzione swap
  std::cout << "after swap nel main\t" << &x << " " << &y << " " << &t <<std::endl;//0x7ec 0x7f0 0x7f4
  //prima e dopo lo swap x e y mantengono il proprio indirizzo di memoria
  swap(x, y);
  std::cout << "after funzione void swap\t" << x << " " << y << std::endl;//7 3
  std::cout << "after funzione void swap\t" << &x << " " << &y <<std::endl;//0x7ec 0x7f0
  
  std::cout << "after funzioni di swap con return\t" << x << " " << y << std::endl;//3 7
  //osservo che é avvenuto lo swap
  swapa(x,y);
  swapb(x,y);
  std::cout << "dopo aver chiamato le funzioni di swap con return\t" << x << " " << y << std::endl;//7 3
  //noto che anche in questo caso non modifico il valore di x e y
  return 0;
}

void swap(int a, int b) {
  int t{a};
  a = b;
  b = t;
  std::cout << "nella funzione\t" << a << " " << b << " " << t <<std::endl;//3 7 7
  //nella funzione avviene lo swap
}

void swapx(int a, int b) {
  int t{a};
  a = b;
  b = t;
  return a;
}

void swapy(int a, int b) {
  int t{a};
  a = b;
  b = t;
  return b;
}


