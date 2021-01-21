class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int countUpper=0;
        int countLower=0;
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z'){
                countUpper++;
            }
            else if(word[i]>='a' && word[i]<='z'){
                countLower++;
            }
        }
        //cout<<countUpper<<" "<<countLower<<endl;
        if(countUpper==n || countLower==n){
            return true;
        }
        else if(countUpper==1 && isupper(word[0]) && countLower==n-1){
            return true;
        }
        else{
            return false;
        }
    }
};
