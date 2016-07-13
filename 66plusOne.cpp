#include <stdint.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> add(vector<int>& digits, int i) {
		if (digits[i] == 9) {
			digits[i] = 0;
			if (i > 0)
				return add(digits, i - 1);
			else {
				reverse(digits.begin(), digits.end());
				digits.push_back(1);
				reverse(digits.begin(), digits.end());
			}
		}
		else
			digits[i]++;
		return digits;
	}
	vector<int> plusOne(vector<int>& digits) {
		return add(digits, digits.size() - 1);
	}
};