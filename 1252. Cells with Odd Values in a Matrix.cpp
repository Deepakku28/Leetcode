class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<indices.size();i++){
            row[indices[i][0]]^=1;
            col[indices[i][1]]^=1;
        }
        int r=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(row[i]){
                r++;
            }
        }
        for(int i=0;i<m;i++){
            if(col[i]){
                c++;
            }
        }
        return (n*c+m*r-2*r*c);
    }
};
