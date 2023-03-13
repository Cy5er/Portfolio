#include "matrix.hpp"

#include <iostream>
#include <vector>

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

// Assumes 'm' is a square matrix
Matrix ReadMatrix(int n) {
  std::vector< std::vector<int> > mat(n,std::vector<int>(n));
  for ( int i = 0; i<n ; i++){
    for( int j = 0; j < n; j++){
      std::cin >> mat[i][j];
    }
  }
  }

Matrix Rotate90Deg(const Matrix &m) {
  
  }

void Print(const Matrix &m) {
  int n = m[0].size();
  for ( int i = 0; i<n ; i++){
    for( int j = 0; j < n; j++){
      std::cout << (m[i][j]);
    }
  }
}
