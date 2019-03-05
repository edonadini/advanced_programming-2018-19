//
//  Uniq.cpp
//
#include <iostream>

int main() {
    std::cout << "insert a text:\n";
    std::string text,text1;
    int count{1};
    getline(std::cin,text);
    text1=text;
    while(std::getline(std::cin,text))
    {
        if (text==text1) count++;
        else {
            std::cout << text1<<  " is repeated consecutively " << count<<std::endl;
            text1=text;
            count = 1;
        }
    }
    return 0;
}
