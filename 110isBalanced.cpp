#include <stdint.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int dep(TreeNode* node) {
		if (node == NULL)
			return 0;
		int leftHeight = dep(node->left);
		if (leftHeight == -1)
			return -1;
		int rightHeight = dep(node->right);
		if (rightHeight == -1)
			return -1;
		if (abs(leftHeight - rightHeight) > 1)
			return -1;
		else
			return max(leftHeight, rightHeight) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (dep(root) == -1)
			return false;
		else
			return true;
	}
};