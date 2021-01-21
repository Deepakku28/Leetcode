class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                if(islower(s[i])){
                    str+=s[i];
                }
                else{
                    str+=(s[i]+32);
                }
            }
        }
        int end=str.size()-1;
        int start=0;
        while(start<=end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
