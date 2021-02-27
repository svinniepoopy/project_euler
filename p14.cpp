#include <iostream>

int LongestCollatzSequence(uint64_t n) {
  int64_t chain_len{0};

  while (n!=1) {
    if (n%2) {
      n = n*3+1;
    } else {
      n = n/2; 
    }
    // std::cout << chain_len << '\n';
    ++chain_len;
  }
  return chain_len;
}

int main() {
  uint64_t kMAX = 1000000;
  int max_len = 0;
  uint64_t num;
  int len;
  for (uint64_t i=1;i<=kMAX;++i) {
    if ((len = LongestCollatzSequence(i)) > max_len) {
      max_len = len;
      num = i;
    }
  }
  std::cout << "Number: " << num << 
    " has the longest chain length: " << max_len << '\n';

  return 0;
}
