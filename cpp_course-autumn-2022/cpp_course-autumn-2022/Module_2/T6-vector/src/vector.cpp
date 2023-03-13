#include "vector.hpp"

#include <vector>

int GetMin(std::vector<int> v) {
  int min = v[0];
  for (unsigned int i = 1; i < v.size(); i++){
    if(min > v[i]){
      min = v[i];
    }
  }
  return min; 
}

int GetMax(std::vector<int> v) {
  int max = v[0];
  for (unsigned int i = 1; i < v.size(); i++){
    if(max < v[i]){
      max = v[i];
    }
  }
  return max;  
}

double GetAvg(std::vector<int> v) {
  double avg = 0.0;
  double total = 0.0;
  for (unsigned int i = 0; i < v.size(); i++){
    total = total + v[i];
    avg = total / v.size();
  }
  return avg;  
}
