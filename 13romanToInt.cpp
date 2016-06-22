#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int temp1 = 0, temp2 = 0, result = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			switch (s[i]) {
			case 'I':
				temp2 = 1;
				break;
			case 'V':
				temp2 = 5;
				break;
			case 'X':
				temp2 = 10;
				break;
			case 'L':
				temp2 = 50;
				break;
			case 'C':
				temp2 = 100;
				break;
			case 'D':
				temp2 = 500;
				break;
			case 'M':
				temp2 = 1000;
				break;
			default:
				break;
			}
			if (temp2 >= temp1)
				result += temp2;
			else
				result -= temp2;
			temp1 = temp2;
		}
		return result;
	}
};