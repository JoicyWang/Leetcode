#include <iostream>
using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		bool result;
		result = static_cast<bool>(n % 4);
		return result;
	}
};