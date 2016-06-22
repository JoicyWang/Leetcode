#include <stdint.h>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		if (n <= 0)
			return 0;
		int *p = new int[n];
		p[0] = 1;
		int next = 1;
		int *p1 = p, *p2 = p, *p3 = p;
		while (next < n) {
			int temp = min(*p1 * 2, *p2 * 3);
			p[next] = min(temp, *p3 * 5);
			while (*p1 * 2 <= p[next])
				++p1;
			while (*p2 * 3 <= p[next])
				++p2;
			while (*p3 * 5 <= p[next])
				++p3;
			++next;
		}
		int ugly = p[next - 1];
		delete[] p;
		return ugly;
	}
};