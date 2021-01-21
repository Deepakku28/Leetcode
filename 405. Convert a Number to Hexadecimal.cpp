class Solution {
public:
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        string mp="0123456789abcdef";
        string ans="";
        unsigned n=num;
        while(n){
            ans=ans+mp[n%16];
            n=n/16;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
