class Solution {
public:
    int compare(vector<vector<int>>& a, vector<vector<int>>& b,int &row,int &col,int &m,int &n){
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i+row>=0 && i+row<m && j+col>=0 && j+col<n && a[i][j]==1 && b[i+row][j+col]==1){
                    count++;
                }
            }
        }
        return count;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        int m=img1.size();
        int n=img1[0].size();
        for(int i=-m+1;i<m;i++){
            for(int j=-n+1;j<n;j++){
                ans=max(ans,compare(img1,img2,i,j,m,n));
            }
        }
        return ans;
    }
};
