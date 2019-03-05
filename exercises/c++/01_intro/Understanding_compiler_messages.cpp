//
//  Understanding_compiler_messages.cpp
//
#include<iostream>
int sum (int a, int b) {
    return a+b;
}

int main() {
    int c=2;
    std::cout << "Hello world\n " << c <<" "<< sum(3, 3)<<std::endl;
    
    return 0;
}

/*
 if std:c0out << "Hello world\n"...;      --> the error: no member named 'c0out' in namespace 'std'; did you mean 'cout'?
 if std::cout << "Hello world\n" << e...; --> the error: use of undeclared identifier 'e'
 if I don't put ;                         --> the error: expected ';' at end of declaration
 if I forget to #include <iostream>       --> the error: use of undeclared identifier 'std'
 if I declare int double {0}              --> the error: cannot combine with previous 'int' declaration specifier
 if I call the function sum with (3)      --> the error: No matching function for call to 'sum'
 */
