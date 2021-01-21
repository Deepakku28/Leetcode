class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int notSwapped=0;
        int swapped=1;
        int n=A.size();
        for(int i=1;i<n;i++){
            int newNotswapped=INT_MAX;
            int newSwapped=INT_MAX;
            if(A[i-1]<A[i] && B[i-1]<B[i]){
                newNotswapped=min(newNotswapped,notSwapped);
                newSwapped=min(newSwapped,swapped+1);
            }
            if(A[i-1]<B[i] && B[i-1]<A[i]){
                newNotswapped=min(newNotswapped,swapped);
                newSwapped=min(newSwapped,notSwapped+1);
            }
            notSwapped=newNotswapped;
            swapped=newSwapped;
        }
        return min(notSwapped,swapped);
    }
};
