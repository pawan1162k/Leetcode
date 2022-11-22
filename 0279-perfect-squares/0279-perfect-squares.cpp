class Solution {
    int solve(int i,int n,vector<vector<int>>&dp){
        if(n==0){
            return 0;
        }
        if(i*i>n){
            return 10001;
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        int c=10001;
        if(i*i<=n){
            c=1+solve(i,n-(i*i),dp);
        }
        return dp[i][n]=min(c,solve(i+1,n,dp));
    }
public:
    int numSquares(int n) {
        vector<vector<int>>dp(sqrt(n)+10,vector<int>(n+1,-1));
        return solve(1,n,dp);
    }
};