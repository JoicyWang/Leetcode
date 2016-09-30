#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return sum;
        if (root->left != NULL && root->left->left == NULL &&  root->left->right == NULL) {
            sum += root->left->val;
        }
        else if (root->left != NULL) sumOfLeftLeaves(root->left);
        if (root->right != NULL) sumOfLeftLeaves(root->right);
        return sum;
    }
};