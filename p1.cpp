#include <iostream>

int sum3or5(int n) {
  int sum=0;
  for (int i=1;i<n;++i) {
    if (i%5==0 || i%3==0) {
      sum+=i;
    }
  }
  return sum;
}

int main() {
  std::cout << sum3or5(1000) << '\n';
  return 0;
}
