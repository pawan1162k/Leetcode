class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m1;
        for(auto it:s){
            m1[it]++;
        }
        string temp="";
        multimap<int,char>m;
        for(auto it=m1.begin();it!=m1.end();it++){
            m.insert(pair<int,char>(it->second,it->first));
        }
        for(auto it=m.rbegin();it!=m.rend();it++){
            for(int i=0;i<it->first;i++){
                temp+=it->second;
            }
        }
        return temp;
    }
};