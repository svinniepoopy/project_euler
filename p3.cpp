#include <cstdint>
#include <vector>
#include <iostream>
#include <bitset>
#include <cmath>
#include <climits>

int64_t largestPrimeFactor(int64_t n) {

  int64_t sq = std::sqrt(n);
  int64_t last = 1; 
  for (int i=3;i<=sq;i+=2) {
    while (n%i == 0) {
      last = i;
      n = n/i;
    }
  }
  return last;
}

int main() {
  int64_t n = 600851475143; 
  std::cout << largestPrimeFactor(n) << '\n';
  return 0;
}
