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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;

        deque<TreeNode*> dq;
        dq.push_front(root);
        
        bool rev=false;
        
        while(!dq.empty()){
            int size=dq.size();
            vector<int> cur;
            cur.reserve(dq.size());
            for(int i=0;i<size;++i){
                if(!rev){
                    TreeNode* cur_node=dq.front();
                    dq.pop_front();
                    cur.push_back(cur_node->val);
                    if(cur_node->left) dq.push_back(cur_node->left);
                    if(cur_node->right) dq.push_back(cur_node->right);
                }
                else{
                    TreeNode* cur_node=dq.back();
                    dq.pop_back();
                    cur.push_back(cur_node->val);
                    if(cur_node->right) dq.push_front(cur_node->right);
                    if(cur_node->left) dq.push_front(cur_node->left);
                    
                }
            }
            rev=!rev;
           ans.push_back(cur);  
        }
        return ans;
    }
};