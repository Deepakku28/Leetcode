class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int len=mat.size();
        for(int i=0;i<len;i++){
            sum+=mat[i][i]+mat[i][len-1-i];
        }
        if(len%2==1){
            sum=sum-mat[len/2][len/2];
        }
        return sum;
    }
};
