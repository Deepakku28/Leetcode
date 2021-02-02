class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int row=arr.size();
        for(int i=1;i<row;i++){
            for(int j=0;j<row;j++){
                int minVal=INT_MAX;
                for(int k=0;k<row;k++){
                    if(k!=j){
                        minVal=min(minVal,arr[i-1][k]);
                    }
                }
                arr[i][j]+=minVal;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<row;i++){
            ans=min(ans,arr[row-1][i]);
        }
        return ans;
    }
};
