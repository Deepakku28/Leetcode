class Solution {
public:
    long long int solution(int n){
        if(n<=1){
            return 1;
        }
        else if(n%2==0){
            return 1+(solution(n/2));
        }
        else{
            if(n>=INT_MAX){
                return solution(n-1);
            }
            else{
                return 1+min(solution(n-1),solution(n+1));
            }
        }
    }
    
    int integerReplacement(int n) {
        return (long)solution(n)-1;
    }
};
