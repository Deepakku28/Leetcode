class Solution {
public:
    bool isConcatenated(string str1,unordered_set<string> &s){
        if(str1.length()==0 || s.size()==0){
            return false;
        }
        vector<bool> dp(str1.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=str1.length();i++){
            for(int j=i-1;j>=0;j--){
                string str2=str1.substr(j,i-j);
                if(s.find(str2)!=s.end() && (dp[j]==true)){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[str1.size()];
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        if(n<=1){
            return {};
        }
        vector<string> ans;
        unordered_set<string> s(words.begin(),words.end());
        for(int i=0;i<n;i++){
            s.erase(words[i]);
            if(isConcatenated(words[i],s)==true){
                ans.push_back(words[i]);
            }
            s.insert(words[i]);
        }
        return ans;
    }
};
