class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2==1){
            return false;
        }
        int i=0;
        stack<char> st;
        for(i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else if(!st.empty() && ((st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']') ||                        (st.top()=='{' && s[i]=='}') )){
                st.pop();
            }
            else{
                return false;
            }
        }
        if(st.empty() &&  i==s.length()){
            return true;
        }
        else{
            return false;
        }
    }
};
