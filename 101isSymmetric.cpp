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
    bool readLeaf(TreeNode* node1, TreeNode* node2) {
        if ((node1 == NULL) && (node2 == NULL))
            return true;
        else if ((node1 == NULL) || (node2 == NULL))
            return false;
        else
            return (node1->val == node2->val) && readLeaf(node1->left, node2->right) && readLeaf(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return readLeaf(root, root);
    }
};