class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int r=0;
        for(int i=0;i<row;i++){
            if(matrix[i][0]<=target && matrix[i][col-1]>=target){
                r=i;
                break;
            }
        }
        for(int i=0;i<col;i++){
            if(matrix[r][i]==target){
                return true;
            }
        }
        return false;
    }
};
