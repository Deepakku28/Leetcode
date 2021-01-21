class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string> val;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            string temp="";
            for(;i<n;i++){
                if(s[i]==' '){
                    break;
                }
                temp+=s[i];
            }
            val.push_back(temp);
        }
        string ans="";
        reverse(val.begin(),val.end());
        for(int i=0;i<val.size();i++){
            ans+=val[i];
            if(i!=val.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};
