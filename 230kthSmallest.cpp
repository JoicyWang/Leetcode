class Solution {
private:
    int calTreeSize(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + calTreeSize(root->left) + calTreeSize(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return 0;
        int leftSize = calTreeSize(root->left);
        if (k == leftSize + 1) return root->val;
        else if (leftSize >= k) return kthSmallest(root->left, k);
        else return kthSmallest(root->right, k - leftSize - 1);
    }
};