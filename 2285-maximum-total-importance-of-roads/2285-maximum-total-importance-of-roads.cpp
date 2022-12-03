class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>in_deg(n,0);
        for(auto it:roads){
            in_deg[it[0]]++;
            in_deg[it[1]]++;
        }
        priority_queue<pair<int,int>>pq;
        int i=0;
        for(auto it:in_deg){
            pq.push({it,i++});
        }
        int k=n;
        while(!pq.empty()){
            in_deg[pq.top().second]=n--;
            pq.pop();
        }
        long long count=0;
        for(auto it:roads){
            count+=(in_deg[it[0]]+in_deg[it[1]]);
        }
        return count;
    }
};