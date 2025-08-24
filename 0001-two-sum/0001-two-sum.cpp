class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int moreneed=target-num;
            if(mp.find(moreneed)!=mp.end()) return {mp[moreneed],i};
            
            mp[num]=i;

        }
        return {-1,-1};
    }
};