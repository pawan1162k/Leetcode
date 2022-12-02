class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>m1;
        map<char,int>m2;
        for(auto it:word1){
            m1[it]++;
        }
        for(auto it:word2){
            m2[it]++;
        }
        unordered_multiset<int>s;
        bool flag=false;
        for(auto it=m1.begin();it!=m1.end();it++){
            s.insert(it->second);
        }
        for(auto x=m2.begin();x!=m2.end();x++){
            auto h=s.find(x->second);
            if(h==s.end()){
                break;
            }
            s.erase(h);
        }
        if(s.empty()){
            flag=true;
        }
        auto it2=m2.begin();
        for(auto it1=m1.begin();it1!=m1.end();it1++){
            if(it1->first!=it2->first){
                flag=false;
                break;
            }
            it2++;
        }
        if(flag){
            return true;
        }
        return false;
    }
};