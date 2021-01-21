class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1=s1.length();
        int len2=s2.length();
        if(len1==0||len2==0||len1!=len2){
            return false;
        }
        if(s1==s2){
            return true;
        }
        string str1=s1;
        string str2=s2;
        
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        
        if(str1!=str2){
            return false;
        }
        
        for(int i=1;i<len1;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) 
               && isScramble(s1.substr(i,len1-i),s2.substr(i,len1-i))){
                return true;
            }
            if(isScramble(s1.substr(0,i),s2.substr(len1-i,i)) 
               && isScramble(s1.substr(i,len1-i),s2.substr(0,len1-i))){
                return true;
            }
        }
        return false;
    }
};
