class Solution {
public:
    void helper(vector<string> &ans,string curr,int open,int close,int &n){
        if(open==n && close==n){
            ans.push_back(curr);
            return ;
        }
        if(open<n){
            helper(ans,curr+'(',open+1,close,n);
        }
        if(close<open){
            helper(ans,curr+')',open,close+1,n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,"",0,0,n);
        return ans;
    }
};
