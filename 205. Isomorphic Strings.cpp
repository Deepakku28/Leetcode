class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<n;i++){
            if(mp1.find(s[i])==mp1.end()){
                mp1[s[i]]=i;
            }
            if(mp2.find(t[i])==mp2.end()){
                mp2[t[i]]=i;
            }
            if(mp1[s[i]]!=mp2[t[i]]){
                return false;
            }
        }
        return true;
    }
};
