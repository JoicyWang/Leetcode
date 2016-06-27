#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int a = 0, b = 1, result = 0;
		for (int i = 0; i < n; i++) {
			result = a + b;
			a = b;
			b = result;
		}
		return result;
	}
};