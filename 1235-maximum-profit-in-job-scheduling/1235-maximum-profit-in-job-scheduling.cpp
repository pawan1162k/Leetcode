class Solution {
    int solve(int pos,vector<vector<int>>&pq,int last,vector<int>&dp){
        if(pos>=pq.size()){
            return 0;
        }
        vector<int>v=pq[pos];
        if(v[0]<last){
            return solve(pos+1,pq,last,dp);
        }
        if(dp[pos]!=-1){
            return dp[pos];
        }
        int x=0;
        if(v[0]>=last){
            x=solve(pos+1,pq,v[1],dp)+v[2];
        }
        int y=solve(pos+1,pq,0,dp);
        return dp[pos]=max(y,x);
    }
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        // priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>pq;
        for(int i=0;i<start.size();i++){
            pq.push_back({start[i],end[i],profit[i]});
        }
        sort(pq.begin(),pq.end());
        vector<int>dp(50001,-1);
        return solve(0,pq,0,dp);
    }
};