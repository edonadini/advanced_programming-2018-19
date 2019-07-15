#include<iostream>
#include<algorithm> //std::copy
#include<memory>

template <typename T>
class Vector{
  T i;
  std::shared_ptr<T[]> p;
  public:
  explicit Vector(const std::size_t l): i(l), p(new T[i]{}) {}
  Vector() {} //default constructor
  //~Vector() noexcept {delete() p} non e' necessario perche' unique pointer
  ~Vector() noexcept =default;

  //copy constructor
  Vector(const Vector& v);

  //copy assignment
  Vector& operator=(const Vector& v);

  //move constructor
  Vector(Vector && v): i(v.i), p(v.p) 
    {
      v.i=0;
      v.p.reset();
    }

  //move assignment
  Vector& operator=(Vector&& v);

  //lunghezza del vettore
  const std::size_t size() const noexcept {return i;}
  //elementi del pointer
  const T& operator[](const std::size_t i) const noexcept {return p[i];}
  T& operator[](const std::size_t i) noexcept {return p[i];}

  // range-for
  const T* begin() const noexcept { return p.get(); }
  T* begin() noexcept { return p.get(); }

  const T* end() const noexcept { return p.get() + i; }
  T* end() noexcept { return p.get() + i; }
};


//copy constructor
template <typename T>
Vector<T>::Vector(const Vector& v): i(v.i), p(new T[i]) {std::copy(v.begin(),v.end(),begin());}

//copy assignment
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& v){
  std::shared_ptr<T[]> q{new T[v.i]};
  std::copy(v.begin(),v.end(),q.get());
  p.reset();
  p=nullptr; //necessario?
  p=q;
  i=v.i;
  return *this;
}
//move assignment
template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& v)
{
  p.reset();
  p=nullptr;
  p=v.p;
  i=v.i;
  v.p=nullptr;
  v.i=0;
  return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v){
  for(const auto& x:v)
    os<< x<<" ";
    os <<std::endl;
    return os;
}


int main(){
Vector<int> a {3};
for(int x=0; x<=a.size();x++) a[x]=x+90;

Vector<int> b(a);//copy constructor
a[2]=9;
std::cout<<a<<std::endl;
std::cout<< b <<std::endl;

Vector<int> c {5};
c=a; //copy assignment
std::cout<<c<<std::endl;

//move constructor
int lung{15};
//Vector<int> d=fill(lung);
//std::cout<<d<<std::endl;


return 0;
};