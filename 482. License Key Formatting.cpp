class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int n=S.size();
        string temp="";
        for(int i=0;i<n;i++){
            if(S[i]!='-'){
                if ('a'<=S[i] && S[i]<='z'){
                    temp+=(S[i]-'a'+'A');
                }   
                else{
                    temp+=S[i];
                }
            }
        }
        if(temp.empty()){
            return "";
        }
        int len=temp.size();
        string ans="";
        reverse(temp.begin(),temp.end());
        for (int i=0;i<len;i=i+K){
            ans+=temp.substr(i,K)+'-';
        }
        reverse(ans.begin(),ans.end());
        ans=ans.substr(1);
        return ans;
    }
};
