class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>in_deg(n,0);
        for(auto& it:roads){
            in_deg[it[0]]++;
            in_deg[it[1]]++;
        }
        sort(in_deg.begin(),in_deg.end());
        long long count=0;
        for(int i=n-1;i>=0;i--){
            count+= (in_deg[i]*(n--));
        }
        return count;
    }
};