#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	string reverseString(string s)
	{
		auto p = s.begin();
		auto q = s.end() - 1;
		while (p < q)
		{
			char temp;
			temp = *p;
			*p = *q;
			*q = temp;
			p++;
			q--;
		}
		return s;
	}
};