class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return {};
        vector<int> nums;
        vector<char> ops;
        int n = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] < '0' || input[i] > '9') {
                nums.push_back(n);
                n = 0;
                ops.push_back(input[i]);
            }
            else n = n * 10 + input[i] - '0';
        }
        nums.push_back(n);
        int sz = nums.size();
        vector<vector<vector<int>>> vvv(sz, vector<vector<int>>(sz));
        for (int i = 0; i < sz; i++) {
            vvv[i][i].push_back(nums[i]);
        }
        for (int len = 2; len <= sz; len++) {
            for (int lo = 0, hi = lo + len - 1; hi < sz; lo++, hi++) {
                auto& v = vvv[lo][hi];
                for (int i = lo; i < hi; i++) {
                    const auto& v1 = vvv[lo][i];
                    const auto& v2 = vvv[i + 1][hi];
                    char op = ops[i];
                    switch(op) {
                        case '+': for (int x : v1) for (int y : v2) v.push_back(x + y);
                                  break;
                        case '-': for (int x : v1) for (int y : v2) v.push_back(x - y);
                                  break;
                        case '*': for (int x : v1) for (int y : v2) v.push_back(x * y);
                                  break;
                        default: break;
                    }
                }
            }
        }
        vector<int> ret;
        ret.swap(vvv[0][sz - 1]);
        return ret;
    }
};