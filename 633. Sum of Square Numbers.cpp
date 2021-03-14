class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int left=0;
        long long int right=sqrt(c);
        while(left<=right){
            long long int val = left*left + right*right;
            if(val == c){
                return true;
            }
            else if(val < c){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }
};
