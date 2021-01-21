class Solution {
public:
    string addBinary(string a, string b) {
        int len1=a.size()-1;
        int len2=b.size()-1;
        string ans="";
        int carry=0;
        while(len1>=0 || len2>=0 || carry>0){
            if(len1>=0) {
                carry+=a[len1]=='0'?0:1;
                len1--;
            }
            if(len2>= 0) {
                carry+=b[len2]=='0'?0:1;
                len2--;
            }
            ans=((carry%2)==0?"0":"1")+ans;
            carry/=2;
        }
        return ans;
    }
};
