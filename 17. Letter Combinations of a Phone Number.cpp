class Solution {
public:
    void dfs(string &digits,vector<string> &ans,vector<string> &mp,string &curr,int start,int &end){
        if(start==end){
            ans.push_back(curr);
            return ;
        }
        for(auto it:mp[digits[start]-'0']){
            curr.push_back(it);
            dfs(digits,ans,mp,curr,start+1,end);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n=digits.size();
        if(n==0){
            return ans;
        }
        vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string curr="";
        dfs(digits,ans,mp,curr,0,n);
        return ans;
    }
};
