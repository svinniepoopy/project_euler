#include <iostream>
//
class FibonacciGenerator {
  private:
    int n;
    unsigned long long val[2];
  public:
    FibonacciGenerator(): n{0} {
	val[0] = val[1] = 0;
    }

    unsigned long long operator()() {
      auto result = n>2?val[0]+val[1]:n>0?1:0;
      ++n;
      val[0] = val[1];
      val[1] = result;
      return result;
    }

    int count() const {
      return n;
    }
};

int main() {
  int kMax = 4000000;
  FibonacciGenerator f;
  f();f();
  unsigned long long sum=0;
  for (int i=0;i<50;++i) {
    auto t = f();
    if (t<kMax && (t%2==0)) {
      sum+=t;
      // std::cout << t << std::endl;
    }
  }
  std::cout << sum << '\n';
  return 0;
}
