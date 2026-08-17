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
    int cal(TreeNode* root,int& dia){
        if(!root) return 0;
        
        int left_height= cal(root->left,dia);
        int right_height= cal(root->right,dia);

        dia=max(dia,left_height+right_height);

        return 1+max(left_height,right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int dia=0;
        cal(root,dia);
        return dia;
    }
};