class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    string str="("+to_string(board[i][j])+")";
                    if(s.count(to_string(i)+str)){
                        return false;
                    }
                    if(s.count(str+to_string(j))){
                        return false;
                    }
                    if(s.count(to_string(i/3)+str+to_string(j/3))){
                        return false;
                    }
                    s.insert(to_string(i)+str);
                    s.insert(str+to_string(j));
                    s.insert(to_string(i/3)+str+to_string(j/3));
                }
            }
        }
        return true;
    }
};
