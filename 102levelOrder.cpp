#include <stdint.h>
#include <iostream>
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
	void depRead(TreeNode* node, int &dep, vector<vector<int>> &result)  {
		dep++;
		if (node != NULL) {
			if ((result.size() == 0) || (result.size() < dep)) {
				vector<int> temp;
				temp.push_back(node->val);
				result.push_back(temp);
			}
			else {
				result[dep - 1].push_back(node->val);
			}
			depRead(node->left, dep, result);
			depRead(node->right, dep, result);
		}
		dep--;
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		int dep = 0;
		depRead(root, dep, result);
		return result;
	}
};