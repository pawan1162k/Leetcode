class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<pair<int,int>>s1,s2;
        for(int i=0;i<n;i++){
            int count=1;
            while(!s1.empty() && (s1.top().first)>arr[i]){
                count+=s1.top().second;
                s1.pop();
            }
            s1.push({arr[i],count});
            left[i]=count;
        }
        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        for(int i=n-1;i>=0;i--){
            int count=1;
            while(!s2.empty() && (s2.top().first)>=arr[i]){
                count+=s2.top().second;
                s2.pop();
            }
            s2.push({arr[i],count});
            right[i]=count;
        }
        // for(int i=0;i<n;i++){
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        long long ans=0;
        for(int i=0;i<n;i++){
            long long val=(left[i]*right[i])%1000000007; 
            val=val%1000000007;
            val = (val*arr[i])%1000000007;
            ans=(ans+val)%1000000007;
        }
        return ans;
    }
};