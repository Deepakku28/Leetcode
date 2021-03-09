class Solution {
public:
    vector<string> helper(string str){
        vector<string> ans;
        for(int i=0;i<4;i++){
            string curr=str;
            curr[i]=(str[i]-'0'+1)%10+'0';
            ans.push_back(curr);
            curr[i]=(str[i]-'0'-1+10)%10+'0';
            ans.push_back(curr);
        }
        return ans;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dict(deadends.begin(),deadends.end());
        unordered_set<string> visited;
        if(dict.find(target)!=dict.end() || dict.find("0000")!=dict.end()){
            return -1;
        }
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int steps=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return steps;
                }
                vector<string> temp=helper(curr);
                for(auto it:temp){
                    if(visited.find(it)!=visited.end()){
                        continue;
                    }
                    if(dict.find(it)==dict.end()){
                        visited.insert(it);
                        q.push(it);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
