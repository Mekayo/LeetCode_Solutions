class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0;
        int val_candidate=0;
        for(auto num:nums){
            if(val_candidate==0){
                candidate=num;
                val_candidate=1;
            }else if(candidate==num){
                val_candidate++;
            }
            else 
                val_candidate--;
        }
        return candidate;
    }
};