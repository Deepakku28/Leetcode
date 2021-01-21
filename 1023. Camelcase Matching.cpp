class Solution {
public:
    bool isMatch(string str,string pattern){
        int index=0;
        int m=pattern.size();
        int n=str.size();
        for(int i=0;i<n;i++){
            if(index<n && str[i]==pattern[index]){
                index++;
            }
            else if(str[i]>='A' && str[i]<='Z'){
                return false;
            }
        }
        return index==m?true:false;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n=queries.size();
        vector<bool> ans;
        for(int i=0;i<n;i++){
            if(isMatch(queries[i],pattern)==true){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
