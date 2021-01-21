class Solution {
public:
    int maxHistArea(vector<int> val,int &col){
        stack<int> s;
        int maxArea=0;
        int currArea=0;
        int i=0;
        while(i<col){
            if(s.empty()){
                s.push(i);
                i++;
            }
            else if(val[s.top()]<=val[i]){
                s.push(i);
                i++;
            }
            else{
                int currTop=s.top();
                s.pop();
                if(s.empty()){
                    currArea=val[currTop]*i;
                }
                else{
                    currArea=val[currTop]*(i-s.top()-1);
                }
                maxArea=max(maxArea,currArea);
            }
        }
        while(!s.empty()){
            int currTop=s.top();
            s.pop();
            if(s.empty()){
                currArea=val[currTop]*i;
            }
            else{
                currArea=val[currTop]*(i-s.top()-1);
            }
            maxArea=max(maxArea,currArea);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(row==0){
            return 0;
        }
        int col=matrix[0].size();
        if(col==0){
            return 0;
        }
        vector<vector<int>> mat(row,vector<int>(col));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j]=matrix[i][j]-'0';
            }
        }
        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]!=0){
                    mat[i][j]+=mat[i-1][j];
                }
                else{
                    mat[i][j]=0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<row;i++){
            int currArea=maxHistArea(mat[i],col);
            ans=max(ans,currArea);
        }
        return ans;
    }
};
