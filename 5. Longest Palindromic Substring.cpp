class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0){
            return "";
        }
        else if(n==1){
            return s;
        }
        int start=0;
        int max_len=1;
        for(int i=1;i<n;i++){
            check(s,i-1,i,start,max_len);
            check(s,i-1,i+1,start,max_len);
        }
        return s.substr(start,max_len);
    }
    void check(string s,int left,int right,int& start,int& max_len){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            if(right-left+1>max_len){
                start=left;
                max_len=right-left+1;
            }
            left--;
            right++;
        }
    }
};
