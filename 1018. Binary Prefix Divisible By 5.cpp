class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n=A.size();
        vector<bool> ans(n,false);
        int val=0;
        for(int i=0;i<n;i++){
            val=(val*2+A[i])%5;
            if(val==0){
                ans[i]=true;
            }
        }
        return ans;
    }
};
