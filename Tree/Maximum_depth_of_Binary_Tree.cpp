// LeetCode #104: Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int height(TreeNode* root){
        if(!root) return 0;
         
         return 1+max(height(root->left),height(root->right));
    }

    int maxDepth(TreeNode* root) {
        
        return height(root);    
    }
};