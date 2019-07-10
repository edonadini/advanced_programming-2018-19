#include <array>
#include <iostream>
#include <vector>

struct Point_s {
  double x;
  double y;
  void print();
};  // note ; at the end

void Point_s::print() {
  std::cout << "Structure. x = " << x << "; y = " << y << std::endl;
}

class Point_c {
  double x;
  double y;

  static Point_c default_point;

 public:

  Point_c(double a=0,double c=0);
  //Point_c();

  void print() {
    std::cout << "Class. x = " << x << "; y = " << y << std::endl;
  }  // note no ; at the end
  static void set_default(double,double);
};   // note ; at the end



Point_c::Point_c(double d,double b)
{
  x=d? d:default_point.x;
  y=b? b:default_point.y;
}

Point_c Point_c::default_point(6.0,6.0);

void Point_c::set_default(double a,double b)
{
  Point_c::default_point=Point_c(a,b);
}

int main() {
  Point_s ps;
  ps.x = 9.9;
  ps.y = 3. / 7;

  ps.print();

  //Point_c pc;
  // pc.x =7.6; // error
  Point_c pc;
  pc.print();  // I can access private data through public functions

  Point_s* p = &ps;
  p->x = 0.0;
  p->print();

  auto& pr = ps;
  ++pr.x;
  pr.print();

  Point_s array_of_structs[8];  // built-in array
  array_of_structs[0].x = 1;
  array_of_structs[0].y = 2;

  std::array<Point_s, 5> as;
  as[3].x = 3;

  std::vector<Point_s> vs;
  vs.push_back(ps);
  vs[0].x = 999;
  ps.x = 11;
  ps.print();
  vs[0].print();

  return 0;
}
