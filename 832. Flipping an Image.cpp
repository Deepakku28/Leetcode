class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row=A.size();
        int col=A[0].size();
        for(int i=0;i<row;i++){
            reverse(A[i].begin(),A[i].end());
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(A[i][j]==1){
                    A[i][j]=0;
                }
                else{
                    A[i][j]=1;
                }
            }
        }
        return A;
    }
};
