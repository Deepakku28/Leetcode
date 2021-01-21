class Solution {
public:
    bool solution(int bitVector,int currTotal,vector<bool> &dp,int &maxChoosableInteger,int &desiredTotal){
        if(currTotal>=desiredTotal){
            return false;
        }
        if(dp[bitVector]==true){
            return true;
        }
        for(int i=1;i<=maxChoosableInteger;i++){
            if((bitVector&(1<<(i-1)))==0){
                if(solution((bitVector|(1<<(i-1))),currTotal+i,dp,maxChoosableInteger,desiredTotal)==false){
                    return dp[bitVector]=true;
                }
            }
        }
        return dp[bitVector]=false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal==0 || maxChoosableInteger==0 || desiredTotal<=maxChoosableInteger){
            return true;
        }
        int sum=(maxChoosableInteger*(maxChoosableInteger+1)/2);
        if(sum<desiredTotal){
            return false;
        }
        int bitVector=0;
        vector<bool> dp(1<<(maxChoosableInteger+1),false);
        return solution(bitVector,0,dp,maxChoosableInteger,desiredTotal);
    }
};
