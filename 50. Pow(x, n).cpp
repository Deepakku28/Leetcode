class Solution {
public:
    double helper(double &x,int n){
        if(n==0){
            return 1;
        }
        double ans=helper(x,n/2);
        if(n%2){
            return ans*ans*x;
        }
        else{
            return ans*ans;
        }
    }
    
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        else if(n<0){
            x=1/x;
        }
        return helper(x,abs(n));
    }
};
