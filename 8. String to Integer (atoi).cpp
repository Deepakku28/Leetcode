class Solution {
public:
    int myAtoi(string s) {
        bool negative=false;
        bool start=false;
        long long num=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && start==false){
                continue;
            }
            else if(s[i]=='-' && start==false){
                negative=true;
                start=true;
            }
            else if(s[i]=='+' && start==false){
                start=true;
            }
            else if(isdigit(s[i])==false) {
                break;
            }
            else{
                num=(num*10)+s[i]-'0';
                if(num>INT_MAX) {
                    return (negative)?INT_MIN:INT_MAX;
                }
                start=true;
            }
        }
        return negative?(-1*num):num;
    }
};
