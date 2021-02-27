
// generate a triangular number
// find the number of divisors
// if num divisors == 500, return
//

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

class DivisorGen {
  public:
    DivisorGen() {}

    int GetNumDivisors(uint64_t n) {
      if (n==1) {
	return 1;
      }
      std::unordered_map<uint64_t, int> M;
      while (n%2==0) {
	++M[2];
	n = n/2;
      }

      uint64_t sqrtn = std::sqrt(n);
      for (int i=3;i<=sqrtn;++i) {
	while (n%i==0) {
	  ++M[i];
	  n = n/i;
	}
      }

      if (n>2) {
	++M[n];
      }

      int ndivisors = 1;
      for (const auto& p:M) {
	ndivisors *= (p.second+1); 
      }

      return ndivisors;
    }
};

class TriangularNumGen {
  public:
    TriangularNumGen():n{0},i{1} {}

    uint64_t operator()() {
      n = n+i;
      ++i;
      return n;     
    }

  private:
    uint64_t i;
    uint64_t n;
};

// return a triangular number with k divisors
int GetKthTriangularNum(int k) {
  int ndivisors = 0;
  uint64_t num;
  TriangularNumGen numgen;
  DivisorGen divgen;
  while (ndivisors <= k) {
    num = numgen();
    ndivisors = divgen.GetNumDivisors(num);
  }

  return num;
}

int main() {

  int k = 500;
  int n = GetKthTriangularNum(k);
  std::cout << "N: " << n << '\n';

  return 0;
}
