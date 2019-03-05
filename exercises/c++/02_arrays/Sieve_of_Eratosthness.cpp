//
//  Sieve_of_Eratosthness.cpp
//  
#include<iostream>
#include<cmath>

/*Function that prints the array and only the non-zero elements */
void printarray (int *array, size_t size) {
    for (size_t k{0}; k<size; k++){
        if (array[k]!=0) std::cout << array[k] << '\t';
    }
    std::cout << '\n';
}

int main() {
    int num;
    std::cout << "Insert the value: ";
    std::cin >> num;
    
    /*Inizialize the array */
    int dim = num -1;
    int* array{new int[dim]};
    int cont=2;
    for (int i{0}; i<dim; i++){
        array[i]=cont;
        cont++;
    }
    
    /*Compute the root of the number */
    int bound = sqrt(num);
    
    int i = 0;
    while (array[i]<=bound && array[i]!=0) {
        for (int k{0}; k<=dim; k++) {
            if ((array[k]%array[i]==0) && (array[k]!=array[i]))
            {
                array[k]=0;
            }
        }
        i++;
    }
    printarray(array,(size_t)num-1);
    delete [] array;
    return 0;
}
