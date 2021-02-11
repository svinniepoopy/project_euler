#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> getPrimeFactors(int n) {
  std::vector<int> pf;
  while (n%2==0) {
    pf.push_back(2);
    n = n/2;
  }

  int sqrtn = std::sqrt(n);
  for (int i=3;i<=sqrtn;i+=2) {
    while (n%i == 0) {
      pf.push_back(i);
      n = n/i;
    }
  }
  if (n>2) {
    pf.push_back(n);
  }
  return pf;
}

// return the smallest positive number evenly divisible
// by all the numbers from 1 to n
int smallestMultiple(int n) {
  int m = 1;
  for (int i=1;i<=n;++i) {
    if (m%i == 0) {
      continue;
    } else {
      std::vector<int> prime_factors{getPrimeFactors(i)};
      for (int pf:prime_factors) {
	m = m*pf;
	if (m%i == 0) {
	  break;
	} 
      }
    }
  }
  return m;
}

int main() {
  for (int i=1;i<=20;++i) {
    std::cout << "Smallest multiple of " << i << " is " << smallestMultiple(i) << std::endl;
  }
  return 0;
}

