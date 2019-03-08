#include<iostream>
#include<vector>
#include<string>


int main(){

  std::cout<< "Insert a sequence of words, type 'stop' to end: " << std::endl;
  std::vector<std::string> seq;
  
  std::string s;
  while(std::cin >> s && s != "stop"){

    seq.push_back(s);

  }

  std::cout<< "----------\n";

  std::string prev = "";
  
  for(int i{0}; i < seq.size(); i++ ){
    if(seq[i] != prev) {
       std::cout<< seq[i] << std::endl;
       prev = seq[i];
    }
  }

}
