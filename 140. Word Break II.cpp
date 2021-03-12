class Solution {
public:
    vector<string> helper(string str,vector<string> &wordDict,unordered_map<string,vector<string>> &mp){
        if(mp.find(str)!=mp.end()){
            return mp[str];
        }
        if(str.size()==0){
            return {""};
        }
        vector<string> subpart;
        vector<string> ans;
        for(auto it:wordDict){
            string curr=str.substr(0,it.size());
            if(curr!=it){
                continue;
            }
            else{
                subpart=helper(str.substr(curr.size()),wordDict,mp);
            }
            for(auto val:subpart){
                string space=(val.size()==0?"":" ");
                ans.push_back(it+space+val);
            }
        }
        return mp[str]=ans;
    }
    
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        unordered_map<string,vector<string>> mp;
        return helper(str,wordDict,mp);
    }
};
