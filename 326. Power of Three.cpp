class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n && n%3==0){
            n=n/3;
        }
        if(n==1){
            return true;
        }
        return false;
    }
};
