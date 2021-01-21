class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n=A.size();
        for(int i=0;i<n;i++){
            if(A[i]==i+1 || A[i]==i-1 || A[i]==i){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
