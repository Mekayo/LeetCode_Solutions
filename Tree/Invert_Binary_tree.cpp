// LeetCode #226: Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
     
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};