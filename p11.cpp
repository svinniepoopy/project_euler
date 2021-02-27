#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

namespace {
using Grid = std::vector<std::vector<int>>;
Grid grid = Grid(20, std::vector<int>(20, 0));

const int nrows = grid.size();
const int ncols = grid[0].size();
}

int MaxProductRight(const Grid& grid) {
  int max_prod = INT_MIN;
  for (int i=0;i<nrows;++i) { 
    for (int j=0;j+3<ncols;++j) { 
      int prod = 1;
      for (int p=0;p<4;++p) {
	prod = prod*grid[i][p+j];
      }
      max_prod = std::max(max_prod, prod);
    }
  }
  return max_prod;
}

int MaxProductDown(const Grid& grid) {
  int max_prod = INT_MIN;
  for (int i=0;i<ncols;++i) {
    for (int j=0;j+3<nrows;++j) {
      int prod = 1;
      for (int p=0;p<4;++p) {
	prod = prod*grid[p+j][i];
      }
      max_prod = std::max(max_prod, prod);
    }
  }
  return max_prod;;
}

int MaxProductDiag(const Grid& grid) {
  int max_prod = INT_MIN;
  for (int i=ncols-4;i>=0;--i) {
    for (int j=0;j+3<nrows;++j) {
      int prod = 1;
      for (int p=0;p<4;++p) {
	prod = prod*grid[p+j][i+p];
      }
      max_prod = std::max(max_prod, prod);
    }
  }
  return max_prod;
}

int MaxProductAntiDiag(const Grid& grid) {
  int max_prod = INT_MIN;
  for (int i=3;i<nrows;++i) {
    for (int j=0;j<ncols-3;++j) {
      int prod = 1;
      for (int p=0;p<4;++p) {
	prod = prod*grid[i-p][j+p];
      }
      max_prod = std::max(max_prod, prod);
    }
  }
  return max_prod;
}

int MaxProductGrid(const Grid& grid) { 
  std::vector<int> products(4);
  products[0] = MaxProductDown(grid);
  products[1] = MaxProductRight(grid);
  products[2] = MaxProductDiag(grid);
  products[3] = MaxProductAntiDiag(grid);
  return *std::max_element(products.begin(), products.end());
}

void ParseInput() {
  int i=0,j=0;
  for (std::string line; std::getline(std::cin, line);) { 
    int num;
    std::istringstream istr{line};
    while (istr>>num) {
      grid[i][j++] = num; 
    }
    j = 0;
    ++i;
  }
  assert(i==20);
}

int main() {
  ParseInput();
  std::cout << MaxProductGrid(grid) << '\n';

  return 0;
}
