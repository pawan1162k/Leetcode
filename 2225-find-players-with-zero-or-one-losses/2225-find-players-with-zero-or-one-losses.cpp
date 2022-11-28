class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>loser;
        map<int,int>winner;
        int n=matches.size();
        for(int i=0;i<n;i++){
            loser[matches[i][1]]++;
            winner[matches[i][0]]++;
        }
        vector<int>ans1;
        vector<int>ans2;
        for(auto it=winner.begin();it!=winner.end();it++){
            auto itr=loser.find(it->first);
            if(itr==loser.end()){
                ans1.push_back(it->first);
            }
        }
        for(auto it=loser.begin();it!=loser.end();it++){
            if(it->second==1){
                ans2.push_back(it->first);
            }
        }
        return {ans1,ans2};
    }
};