class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<char> s;
        int count=0;
        int n=str.size();
        for(int i=0;i<n;i++){
            if(str[i]=='('){
                s.push(str[i]);
                count++;
            }
            else{
                if(count>0){
                    s.pop();
                    count--;
                }
                else{
                    s.push(str[i]);
                }
            }
        }
        return s.size();
    }
};
