class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0){
            return 0;
        }
        int n=s.size()-1;
        bool flag=true;
        int ans=0;
        while(n>=0){
            if(s[n]!=' '){
                ans++;
                flag=false;
            }
            else if(flag==false){
                break;
            }
            n--;
        }
        return ans;
    }
};
