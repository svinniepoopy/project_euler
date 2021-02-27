#include <iostream>


// generate pascal's triangle 
uint64_t LatticePaths(int n) {
  // create a n+1xn+1 grid
  uint64_t grid[n+1][n+1];
  grid[0][0] = 1;
  // fill the border columns and rows
  for (int i=0;i<=n;++i) {
    grid[0][i] = 1;
    grid[i][0] = 1;
  }

  for (int i=1;i<=n;++i) {
    for (int j=1;j<=n;++j) {
      /*std::cout << "filling " << "[" << i << ',' << j << "]" << 
	i << ',' << j-1 << " " << i-1 << ',' << j << '\n';*/
      grid[i][j] = grid[i][j-1] + grid[i-1][j];
    }
  }

  for (int i=0;i<n;++i) {
    for (int j=0;j<n;++j) {
      std::cout<< grid[i][j] << " ";
    }
    std::cout << '\n';
  }

  for (int i=0;i<n;++i) {
    std::cout << grid[i][i] << '\n';
  }

  
  return grid[n-1][n-1];

}

int main() {
  std::cout << LatticePaths(21) << std::endl;
  return 0;
}
