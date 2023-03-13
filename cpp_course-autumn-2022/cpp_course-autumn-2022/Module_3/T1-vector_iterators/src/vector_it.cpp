#include "vector_it.hpp"

#include <iostream>
#include <vector>

// Implement the functions here

std::vector<int> ReadVector() {
  std::vector<int> v;
  int in;
  while(std::cin >> in){
    v.push_back(in);
  }
  return v;
}
void PrintSum1(const std::vector<int>& v) {
  for (std::vector<int>::const_iterator it = v.begin(); it!=v.end() -1; it++){
    std::cout << *it + *(it + 1) << " ";
  }
  std::cout << std::endl;
}

void PrintSum2(const std::vector<int>& v) {
  std::vector<int>::const_iterator end = v.end() -1 ;
  for( std::vector<int>::const_iterator beg = v.begin(); beg < (v.end() - (v.size()/2)) && beg != end; beg++, end = end - 1){
    std::cout << *beg + *end << " ";
  }
  std::cout << std::endl;
}
