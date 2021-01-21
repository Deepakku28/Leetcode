class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int start=0;
        int end=n-1;
        while(start<end){
            char ch=s[start];
            s[start]=s[end];
            s[end]=ch;
            start++;
            end--;
        }
    }
};
