//
//  Reverse_order.cpp
//  
#include <iostream>
​
​template <typename T>
​T* builder(const size_t& sz);
​
​template <typename T>
​void printer(const T* ar, const size_t& sz);
​
​int main() {
    ​std::cout<<"please insert array lenght: ";
    ​std::size_t sz;
    ​std::cin>>sz;
    ​//int* ar_int =builder<int>(sz);
    ​//printer<int>(ar_int, sz);
    ​//delete ar_int;
    ​double* ar_double =builder<double>(sz);
    ​printer<double>(ar_double,sz);
    ​delete ar_double;
    ​
    ​return 0;
    ​}
​
​template <typename T>
​T* builder(const size_t& s) {
    ​T* ar{new T[s]{}};
    ​T key = 0;
    ​for (std::size_t i{0};i<s; i++){
        ​std::cout <<"please insert a value: ";
        ​std::cin>>key;
        ​ar[i]=key;
        ​}
    ​return ar;
    ​}
​
​template <typename T>
​void printer(const T* ar, const size_t& sz){
    ​int counter=int(sz-1);
    ​std::cout <<"[";
    ​while (counter>=0){
        ​std::cout <<ar[counter--];
        ​counter+1!=0? std::cout<<",":std::cout<<"]"<<std::endl;
        ​}
    ​return;
    ​}
