class Solution {
public:
    int solution(unordered_map<int,int> &mp,vector<vector<int>> &dp,vector<int>& stones,int &n,int val,int index,int k){
        if(index==n-1){
            return dp[index][k]=true;
        }
        if(dp[index][k]!=-1){
            if(dp[index][k]==1){
                return dp[index][k]=true;
            }
            else{
                return dp[index][k]=false;
            }
        }
        if(val!=stones[index]){
            return dp[index][k]=false;
        }
        if(k-1>0 && solution(mp,dp,stones,n,val+k-1,mp[val+k-1],k-1) || solution(mp,dp,stones,n,val+k,mp[val+k],k) || solution(mp,dp,stones,n,val+k+1,mp[val+k+1],k+1)){
            return dp[index][k]=true;
        }
        else{
            return dp[index][k]=false;
        }
    }
    
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(1+stones[0]!=stones[1]){
            return false;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solution(mp,dp,stones,n,1,1,1);
    }
};
