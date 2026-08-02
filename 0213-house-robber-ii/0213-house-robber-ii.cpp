class Solution {
public:
    int helper(vector<int>& nums, int id, vector<int>& dp, int n) {
        if (id > n)
            return 0;

        if (dp[id] != -1)
            return dp[id];

        int max_rob = helper(nums, id + 2, dp, n) + nums[id];
        int right = helper(nums, id + 1, dp, n);

        return dp[id] = max(max_rob, right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);

        vector<int> dp2(n, -1);
        return max(helper(nums, 0, dp1, n - 2), 
                    helper(nums, 1, dp2, n - 1));
    }
};