class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.size()-1;
        int len2=num2.size()-1;
        int carry=0;
        string ans="";
        while(len1>=0 || len2>=0 || carry>0){
            if(len1>=0){
                carry+=(num1[len1]-'0');
                len1--;
            }
            if(len2>=0){
                carry+=(num2[len2]-'0');
                len2--;
            }
            ans=to_string(carry%10)+ans;
            carry=carry/10;
        }
        return ans;
    }
};
