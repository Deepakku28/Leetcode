class Solution {
public:
    int solution(int start,int end,vector<vector<int>> &dp,vector<int>& piles){
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        return dp[start][end]=max(piles[start]+min(solution(start+2,end,dp,piles),solution(start+1,end-1,dp,piles)),
            piles[end]+min(solution(start,end-2,dp,piles),solution(start+1,end-1,dp,piles)));
    }
    
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int total=0;
        for(auto it:piles){
            total+=it;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int alex=solution(0,n-1,dp,piles);
        int lee=total-alex;
        return (alex>lee);
    }
};
