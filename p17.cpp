// algorithm
// from 1 - 99 
// from 100 - 999
// 1000 = one thousand

// count (hundred and) 101 to 999 
// count 1 - 99 from 101 to 999
// count one thousand
// count 1 to 99

#include "p17.h"

#include <string>
#include <iostream>
#include <unordered_map>

using DigitWords::M;

int WordToLetterCount() {
  int letter_counts = 0;

  // count 1 - 19
  for (int i=1;i<=19;++i) {
    letter_counts += M[i].size();
  }

  // count 20 - 99
  for (int i=20;i<=99;++i) {
    int msd = i/10;
    int lsd = i%10;
    if (lsd == 0) {

      letter_counts += M[i].size();
    } else {
      letter_counts += M[msd*10].size() + M[lsd].size(); 
    }
  }

  const std::string AND{"and"};

  // count 101 - 999
  for (int i=100;i<=999;++i) {
    int hundredth = i/100;
    int oneth = i%10;
    int rem = i%100;
    if (rem == 0) { // 900
      letter_counts += M[hundredth].size() + M[100].size(); 
    } else {
      if (oneth == 0) { // hundred and twenty thirty forty so on 
	letter_counts += M[hundredth].size() + M[100].size() + AND.size() + M[i-i/100*100].size();
      } else if (oneth!= 0 && (i%100<10)) { // 901, 902, 903, 909
	letter_counts += M[hundredth].size() + M[100].size() + AND.size() + M[i%100].size();
      } else { // 999
	int tenth = i-(i/100)*100;
	if (tenth>=11 && tenth<=19) {
	  letter_counts += M[hundredth].size() + M[100].size() + AND.size() + M[tenth].size();
	} else {
	  letter_counts += M[hundredth].size() + M[100].size() + AND.size() + M[(tenth/10)*10].size() + M[i%10].size();
	}
      }
    }
  }

  // count "one thousand"
  letter_counts += M[1].size() + M[1000].size();

  return letter_counts;
}

int main() {
  std::cout << WordToLetterCount() << std::endl;
  return 0;
}
