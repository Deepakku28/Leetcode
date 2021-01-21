class Solution {
public:
    
    void dfs(vector<vector<int>>& image,int x,int y,int &row,int &col,int &newColor,int &color){
        if(x<0 || y<0 || x>=row || y>=col || image[x][y]!=color || image[x][y]==newColor){
            return ;
        }
        image[x][y]=newColor;
        dfs(image,x,y+1,row,col,newColor,color);
        dfs(image,x+1,y,row,col,newColor,color);
        dfs(image,x,y-1,row,col,newColor,color);
        dfs(image,x-1,y,row,col,newColor,color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row=image.size();
        int col=image[0].size();
        int color=image[sr][sc];
        dfs(image,sr,sc,row,col,newColor,color);
        
        return image;
    }
};
