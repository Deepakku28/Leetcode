class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3){
            return 0;
        }
        vector<int> dp(n,0);
        for(int i=2;i<n;i++){
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                dp[i]=1+dp[i-1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=dp[i];
        }
        return ans;
    }
};
