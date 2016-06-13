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
	TreeNode *root1;
	TreeNode *root2;
	bool isSameTree(TreeNode* p, TreeNode* q) {
		bool result = true, result1 = true, result2 = true;
		if (p != NULL && q != NULL){
			if (p->val != q->val)
				result = false;
			result1 = isSameTree(p->left, q->left);
			result2 = isSameTree(p->right, q->right);
			return result && result1 && result2;
		}
		else if (p == NULL && q == NULL)
			return true;
		else
			return false;
	}
	void testP(vector<int> nums1, vector<int> nums2){
		createTree(root1, nums1, 1);
		createTree(root2, nums2, 1);
		bool result = isSameTree(root1, root2);
		cout << result << endl;
	}
};