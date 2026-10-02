class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);

        int po_ind=0, neg_ind=1;

        for(auto i:nums){
            if(i>=0){
                ans[po_ind]=i;
                po_ind+=2;
            }
            else{
                ans[neg_ind]=i;
                neg_ind+=2;
            }
        }
        return ans;
    }
};