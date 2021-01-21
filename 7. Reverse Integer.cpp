class Solution {
public:
    int reverse(int x) {
        int temp=0,reverse=0;
        while(x){
            temp = x%10;
            x = x/10;
            if((reverse>INT_MAX/10) || (reverse==INT_MAX/10 && temp>7) || (reverse<INT_MIN/10) || (reverse==INT_MIN/10 && temp<-8)){
                return 0;
            }
            reverse = reverse*10 + temp;
        }
        return reverse;
    }
};
