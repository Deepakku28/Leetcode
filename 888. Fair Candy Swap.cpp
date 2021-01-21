class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA=0,sumB=0;
        int m=A.size();
        int n=B.size();
        for(int i=0;i<m;i++){
            sumA+=A[i];
        }
        for(int i=0;i<n;i++){
            sumB+=B[i];
        }
        int temp=(sumB-sumA)/2;
        unordered_set<int> s(B.begin(),B.end());
        for(int i=0;i<m;i++){
            if(s.find(A[i]+temp)!=s.end()){
                return {A[i],A[i]+temp};
            }
        }
        return {};
    }
};
