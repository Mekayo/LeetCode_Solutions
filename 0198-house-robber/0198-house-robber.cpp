class Solution {
public:
    int helper(vector<int>& nums, int id, vector<int>& dp, int n) {
        if (id >= n)
            return 0;

        if (dp[id] != -1)
            return dp[id];
        int max_rob = INT_MIN;
        if (id + 2 < n) {
            int rob = helper(nums, id + 2, dp, n) + nums[id];

            max_rob = max(rob, max_rob);
        } 
        else return nums[id];

        return dp[id] = max_rob;
    }
    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);
        int U_max = -1;
        for (int i = 0; i <= n; i++) {
            int temp = helper(nums, i, dp, n);
            U_max = max(temp, U_max);
        }
        return U_max;
    }
};