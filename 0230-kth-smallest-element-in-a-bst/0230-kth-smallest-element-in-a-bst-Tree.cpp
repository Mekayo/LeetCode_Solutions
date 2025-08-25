/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    int res_val;
    void inorder_traversal(TreeNode* root, int k) {
        if (!root)
            return;

        inorder_traversal(root->left, k);

        cnt++;
        if (cnt == k) {
            res_val = root->val;
            return;
        }
        if (cnt < k) {
            inorder_traversal(root->right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        inorder_traversal(root, k);
        return res_val;
    }
};