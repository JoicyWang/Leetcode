#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void createTree(TreeNode* &node, vector<int> nums, int i) {
		if ((i > 0) && (i < nums.size() + 1) && nums[i - 1] != 0) {
			node = new TreeNode(nums[i - 1]);
			createTree(node->left, nums, 2 * i);
			createTree(node->right, nums, 2 * i + 1);
		}
		else
			node = NULL;
	}
	void preOrder(TreeNode* node){
		if (node != NULL){
			cout << node->val << " ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}
public:
	TreeNode *root;
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return NULL;
		else {
			TreeNode* temp = root->left;
			root->left = invertTree(root->right);
			root->right = invertTree(temp);
			return root;
		}
	}
	void testP(vector<int> nums){
		createTree(root, nums, 1);
		preOrder(root);
		cout << endl;
		root = invertTree(root);
		preOrder(root);
		cout << endl;
	}
};