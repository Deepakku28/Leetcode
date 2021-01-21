class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> direction{{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val=mat[i][j];
                int count=1;
                for(auto it:direction){
                    int x=i+it[0];
                    int y=j+it[1];
                    if(x>=0 && x<m && y>=0 && y<n){
                        val+=mat[x][y];
                        count++;
                    }
                }
                ans[i][j]=floor(val/count);
            }
        }
        return ans;
    }
};
