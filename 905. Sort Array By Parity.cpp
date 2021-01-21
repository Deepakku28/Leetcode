class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n=A.size();
        int curr=0;
        for(int start=0;start<n;start++){
            if(A[start]%2==0){
                swap(A[start],A[curr]);
                curr++;
            }
        }
        return A;
    }
};
