#include <iostream>

int main () 
{
    float x, in, cm, f, ya, m;
    char ch=0;

    std::cout<<"enter a length (unit:i, f, y, c): ";
    std::cin>>x;
    std::cin>>ch;

    switch(ch){
        case 'i':
            in = x;
            m = x*0.0245;
            std::cout<<in<<" inch = "<<m<<" m\n";
            break;
        case 'y':
            ya = x;
            m = x*0.9144;
            std::cout<<ya<<" yard = "<<m<<" m\n";
            break;
        case 'f':
            f = x;
            m = x*0.3048;
            std::cout<<f<<" foot = "<<m<<" m\n";
            break;
        case 'c':
            cm = x;
            m = x*0.01;
            std::cout<<cm<<"cm = "<<m<<" m\n";
            break;
        default:
            std::cout<<"invalid expression\n";
            break;
            }
return 0;
}
