class Solution {
public:
    string removeOuterParentheses(string S) {
        int n=S.size();
        int j=0;
        string ans="";
        if(n<=2){
            return ans;
        }
        int open=0;
        int close=0;
        for(int i=0;i<n;i++){
            if(S[i]=='('){
                open++;
            }
            else if(S[i]==')'){
                close++;
            }
            if(open==close){
                open=0;
                close=0;
                ans+=S.substr(j+1,i-j-1);
                j=i+1;
            }
        }
        return ans;
    }
};
