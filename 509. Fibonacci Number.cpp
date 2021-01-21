class Solution {
public:
    int fib(int N) {
        if(N<2){
            return N;
        }
        int first=0;
        int second=1;
        for(int i=2;i<=N;i++){
            int temp=first+second;
            first=second;
            second=temp;
        }
        return second;
    }
};
