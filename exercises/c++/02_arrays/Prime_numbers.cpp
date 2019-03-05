//
//  Prime_numbers.cpp
//  
#include <iostream>
#include <vector>


int main() {
    std::vector<unsigned int> prime_num{2};
    
    for (unsigned int i{3}; i<100; i=i+2){
        for (auto j=0u; j<=prime_num.size(); ++j){
            unsigned int* p=&prime_num[j];
            if(i%*p!=0){
                if(j==prime_num.size()-1){
                    prime_num.push_back(i);
                }
            }
            else{
                break;
            }
        }
    }
    for (const auto& x : prime_num)
        std::cout << x << " ";
    std::cout<<std::endl;
}
