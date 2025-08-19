// LeetCode #144: Binary tree preorder traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal
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
    void preorder(TreeNode* node,vector<int>& res) {
        if (node == NULL) return;
        
        res.push_back(node->val); 
        preorder(node->left,res);
        preorder(node->right,res);
    }
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        
        return res;
    }
};