class RandomizedSet {
    vector<int>v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(find(v.begin(),v.end(),val)==v.end()){
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it=find(v.begin(),v.end(),val);
        if(it==v.end()){
            return false;
        }
        v.erase(it);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */