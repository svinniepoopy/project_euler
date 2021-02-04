#include <climits>
#include <vector>
#include <iostream>

bool isPalindrome(int num) {
  std::vector<int> arr;
  while (num) {
    int last = num%10;
    arr.push_back(last);
    num = num/10;
  }
  int i=0;
  int j=arr.size()-1;
  while (i<j) {
    if (arr[i] != arr[j]) {
      return false;
    }
    ++i;
    --j;
  }
  return true;
}

int largest_palindrome(std::vector<int> numbers) {
  int largest = INT_MIN;
  for (int i=0;i<numbers.size();++i) {
    for (int j=i+1;j<numbers.size();++j) {
      int num = numbers[i]*numbers[j];
      if (isPalindrome(num)) {
	if (num>largest) {
	  largest = num;
	}
      }
    }
  }
  return largest;
}

int main() {
  int start = 100;
  int end = 999;
  std::vector<int> numbers;
  for (int i=start;i<=end;++i) {
    numbers.push_back(i);
  }
  std::cout << largest_palindrome(numbers) << '\n';
  return 0;
}
