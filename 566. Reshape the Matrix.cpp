class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row=nums.size();
        int col=nums[0].size();
        if(row==0 || col==0 || r==0 || c==0 || row*col!=r*c){
            return nums;
        }
        vector<int> val;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                val.push_back(nums[i][j]);
            }
        }
        int index=0;
        vector<vector<int>> mat(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mat[i][j]=val[index];
                index++;
            }
        }
        return mat;
    }
};
