class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n=A.size();
        int start=0;
        int end=n-1;
        while(start+1<n && A[start]<A[start+1]){
            start++;
        }
        while(end>0 && A[end-1]>A[end]){
            end--;
        }
        return (start>0 && end<n-1 && start==end);
    }
};
