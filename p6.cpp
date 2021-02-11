#include <iostream>

uint64_t SumOfSquares(uint64_t n) {
  uint64_t sum = 0;
  for (int i=1;i<=n;++i) {
    sum += i*i;
  }
  std::cout << sum << '\n';
  return sum;
}

uint64_t SquareOfSum(uint64_t n) {
  uint64_t sum = n*(n+1)/2;
  std::cout << sum*sum << '\n';
  return sum*sum;
}

int main() {
  const uint64_t n = 100;
  int sumsq = SumOfSquares(n); 
  int sqsum = SquareOfSum(n);
  std::cout << std::abs(sumsq-sqsum) << '\n';

  return 0;
}

