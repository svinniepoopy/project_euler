#include <iostream>

int PythagoreanTriplet(int n) {
  for (int a=1;a<=n;++a) {
    for (int b=1;b<=n;++b) {
      for (int c=1;c<=n;++c) {
	if (a+b+c==1000) {
	  if (a*a + b*b == c*c) {
	    return a*b*c;
	  }
	}
      }
    }
  }
  return -1;
}

int main() {
  std::cout << PythagoreanTriplet(1000) << '\n';
  return 0;
}
