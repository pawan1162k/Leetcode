class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(auto it:arr){
            m[it]++;
        }
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(auto it=m.begin();it!=m.end();it++){
            st1.insert(it->first);
            st2.insert(it->second);
        }
        return st1.size()==st2.size();
    }
};