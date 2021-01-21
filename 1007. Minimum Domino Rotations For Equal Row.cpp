class Solution {
public:
    int solution(int target,vector<int>& val1,vector<int>& val2){
        int swap=0;
        for(int i=0;i<val1.size();i++){
            if(val1[i]!=target){
                if(val2[i]!=target){
                    return INT_MAX;
                }
                else{
                    swap++;
                }
            }
        }
        return swap;
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans=min({solution(A[0],A,B),solution(B[0],A,B),solution(A[0],B,A),solution(B[0],B,A)});
        return (ans==INT_MAX)?-1:ans;
    }
};
