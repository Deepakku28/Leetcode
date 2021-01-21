class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        return false;
    }
    
    string toGoatLatin(string str) {
        int n=str.size();
        vector<string> val;
        string curr="";
        for(int i=0;i<n;i++){
            if(str[i]==' '){
            val.push_back(curr);
                curr="";
            }
            else{
                curr+=str[i];
            }
        }
        val.push_back(curr);
        curr='a';
        string add="ma";
        for(int i=0;i<val.size();i++){
            if(isVowel(val[i][0])==true){
                string temp=val[i];
                temp=temp+add+curr;
                val[i]=temp;
            }
            else{
                string temp=val[i];
                temp=val[i].substr(1)+val[i].substr(0,1)+add+curr;
                val[i]=temp;
            }
            curr+='a';
        }
        string ans="";
        for(int i=0;i<val.size();i++){
            if(i==val.size()-1){
                ans+=val[i];
            }
            else{
                ans+=val[i]+" ";
            }
        }
        return ans;
    }
};
