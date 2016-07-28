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
    bool sumUp(TreeNode* node, int sum, int tmp) {
        if (node == NULL)
            return false;
        if ((node->left == NULL) && (node->right == NULL))
            return (tmp + node->val == sum);
        return sumUp(node->left, sum, tmp + node->val) || sumUp(node->right, sum, tmp + node->val);    
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return sumUp(root, sum, 0);
    }
};