class Solution {
public:
    void helper(vector<char> &val,vector<string> &ans,int start,int n,string &curr){
        if(n==0){
            ans.push_back(curr);
            return ;
        }
        for(int i=start;i<5;i++){
            curr+=val[i];
            helper(val,ans,i,n-1,curr);
            curr.pop_back();
        }
    }
    
    int countVowelStrings(int n) {
        vector<char> val={'a','e','i','o','u'};
        vector<string> ans;
        string curr="";
        helper(val,ans,0,n,curr);
        return ans.size();
    }
};
