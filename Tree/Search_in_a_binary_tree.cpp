// LeetCode #700: search in a binary tree
// https://leetcode.com/problems/search-in-a-binary-tree

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
    TreeNode* searchBST(TreeNode* root, int val) {
           
        if (!root || root->val == val) {
            return root;
        }
        return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    
    }
};