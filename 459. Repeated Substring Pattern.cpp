class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int i=n/2;i>0;i--){
            if(n%i==0){
                int repeat=n/i;
                string subString=s.substr(0,i);
                string str="";
                for(int j=0;j<repeat;j++){
                    str+=subString;
                }
                if(s==str){
                    return true;
                }
            }
        }
        return false;
    }
};
