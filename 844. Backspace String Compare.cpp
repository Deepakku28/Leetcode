class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string str1="";
        for(int i=0;i<S.size();i++){
            if(str1.size()==0 && S[i]=='#'){
                continue;
            }
            else if(S[i]!='#'){
                str1.push_back(S[i]);
            }
            else if(S[i]=='#'){
                str1.pop_back();
            }
        }
        string str2="";
        for(int i=0;i<T.size();i++){
            if(str2.size()==0 && T[i]=='#'){
                continue;
            }
            else if(T[i]!='#'){
                str2.push_back(T[i]);
            }
            else if(T[i]=='#'){
                str2.pop_back();
            }
        }
        return (str1==str2);
    }
};
