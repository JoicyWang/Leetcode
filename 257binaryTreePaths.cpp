#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        read(root, "", res);
        return res;
    }
private:
    string int2Str(int val) {
        ostringstream s;
        s << val;
        return s.str();
    }
    void read(TreeNode* node, string path, vector<string>& res) {
        if (node == NULL)
            return;
        if (!path.empty())
            path += "->";
        path += int2Str(node->val);
        if ((node->left == NULL) && (node->right == NULL))
            res.push_back(path);
        else {
            read(node->left, path, res);
            read(node->right, path, res);
        }
    }
};