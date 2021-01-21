class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        int min=strs[0].length();
        for(int i=1;i<strs.size();i++){
            if(min>strs[i].length()){
                min=strs[i].length();
            }
            for(int j=0;j<min;j++){
                if(strs[i][j] != strs[i-1][j]){
                    min=j;
                    break;
                }
            }
        }
        return strs[0].substr(0,min);
    }
};
