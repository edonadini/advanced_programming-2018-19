#include <iostream>
#include <array>
#include <string>
#include <vector>

enum class month { 
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

using namespace std;
void mfind(const month r){
  switch(r){
    case month::jan:
    cout<<"Gennaio"<<endl;
    break;
    default:
    cout<<"non gennaio"<<endl;
  }

};
vector<string> mesiprint={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
//ostream& operator<<(ostream & os,month& m)
  //{
    //return os << mesiprint[int(m)]<<endl;
  //}
int x = 20;

int main() {
  cout<<&x<<endl;
  x = 12;
  cout<<&x<<endl;
  int f=5;
  cout<<&f<<endl;
  array < string,12> mesi{"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  cout << &mesi[int(month::nov)]<<endl;
  cout << static_cast<int>(month::dec) <<endl;
  cout << &mesiprint[int(month::jan)-1]<<endl;
  
  return 0;
}
