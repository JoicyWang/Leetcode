#include <iostream>
#include <string>
using namespace std;

class Solution{
private:
	string voels = "AEIOUaeiou";
	bool isVowel(char a)
	{
		for (auto t : voels)
		{
			if (a == t)
				return true;
		}
		return false;
	}
public:
	string reverseVowels(string s)
	{
		auto p = s.begin();
		auto q = s.end() - 1;
		while (p < q)
		{
			while (!isVowel(*p) && p < q)
				p++;
			while (!isVowel(*q) && p < q)
				q--;
			if (isVowel(*p) && isVowel(*q))
			{
				char t = *p;
				*p = *q;
				*q = t;
				p++;
				q--;
			}
		}
		return s;
	}
};