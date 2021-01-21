class Solution {
public:
    vector<string> generateBoard(vector<int> &queens,int &n){
        vector<string> temp;
        int len=queens.size();
        for(int i=0;i<len;i++){
            string str="";
            for(int col=0;col<n;col++){
                if(col==queens[i])
                    str='Q'+str;
                else 
                    str='.'+str;
            }
            temp.push_back(str);
        }
        return temp;
    }
    
    bool isSafe(vector<int> &queens){
        int lastPlacedQueenColumn=queens.size()-1;
        for(int i=0;i<lastPlacedQueenColumn;i++){
            int absoluteColDistance=abs(queens[i]-queens[lastPlacedQueenColumn]);
            int absoluteRowDistance=lastPlacedQueenColumn-i;
            if(absoluteColDistance==0 or absoluteColDistance==absoluteRowDistance)
                return false;
        }
        return true;
    }
    
    void solveNQueensUtil(int &n,int row,vector<vector<string>> &ans,vector<int> &queens){
        if(row==n){
            ans.push_back(generateBoard(queens,n));
            return ;
        }
        for(int col=0;col<n;col++){
            queens.push_back(col);
            if(isSafe(queens)){
                solveNQueensUtil(n,row+1,ans,queens);
            }
            queens.pop_back();
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        if(n==2 || n==3){
            return 0;
        }
        vector<int> queens;
        solveNQueensUtil(n,0,ans,queens);
        return (int)ans.size();
    }
};
