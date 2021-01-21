class Solution {
public:
    char findTheDifference(string s, string t) {
        int res=0;
        for(int i=0;i<s.length();i++){
            res=(res^(s[i]-'a'));
        }
        for(int i=0;i<t.length();i++){
            res=(res^(t[i]-'a'));
        }
        return (char)(res+'a');
    }
};
