

#include <iostream>
#include <array>


template<typename T, std::size_t SIZE>
void print_transpose(std::array<T, SIZE> mat ,int n_row , int n_col)
{

  std::array<T, mat.size()> trans;
  
  for(int j{0}; j < n_row; j++){
   for(int i{0}; i < n_col; i++){
     
     trans[j + (i*n_row)] = mat[i + (j*n_col)];
     
   }
 }

  std::cout << "Transposed matrix:\n";
  for(int i{0}; i < mat.size() ; i++){

      std::cout << trans[i] << std::endl;

    }

}




int main(){

  
  std::array<int, 12> mat;

  for(int i{0}; i < mat.size(); i++){
     mat[i] = i;
  
  }
  
  print_transpose<int>(mat, 3, 4);
 

  return 0;

}
