class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0 || matrix[0].size()==0){
            return 0;
        }
        int ans=0;
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> mat(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    mat[i][j]=1;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 || j==0){
                    ans=max(ans,mat[i][j]);
                }
                else if(mat[i][j]==1){
                    mat[i][j]+=min({mat[i-1][j-1],mat[i-1][j],mat[i][j-1]});
                    ans=max(ans,mat[i][j]);
                }
            }
        }
        if(ans==0){
            return 0;
        }
        else{
            return ans*ans;
        }
    }
};
