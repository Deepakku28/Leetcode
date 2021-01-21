class Solution {
public:
    string makeGood(string s) {
        int i=0;
        while(s.length() && i<s.length()-1){
            if(s[i]!=s[i+1] && tolower(s[i])==tolower(s[i+1])){
                s.erase(i,2);
                if(--i<0){
                    i=0;
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
};
