class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0]=1;
        for(int i=1;i<nums.size();i++){
            ans[i]=nums[i-1]*ans[i-1];
        }
        int right=1;
        for(int j=nums.size()-1;j>=0;j--){
            ans[j]*=right;
            right*=nums[j];
        }
        return ans;
    }
};