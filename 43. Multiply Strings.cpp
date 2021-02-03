class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0' || num2[0]=='0'){
            return "0";
        }
        int n=num1.size();
        int m=num2.size();
        string ans=string(n+m,'0');
        for(int i=n-1;i>=0;i--){
            int carry=0;
            for(int j=m-1;j>=0;j--){
                int temp=(ans[i+j+1]-'0')+carry+((num1[i]-'0')*(num2[j]-'0'));
                ans[i+j+1]=(temp%10)+'0';
                carry=temp/10;
            }
            ans[i]+=carry;
        }
        reverse(ans.begin(),ans.end());
        while(ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
