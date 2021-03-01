class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        int n=str.size();
        int count=0;
        for(int i=0;i<str[0].size();i++){
            for(int j=1;j<n;j++){
                if(str[j][i]<str[j-1][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
