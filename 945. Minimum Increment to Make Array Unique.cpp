class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n=A.size();
        sort(A.begin(),A.end());
        int count=0;
        for(int i=1;i<n;i++){
            if(A[i]<=A[i-1]){
                count+=A[i-1]-A[i]+1;
                A[i]=A[i-1]+1;
            }
        }
        return count;
    }
};
