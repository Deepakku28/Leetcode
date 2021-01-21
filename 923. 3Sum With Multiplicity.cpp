class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int mod=1e9+7;
        sort(A.begin(),A.end());
        int n=A.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=A[i]+A[start]+A[end];
                if(sum==target){
                    int len1=1,len2=1;
                    while(start<end && A[start]==A[start+1]){
                        start++;
                        len1++;
                    }
                    while(start<end && A[end]==A[end-1]){
                        end--;
                        len2++;
                    }
                    if(start==end){
                        ans=(ans+len1*(len1-1)/2)%mod;
                    }
                    else{
                        ans=(ans+len1*len2)%mod;
                    }
                    start++;
                    end--;
                }
                else if(sum<target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return ans;
    }
};
