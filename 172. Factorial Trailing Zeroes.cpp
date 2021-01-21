class Solution {
public:
    int trailingZeroes(int n) {
        int count5=0;
        while(n){
            count5+=n/5;
            n/=5;
        }
        return count5;
    }
};
