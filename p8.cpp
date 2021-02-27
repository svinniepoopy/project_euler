#include <numeric>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <string>

namespace {
std::vector<unsigned int> digits(1000);
//using uint128_t = unsigned __int128; 
using uint128_t = uint64_t;
}

uint128_t MaxKDigitProduct(int k, const std::vector<unsigned int>& digits) {
  uint128_t prod = std::accumulate(digits.begin(), digits.begin()+k,
      1,
      std::multiplies<uint128_t>());
  uint128_t max_prod = prod;
  for (int i=1;i+k<digits.size();++i) {
    uint128_t curr_prod = std::accumulate(digits.begin()+i, digits.begin()+i+k,
	(uint64_t)1,
	std::multiplies<uint128_t>());
    if (curr_prod>max_prod) {
      max_prod = curr_prod;
    }
  }
  return max_prod;
}

void ParseInput() {
  std::string line;
  int pos = 0;
  for (std::string line; std::getline(std::cin, line); ) { 
    for (int i=0;i<line.size();++i) {
      digits[pos++] = line[i]-'0';
    }
  }
  assert(digits.size()==1000);
}

int main() {
  ParseInput();
  int k = 13;
  uint128_t val = MaxKDigitProduct(k, digits);
  std::cout << val << '\n'; 
  
  return 0;
}
