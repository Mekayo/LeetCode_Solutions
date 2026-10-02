class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt =0, smallest=INT_MIN,longest=0;

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){

            if(nums[i]-1==smallest){
                smallest=nums[i];
                cnt++;
            }
            else if(nums[i]==smallest) continue;

            else {
                smallest=nums[i];
                cnt=1;
            }
            longest=max(longest, cnt);
        }
        return longest;
    }
};