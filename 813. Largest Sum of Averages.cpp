class Solution {
public:
    double solution(vector<int>& A,int K,int index,vector<vector<double>> &dp,vector<double> &sum,int &n){
        if(index>=n){
            return 0.0;
        }
        if(dp[index][K]!=-1.0){
            return dp[index][K];
        }
        if(K==1){
            return dp[index][K]=((sum[n-1]-sum[index]+A[index])/(n-index));
        }
        double ans=0.0;
        for(int i=index;i+K<=n;i++){
            ans=max(ans,((sum[i]-sum[index]+A[index])/(i-index+1)+(solution(A,K-1,i+1,dp,sum,n))));
        }
        return dp[index][K]=ans;
    }
    
    double largestSumOfAverages(vector<int>& A, int K) {
        int n=A.size();
        vector<double> sum(n,0);
        sum[0]=A[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+A[i];
        }
        vector<vector<double>> dp(n,vector<double>(K+1,-1.0));
        return solution(A,K,0,dp,sum,n);
    }
};
