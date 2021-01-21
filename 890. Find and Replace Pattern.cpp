class Solution {
public:
    bool solution(string str,string pat){
        int m=str.size();
        int n=pat.size();
        if(m!=n){
            return false;
        }
        vector<char> mpStr(26,' ');
        vector<char> mpPat(26,' ');
        for(int i=0;i<n;i++){
            int index1=pat[i]-'a';
            int index2=str[i]-'a';
            if(mpStr[index1]==' ' && mpPat[index2]==' '){
                mpStr[index1]=str[i];
                mpPat[index2]=pat[i];
            }
            else if(mpStr[index1]!=str[i] || mpPat[index2]!=pat[i]){
                return false;
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n=words.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(solution(words[i],pattern)==true){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
