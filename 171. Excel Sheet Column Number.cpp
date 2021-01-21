class Solution {
public:
    int titleToNumber(string s) {
        int counter=0;
        int n=s.size()-1;
        for(int i=0;i<=n;i++) {
            counter+=(s[i]-64)*pow(26,(n-i));
        }
        return counter;
    }
};
