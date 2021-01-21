class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m=A.size();
        int n=A[0].size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                for(int k=0;k<=m;k++){
                    if(k==m){
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                    else if(A[k][j]>A[k][i]){
                        break;
                    }
                }
            }
        }
        return (n-*max_element(dp.begin(),dp.end()));
    }
};
