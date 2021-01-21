class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        int sum=0;
        for(int i=1;i<=n;i=i+2){
            for(int j=0;j<=n-i;j++){
                if(j==0){
                    sum+=arr[i-1];
                }
                else{
                    sum+=arr[i+j-1]-arr[j-1];
                }
            }
        }
        return sum;
    }
};
