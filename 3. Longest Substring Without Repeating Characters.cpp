class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans=0,i=0,j= -1;
        while(i<s.length()){
            if(mp.count(s[i]) && mp[s[i]]>j){
                j=mp[s[i]];
            }
            mp[s[i]]=i;
            ans=max(ans,i-j);
            i++;
        }
        return ans;
    }
};
