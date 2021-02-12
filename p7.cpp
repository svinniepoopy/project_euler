#include <iostream>
#include <vector>

const int kMax = 200000; 
// initially all numbers are not prime
std::vector<bool>* arr = new std::vector<bool>(kMax+1, true);

void markPrimes(uint64_t n) {
  auto& primes = *arr;
  // mark 0 and 1 as prime
  primes[0] = primes[1] = false;
  for (uint64_t i=2;i<=n;++i) {
    // all numbers less than i*i were already sifted
    // by smaller numbers
    uint64_t sq = i*i;
    if (primes[i] && sq<=n) {
      for (uint64_t j=sq;j<=n;j+=i) {
	primes[j] = false;
      }
    }
  }
}

int main() {
  std::cout << sizeof(*arr) << '\n';
  markPrimes(kMax);
  int k=0;
  int i=2;
  for (;i<=kMax;++i) {
    if ((*arr)[i]) {
      ++k;
      if (k==10001) {
	break;
      }
    }
  }
  std::cout << i << '\n';
  std::cout << std::endl;
  return 0;
}
