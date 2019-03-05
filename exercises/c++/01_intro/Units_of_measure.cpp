#include <iostream>
#include <cmath>



double conversion(double p){
    double conv;
    conv = p/39.370;
    return conv;
};

int main () {
    std::cout<< "How many inches do you want to convert in meters? "<<std::endl;
    double n_inch;
    std::cin>>n_inch;
    double n_meter=conversion(n_inch);
    std::cout<<n_inch<<" inches corrispond to "<<n_meter<<" meters "<<std::endl;
    return 0;
    
}
