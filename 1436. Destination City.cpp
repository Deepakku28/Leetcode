class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for(int i=0;i<paths.size();i++){
            s.insert(paths[i][0]);
        }
        for(int i=0;i<paths.size();i++){
            if(s.count(paths[i][1])==0){
                return paths[i][1];
            }
        }
        return "";
    }
};
