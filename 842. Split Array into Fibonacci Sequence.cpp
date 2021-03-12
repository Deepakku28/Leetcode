class Solution {
public:
    string add(string num1,string num2){
        string ans="";
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        while(i>=0 || j>=0 || carry>0){
            int sum=carry+(i>=0?num1[i--]-'0':0)+(j>=0?num2[j--]-'0':0);
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
        if(sum==rem){
            return true;
        }
        if(sum.size()>rem.size()){
            return false;
        }
        else{
            return helper(num2,sum,rem.substr(sum.size()));
        }
    }
    
    void generateFibonacciSequence(string num1,string num2,string str,vector<int> &ans){
        int n=str.size();
        int i=num1.size()+num2.size();
        long long int val1=stol(num1);
        long long int val2=stol(num2);
        if(val1>=INT_MAX || val2>=INT_MAX){
            return;
        }
        ans.push_back(val1);
        ans.push_back(val2);
        while(i<n){
            long long int val3=val1+val2;
            if(val3>=INT_MAX){
                ans.clear();
                return;
            }
            ans.push_back(val3);
            string num=to_string(val3);
            i+=num.size();
            val1=val2;
            val2=val3;
        }
    }
    
    vector<int> splitIntoFibonacci(string str) {
        int n=str.size();
        vector<int> ans;
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=n/2;j++){
                if(helper(str.substr(0,i),str.substr(i,j),str.substr(i+j))==true){
                    generateFibonacciSequence(str.substr(0,i),str.substr(i,j),str,ans);
                    return ans;
                }
            }
        }
        return {};
    }
};
