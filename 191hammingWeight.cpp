#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
	int hammingWeight1(uint32_t n) {
		int result = 0;
		while (n) {
			if (n % 2 == 1)
				result++;
			n = n / 2;
		}
		return result;
	}
	int hammingWeight2(uint32_t n) {
		int result = 0;
		while (n) {
			n = n & (n - 1);
			++result;
		}
		return result;
	}
};