#include <iostream>
#include <vector>

namespace {
const int kINIT_SIZE = 50;
}

class ArraySum {
  public:

    ArraySum(std::vector<int>& start):arr{start} {}

    ArraySum& operator+=(const std::vector<int>& o) {
      int carry = 0;
      int last;
      for (int i=0;i<o.size();++i) {
	int sum = arr[i] + o[i] + carry;
	if (sum<=9) {
	  last = sum;
	  carry = 0;
	} else {
	  last = sum%10;
	  carry = sum/10;
	}
	arr[i] = last;
      }
      AddCarry(carry);
      return *this;
    }

    int operator[](int i) {
      return arr[i];
    }

    int size() const {
      return arr.size();
    }

  private:

    void AddCarry(int carry) {
      if (!carry) {
	return;
      }
      if (arr.size()==kINIT_SIZE) {
	  arr.push_back(carry);
      } else {
	int last;
	for (int i=kINIT_SIZE;i<arr.size();++i) {
	  int sum = arr[i] + carry;
	  if (sum<=9) {
	    last = sum;
	    carry = 0;
	  } else {
	    last = sum%10;
	    carry = sum/10;
	  }
	  arr[i] = last;
	}
	if (carry) {
	  arr.push_back(carry);
	}
      }
    }

    std::vector<int> arr;
};

void LargeIntegerSum(
    std::vector<std::vector<int>>& nums) {
  ArraySum asum{nums[0]};
  for (int i=1;i<nums.size();++i) {
    asum += nums[i]; 
  }

  for (int i=asum.size()-1;i>=asum.size()-10;--i) {
    std::cout << asum[i];
  }
  std::cout << std::endl;
}

std::vector<int> StringToIntArr(const std::string& s) {
  std::vector<int> digits;
  for (int i=s.size()-1;i>=0;--i) {
    digits.push_back(s[i]-'0');
  }
  return digits;
}

int main() {
  std::vector<std::vector<int>> A;
  std::string s;
  while (std::cin>>s) {
    A.emplace_back(StringToIntArr(s));
  }

  LargeIntegerSum(A);

  return 0;
}
