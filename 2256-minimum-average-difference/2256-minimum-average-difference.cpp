class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long suf=0;
        for(auto &it:nums){
            suf+=it;
        }
        long long pref=0;
        long long ind=INT_MAX;
        long long minval=INT_MAX;
        long long j=1;
        long long k=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            pref+=nums[i];
            suf-=nums[i];
            long long temp=abs((pref/j)-(k!=0?(suf/k):0));
            // cout<<temp<<", "<<pref<<", "<<suf<<"| ";
            if(temp<minval){
                minval=temp;
                ind=i;
            }
            j++;
            k--;
        }
        return ind;
    }
};