class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        vector<int> mp(26,-1);
        int maxLen=-1;
        for(int i=0;i<n;i++){
            if(mp[s[i]-'a']!=-1){
                maxLen=max(maxLen,i-mp[s[i]-'a']-1);
            }
            else{
                mp[s[i]-'a']=i;
            }
        }
        return maxLen;
    }
};
