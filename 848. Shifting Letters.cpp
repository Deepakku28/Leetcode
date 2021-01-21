class Solution {
public:
    string shiftingLetters(string str, vector<int>& shifts) {
        int n=str.size();
        for(int i=n-2;i>=0;i--){
            shifts[i]=(shifts[i]+shifts[i+1])%26;
        }
        for(int i=0;i<n;i++){
            str[i]='a'+(str[i]-'a'+shifts[i])%26;
        }
        return str;
    }
};
