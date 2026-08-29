class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int> sumDam;
        sumDam[0]=1;
        int cnt=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            if(sumDam.count(sum-k)){
                cnt+=sumDam[sum-k];
            }
            sumDam[sum]++;
        }
        return cnt;
    }
};