class Solution {
public:
    int numberOfSteps (int num) {
        if(num==0){
            return 0;
        }
        unsigned int count_one=0;
        unsigned int count_bit=0;
        while(num){
            if(num&1){
                count_one++;
            }
            num=num>>1;
            count_bit++;
        }
        return (count_bit+count_one-1);
    }
};
