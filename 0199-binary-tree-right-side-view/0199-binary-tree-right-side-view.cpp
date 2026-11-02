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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if(!root) return ans;

        queue<TreeNode*> dq;
        dq.push(root);
        
        
        while(!dq.empty()){
            int size=dq.size();
            for(int i=0;i<size;++i){
                TreeNode* cur_node=dq.front();
                dq.pop();
                if(i==size-1) ans.push_back(cur_node->val);
                if(cur_node->left) dq.push(cur_node->left);
                if(cur_node->right) dq.push(cur_node->right);
              
            }
        }
        return ans;
    }
};