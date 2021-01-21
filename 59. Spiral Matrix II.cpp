class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int rowStart=0;
        int rowEnd=n-1;
        int colStart=0;
        int colEnd=n-1;
        int val=1;
        while(rowStart<=rowEnd && colStart<=colEnd){
            for(int i=colStart;i<=colEnd;i++){
                ans[rowStart][i]=val;
                val++;
            }
            rowStart++;
            
            for(int i=rowStart;i<=rowEnd;i++){
                ans[i][colEnd]=val;
                val++;
            }
            colEnd--;
            
            if(rowStart<=rowEnd){
                for(int i=colEnd;i>=colStart;i--){
                    ans[rowEnd][i]=val;
                    val++;
                }
            }
            rowEnd--;
            
            if(colStart<=colEnd){
                for(int i=rowEnd;i>=rowStart;i--){
                    ans[i][colStart]=val;
                    val++;
                }
            }
            colStart++;
        }
        return ans;
    }
};
