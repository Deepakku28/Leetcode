class Solution {
public:
    
    void backtrack(vector<string>& result,string S,int pos){
        if(pos==S.length()){
            result.push_back(S);
            return;
        }
        if(S[pos]>='a' && S[pos]<='z'){
            backtrack(result,S,pos+1);
            S[pos]='A'+(S[pos]-'a');
            backtrack(result,S,pos+1);
        }
        else if(S[pos]>='A' && S[pos]<='Z'){
            backtrack(result,S,pos+1);
            S[pos]='a'+(S[pos]-'A');
            backtrack(result,S,pos+1);
        }
        else{
            backtrack(result,S,pos+1);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        if(S.length()==0){
            return result;
        }
        backtrack(result,S,0);
        return result;
    }
};
