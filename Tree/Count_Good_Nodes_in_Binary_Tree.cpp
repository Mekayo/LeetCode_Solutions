// LeetCode #1448: Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree

#include<bits/stdc++.h>
using namespace std;

   struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
    int dfs(TreeNode* root,int max_val){
        if(!root) return 0;

        int res = (root->val>=max_val) ? 1:0;
        max_val=max(max_val,root->val);
        res+=dfs(root->left,max_val);
        res+=dfs(root->right,max_val);
        return res;
    }
public:

    int goodNodes(TreeNode* root) {
    return dfs(root,root->val);
    }
};