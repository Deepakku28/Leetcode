class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n=A.size();
        bool inc=true;
        bool dec=true;
        for(int i=1;i<n;i++){
            inc=inc&(A[i]>=A[i-1]);
            dec=dec&(A[i]<=A[i-1]);
        }
        return (inc||dec);
    }
};
