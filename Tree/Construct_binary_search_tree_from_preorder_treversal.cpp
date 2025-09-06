// LeetCode #1008: [A[BConstruct binary search tree from preorder traversal
// https://leetcode.com/problems/[a[bconstruct-binary-search-tree-from-preorder-traversal

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
    TreeNode* build(vector<int>& preorder ,int& ind,int bound){
        if(ind==preorder.size() || preorder[ind] > bound) return NULL;

        TreeNode* node=new TreeNode(preorder[ind++]);
        node->left=build(preorder,ind,node->val);
        node->right=build(preorder,ind,bound);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int bound=INT_MAX;
        return build(preorder,i,bound);    
    }
};