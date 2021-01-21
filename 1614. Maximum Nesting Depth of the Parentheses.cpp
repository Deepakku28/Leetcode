class Solution {
public:
    int maxDepth(string s) {
        int temp=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                temp++;
            }
            else if(s[i]==')'){
                temp--;
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};
