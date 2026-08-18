class Solution {
public:
    int rec(vector<int>& coins, int amt, vector<int>& dp){
        if(amt==0) return 0;

        if(dp[amt]!=-1) return dp[amt];
        int ans=INT_MAX;
        for(auto coin:coins){

            if(coin<=amt){
                int res=rec(coins,amt-coin,dp);
                if(res!=INT_MAX)
                    ans=min(ans,res+1);
            }
        }
    return dp[amt]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1,-1);
        int ans=rec(coins,amount,dp);
        return ans==INT_MAX ? -1: ans;
    }
};