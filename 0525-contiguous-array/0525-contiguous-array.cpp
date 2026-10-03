class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> Ind_store;
        Ind_store[0]=-1;
        int max_len=0, prefix_sum=0;
        for(int i=0;i<n;i++){
            prefix_sum+= nums[i]==0 ? -1:1;

            if(Ind_store.count(prefix_sum)){
                int ind=Ind_store[prefix_sum];
                int len=i-ind;
                max_len=max(max_len,len);
            }
            else {
                Ind_store[prefix_sum]=i;
            }
        }
        return max_len;
    }
};