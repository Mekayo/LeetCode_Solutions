// LeetCode #124: Binary tree maximum sum[D[D[D[D[Cpath sum[2~[D[C
// https://leetcode.com/problems/binary-tree-maximum-sum[d[d[d[d[cpath-sum[2~[d[c

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
    int max_sum = INT_MIN;

    int helper(TreeNode* root) {
        if (!root)
            return NULL;

        int left = helper(root->left);
        int right = helper(root->right);
        left = max(0, left);
        right = max(0, right);
        int pathsum = left + right + root->val;
        max_sum = max(max_sum, pathsum);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max_sum;
    }
};