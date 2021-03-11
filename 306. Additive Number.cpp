class Solution {
public:
    string add(string &num1,string &num2){
        string ans="";
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        while(i>=0 || j>=0 || carry>0){
            int sum=(i>=0?(num1[i--]-'0'):0)+(j>=0?(num2[j--]-'0'):0)+carry;
            ans=(char)((sum%10)+'0')+ans;
            carry=sum/10;
        }
        return ans;
    }
    
    bool helper(string num1,string num2,string rem){
        if((num1.size()>1 && num1[0]=='0') || (num2.size()>1 && num2[0]=='0')){
            return false;
        }
        string sum=add(num1,num2);
        if(rem==sum){
            return true;
        }
        if(rem.size()<sum.size()){
            return false;
        }
        else{
            return helper(num2,sum,rem.substr(sum.size()));
        }
    }
    
    bool isAdditiveNumber(string num) {
        int n=num.size();
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=(n-i)/2;j++){
                if(helper(num.substr(0,i),num.substr(i,j),num.substr(i+j))){
                    return true;
                }
            }
        }
        return false;
    }
};
