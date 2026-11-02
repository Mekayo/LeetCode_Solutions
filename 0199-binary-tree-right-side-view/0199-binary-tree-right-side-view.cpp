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
        if(!root) return {};
       
        vector<int> ans;
       
        deque<TreeNode*> dq;
        dq.push_front(root);
        
        while(!dq.empty()){
            int size=dq.size();
            ans.push_back(dq.back()->val);
            
            for(int i=0;i<size;++i){

                TreeNode* cur_node=dq.front();
                dq.pop_front();

                if(cur_node->left) dq.push_back(cur_node->left);
                if(cur_node->right) dq.push_back(cur_node->right);
            }
        }
        return ans;
    }
};