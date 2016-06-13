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
public:
	TreeNode *root;
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		else{
			int depth1 = 1, depth2 = 1;
			depth1 += maxDepth(root->left);
			depth2 += maxDepth(root->right);
			return max(depth1, depth2);
		}
	}
	void testP(vector<int> nums){
		createTree(root, nums, 1);
		int result = maxDepth(root);
		cout << result << endl;
	}
};