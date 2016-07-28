#include <stdint.h>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else {
            int depth1 = 1, depth2 = 1;
            depth1 += minDepth(root->left);
            depth2 += minDepth(root->right);
            if (root->left == NULL)
                return depth2;
            else if (root->right == NULL)
                return depth1;
            else
                return min(depth1, depth2);
        }
    }
};