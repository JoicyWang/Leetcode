#include <iostream>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		int a[26] = {};
		for (auto i = s.begin(); i < s.end(); i++) {
			a[*i - 'a']++;
		}
		for (auto i = t.begin(); i < t.end(); i++) {
			a[*i - 'a']--;
			if (a[*i - 'a'] < 0)
				return false;
		}
		return true;
	}
};