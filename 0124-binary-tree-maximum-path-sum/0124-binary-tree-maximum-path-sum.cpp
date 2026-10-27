/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_sum=INT_MIN;

    int pathsum(TreeNode* root){
        if(!root) return 0;
        
        int l=max(0,pathsum(root->left));
        int r=max(0,pathsum(root->right));

        max_sum=max(max_sum,l+r+root->val);

        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;     
        pathsum(root);
        return max_sum;
    }
};