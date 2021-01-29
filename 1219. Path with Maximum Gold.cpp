class Solution {
public:
    int find(vector<vector<int>> &grid,int i,int j){
        int ans=0;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return 0;
        }
        int temp=grid[i][j];
        grid[i][j]=0;
        ans=max({ans,find(grid,i-1,j),find(grid,i+1,j),find(grid,i,j-1),find(grid,i,j+1)});
        grid[i][j]=temp;
        return ans+temp;
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,find(grid,i,j));
                }
            }
        }
        return ans;
    }
};
