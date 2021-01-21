class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n=A.size();
        int one=0;
        int maxLen=0;
        int start=0;
        for(int end=0;end<n;end++){
            one+=A[end];
            if(end-start-one+1>K){
                if(A[start]==1){
                    one--;
                }
                start++;
            }
            maxLen=max(maxLen,end-start+1);
        }
        return maxLen;
    }
};
