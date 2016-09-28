#include <stdint.h>
#include <iostream>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int find(int low, int high) {
        if (low > high) return 0;
        if ((low == high) & (isBadVersion(low))) return low;
        int mid = low + (high - low) / 2;
        if(isBadVersion(mid)) return find(low, mid);
        else return find(mid + 1, high);
    }
    
    int firstBadVersion(int n) {
        return find (1, n);
    }
};