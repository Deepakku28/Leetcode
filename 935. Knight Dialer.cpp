class Solution {
public:
    int solution(vector<vector<int>> &moves,vector<vector<int>> &dp,int index,int end){
        if(end==0){
            return 1;
        }
        if(dp[index][end]!=-1){
            return dp[index][end];
        }
        int ans=0;
        for(auto it:moves[index]){
            ans=(ans+solution(moves,dp,it,end-1))%1000000007;
        }
        return dp[index][end]=ans;
    }
    
    int knightDialer(int n) {
        vector<vector<int>> moves{{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
        vector<vector<int>> dp(10,vector<int>(n+1,-1));
        int result=0;
        for(int i=0;i<=9;i++){
            result=(result+solution(moves,dp,i,n-1)%1000000007)%1000000007;
        }
        return result;
    }
};
