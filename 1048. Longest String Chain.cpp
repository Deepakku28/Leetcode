class Solution {
public:
    
    static bool compare(string s1,string s2){
        return (s1.length()<s2.length());
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int> dp;
        for(int i=0;i<words.size();i++){
            dp[words[i]]=1;
        }
        int ans=0;
        for(string curr: words){
            for(int i=0;i<curr.length();i++){
                if(dp[curr.substr(0,i)+curr.substr(i+1)]>=1){
                    dp[curr]=max(dp[curr],dp[curr.substr(0,i)+curr.substr(i+1)]+1);
                }
            }
            ans=max(ans,dp[curr]);
        }
        return ans;
    }
};
