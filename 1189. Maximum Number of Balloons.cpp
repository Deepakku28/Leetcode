class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> mp(26,0);
        string str="balloon";
        for(int i=0;i<text.size();i++){
            mp[text[i]-'a']++;
        }
        int ans=INT_MAX;
        for(int i=0;i<str.size();i++){
            if(str[i]=='l' || str[i]=='o'){
                ans=min(ans,mp[str[i]-'a']/2);
            }
            else{
                ans=min(ans,mp[str[i]-'a']);
            }
        }
        return ans;
    }
};
