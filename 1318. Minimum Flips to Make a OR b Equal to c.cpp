class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result=0;
        for(int i=0;i<32;i++){
            bool bit_a=false,bit_b=false,bit_c=false;
            bit_a=(a&(1<<i));
            bit_b=(b&(1<<i));
            bit_c=(c&(1<<i));
            
            if(bit_c==false){
                if(bit_a==true && bit_b==true){
                    result=result+2;
                }
                else if(bit_a==true || bit_b==true){
                    result=result+1;
                }
            }
            else if(bit_c==true){
                if(bit_a==false && bit_b==false){
                    result=result+1;
                }
            }
        }
        return result;
    }
};
