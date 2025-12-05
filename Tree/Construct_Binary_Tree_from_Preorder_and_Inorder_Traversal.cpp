// LeetCode #105: Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
// T->O(N^2) s->O(N);
 class Solution {
public:

   int preorderIndex = 0;

    // Function to find root index in inorder[] by linear search
    int findIndex(vector<int>& inorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) return i;
        }
        return -1; // should never happen if input is valid
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start > end) return nullptr;

        // Pick current node from preorder
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root index in inorder by linear search
        int idx = findIndex(inorder, start, end, rootVal);

        // Recursively build left & right subtrees
        root->left = build(preorder, inorder, start, idx - 1);
        root->right = build(preorder, inorder, idx + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0; 
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};