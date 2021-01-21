class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
	    int index2=0,index3=0,index5=0;
	    int value2=2;
	    int value3=3;
	    int value5=5;
	    for(int i=1;i<n;i++){
	        int minimum=min({value2,value3,value5});
	        dp[i]=minimum;
	        if(value2==minimum){
	            index2++;
	            value2=2*dp[index2];
	        }
	        if(value3==minimum){
	            index3++;
	            value3=3*dp[index3];
	        }
	        if(value5==minimum){
	            index5++;
	            value5=5*dp[index5];
	        }
	    }
	    return dp[n-1];
    }
};
