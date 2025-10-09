// LeetCode #98: Validate Binary search tree
// https://leetcode.com/problems/validate-binary-search-tree

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool check_tree(TreeNode* root,long min_val,long max_val){
        if(!root) return true;

        if(!(root->val>min_val && root->val<max_val)) return false;

        return check_tree(root->left,min_val,root->val) && check_tree(root->right,root->val,max_val); 
    }
    bool isValidBST(TreeNode* root) {
        
        return check_tree(root,LONG_MIN,LONG_MAX);
    }
};