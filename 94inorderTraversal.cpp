class Solution {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL) {
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};