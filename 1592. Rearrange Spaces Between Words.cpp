class Solution {
public:
    string reorderSpaces(string text) {
        stringstream str(text);
        string word;
        vector<string> val;
        while(str>>word){
            val.push_back(word);
        }
        int sCount=0;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                sCount++;
            }
        }
        if(sCount==0){
            return text;
        }
        int eSpace=val.size()==1?0:sCount/(val.size()-1);
        int endSpace=val.size()==1?sCount:sCount%(val.size()-1);
        string ans="";
        for(int i=0;i<val.size();i++){
            ans+=val[i];
            if(i!=val.size()-1){
                ans+=string(eSpace,' ');
            }
        }
        ans+=string(endSpace,' ');
        return ans;
    }
};
