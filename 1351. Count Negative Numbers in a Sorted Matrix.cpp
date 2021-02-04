class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int i=grid.size()-1;
        int j=0;
        int ans=0;
        while(i>=0 && j<n){
            if(grid[i][j]>=0){
                j++;
            }
            else{
                ans+=n-j;
                i--;
            }
        }
        return ans;
    }
};
