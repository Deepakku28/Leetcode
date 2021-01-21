class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int end=0;
        int start=0;
        int n=s.size();
        while(end<n){
            char letter=s[end];
            int count=0;
            while(end<n && s[end]==letter){
                end++;
                count++;
            }
            if(count >= 3){
                ans.push_back({start,end-1});
            }
            start=end;
        }
        return ans;
    }
};
