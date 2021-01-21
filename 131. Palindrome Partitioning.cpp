class Solution {
public:
    void dfs(int start,vector<vector<string>>& ans,vector<string> &curr,int &n,string &s){
        if(start==n){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<n;i++){
            if(check(s.substr(start,i-start+1))){
                curr.push_back(s.substr(start,i-start+1));
                dfs(i+1,ans,curr,n,s);
                curr.pop_back();
            }
        }
    }
    
    bool check(string str){
        int n=str.size()-1;
        int i=0;
        while(i<=n){
            if(str[i]!=str[n]){
                return false;
            }
            i++;
            n--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.size();
        vector<string> curr;
        dfs(0,ans,curr,n,s);
        return ans;
    }
};
