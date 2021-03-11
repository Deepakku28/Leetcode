class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N==1){
            return 0;
        }
        else if(kthGrammar(N-1,(K+1)/2)==0){
            return ((K%2==1)?0:1);
        }
        else{
            return ((K%2==1)?1:0);
        }
    }
};
