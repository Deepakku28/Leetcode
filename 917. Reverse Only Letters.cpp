class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n=S.size();
        int start=0;
        int end=n-1;
        while(start<end){
            if(!isalpha(S[start])){
                start++;
            }
            else if(!isalpha(S[end])){
                end--;
            }
            else{
                swap(S[start],S[end]);
                start++;
                end--;
            }
        }
        return S;
    }
};
