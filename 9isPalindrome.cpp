#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int rx = 0, t = x;
		while (t != 0) {
			rx = rx * 10 + t % 10;
			t /= 10;
		}
		return (rx == x);
	}
};