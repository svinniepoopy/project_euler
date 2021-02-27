
#include <numeric>
//#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

auto PowerDigitSum(int n) {
  std::vector<long unsigned int> digits{1};
  for (int i=0;i<n;++i) {
    int carry = 0;
    for (int k=0;k<digits.size();++k) {
      auto sum = digits[k]*2 + carry;
      if (sum>9) {
	carry = 1;
      } else {
	carry = 0;
      }
      digits[k] = sum%10;
    }
    if (carry) {
      digits.push_back(1);
    }
  }
  long unsigned int sum = 0;
  return std::accumulate(digits.begin(), digits.end(), sum);
}

int main() {
  std::cout << PowerDigitSum(1000) << std::endl;
}
