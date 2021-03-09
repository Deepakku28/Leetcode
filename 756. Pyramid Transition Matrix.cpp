class Solution {
public:
    bool dfs(string &bottom,int index,unordered_map<string,vector<char>> &mp,string str){
        if(bottom.size()==1){
            return true;
        }
        if(bottom.size()-1==index){
            return dfs(str,0,mp,"");
        }
        if(mp.find(bottom.substr(index,2))==mp.end()){
            return false;
        }
        for(auto it:mp[bottom.substr(index,2)]){
            str.push_back(it);
            if(dfs(bottom,index+1,mp,str)){
                return true;
            }
            str.pop_back();
        }
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> mp;
        for(auto it:allowed){
            mp[it.substr(0,2)].push_back(it[2]);
        }
        return dfs(bottom,0,mp,"");
    }
};
