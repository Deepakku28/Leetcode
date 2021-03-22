class Solution {
public:
    int helper(vector<vector<int>> &dp,int start,int end,string &str){
	    if(start==end){
	        return 1;
	    }
	    if(start+1==end && str[start]==str[end]){
	        return 2;
	    }
	    if(dp[start][end]!=-1){
	        return dp[start][end];
	    }
	    if(str[start]==str[end]){
	        return dp[start][end]=2+helper(dp,start+1,end-1,str);
	    }
	    else{
	        return dp[start][end]=max(helper(dp,start+1,end,str),helper(dp,start,end-1,str));
	    }
	}
    
    int longestPalindromeSubseq(string str) {
        int n=str.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(dp,0,n-1,str);
    }
};
