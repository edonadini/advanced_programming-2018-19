#include<algorithm>
#include<vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;



double mean(vector<double> v){

  double sum{0};
  
  for(int i{0}; i < v.size(); i++){

    sum = sum + v[i];

  }

  double m = sum / v.size();
  
  return m;

}


double median(vector<double> v){

  sort(v.begin(), v.end());

  double med;
 
  if(v.size()%2 != 0){
    med = v[(v.size() + 1 )/2];

  }
   else {
     double med1 = v[v.size()/2];
     double med2 = v[(v.size()/2)+1];
     med = (med1 + med2)/2;
    

     }

  return med;
}


int main()
  {
    vector<double> v;
    string line;
   
  ifstream myfile( "temperatures.txt" );
  if (myfile)  
    {
      while (getline( myfile, line )) 
      {
        double val = stod(line);
	  v.push_back(val);
        
      }
      
    myfile.close();
    
    }



  double m = mean(v);
  double med = median(v);

  cout<< "The mean of the values is: "<< m << endl << "The median value is: " << med << endl;
  
  
  return 0;
  }



