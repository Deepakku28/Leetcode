class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n=A.size();
        if(n<=0){
            return 0;
        }
		long long int prod=0;
		long long int sum=0;
		for(int i=0;i<n;i++) {
			prod+=A[i]*i;
			sum+=A[i];
		}
		long long int ans=prod;
		for(int i=0;i<n;i++) {
			prod=prod-sum+A[i]+(A[i]*(n-1));
			ans=max(prod,ans);
		}
		return ans;
    }
};
