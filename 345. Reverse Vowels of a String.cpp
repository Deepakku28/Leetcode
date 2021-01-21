class Solution {
public:
    bool checkVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        int n=s.size();
        int start=0;
        int end=n-1;
        while(start<end){
            if(!checkVowel(s[start])){
                start++;
            }
            else if(!checkVowel(s[end])){
                end--;
            }
            else{
                swap(s[start],s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};
