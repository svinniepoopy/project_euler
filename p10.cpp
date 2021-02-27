#include <climits>
#include <vector>
#include <iostream>

namespace {
  using ull = unsigned long long;
  int TWO_MIL = 2000000;
  int N = TWO_MIL;
  std::vector<bool>* p = new std::vector<bool>(N+1, true);
}

uint64_t SumPrimes(int n) {
  auto& primes = *p;
  primes[0] = primes[1] = false;
  for (int i=2;i<=n;++i) {
    if (primes[i] && (uint64_t)i*i<=n) {
      for (uint64_t j=i*i;j<=n;j+=i) {
	primes[j] = false;
      }
    }
  }

  uint64_t sum=0;
  for (uint64_t i=2;i<=N;++i) {
    if (primes[i]) { 
      sum += i;
    }
  }
  return sum;
}

int main() {
  std::cout << SumPrimes(N) << '\n';
  return 0;
}
