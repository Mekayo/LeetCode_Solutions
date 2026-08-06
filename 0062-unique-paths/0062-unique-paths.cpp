class Solution {
public:
    int rec(vector<vector<int>>& dp ,int r,int c,int m,int n){
        if(r==m-1 && c==n-1) return 1;
        if(r>m || c>n) return 0;
        
        if(dp[r][c]!=-1) return dp[r][c];
        int rightcnt=0, downcnt=0;

        if(c<n-1){
            rightcnt+=rec(dp,r,c+1,m,n);
        } 
        if(r<m-1){
            downcnt+=rec(dp,r+1,c,m,n);
        }
        return dp[r][c]=rightcnt+downcnt;
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(dp,0,0,m,n);
    }
};