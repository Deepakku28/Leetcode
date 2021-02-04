class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp(26,0);
        for(int i=0;i<t.size();i++){
            mp[t[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']--;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=(mp[i]>0?mp[i]:0);
        }
        return ans;
    }
};
