class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int row=A.size();
        int col=A[0].size();
        if(row==0 || col==0){
            return 0;
        }
        for(int i=row-2;i>=0;i--){
            for(int j=0;j<col;j++){
                if(j==0){;
                    A[i][j]=A[i][j]+min(A[i+1][j],A[i+1][j+1]);
                }
                else if(j==col-1){
                    A[i][j]=A[i][j]+min(A[i+1][j],A[i+1][j-1]);
                }
                else{
                    A[i][j]=A[i][j]+min(A[i+1][j],min(A[i+1][j+1],A[i+1][j-1]));
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<A[0].size();i++){
            ans=min(ans,A[0][i]);
        }
        return ans;
    }
};
