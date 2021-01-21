class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        vector<int> mp(26,0);
        int start=0;
        int maxCount=0;
        int maxLen=0;
        for(int end=0;end<n;end++){
            mp[s[end]-'A']++;
            maxCount=max(maxCount,mp[s[end]-'A']);
            if(end-start-maxCount+1>k){
                mp[s[start]-'A']--;
                start++;
            }
            maxLen=max(maxLen,end-start+1);
        }
        return maxLen;
    }
};
