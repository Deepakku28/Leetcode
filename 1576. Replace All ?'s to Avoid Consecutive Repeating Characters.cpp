class Solution {
public:
    string modifyString(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                s[i]='a';
                while((i>0 && s[i]==s[i-1])||(i+1<n && s[i]==s[i+1])){
                    s[i]++;
                }
            }
        }
        return s;
    }
};
