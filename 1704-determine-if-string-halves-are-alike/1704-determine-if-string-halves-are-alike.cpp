class Solution {
public:
    bool halvesAreAlike(string s) {
        int count=0;
        for(int i=0;i<s.length()/2;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count++;
            }else if(s[i]=='A' || s[i]=='E'  || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                count++;
            }
        }
        for(int i=s.length()/2;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count--;
            }else if(s[i]=='A' || s[i]=='E'  || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                count--;
            }
        }
        return count==0;
        
    }
};