class Solution {
public:
    int ladderLength(string start, string target, vector<string>& dict) {
        set<string> D(dict.begin(),dict.end());
        if(D.find(target)==D.end()){
            return 0;
        }
        queue<string> q;
        int steps=1;
        q.push(start);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return steps;
                }
                D.erase(curr);
                for(int i=0;i<curr.size();i++){
                    char ch=curr[i];
                    for(int j=0;j<26;j++){
                        curr[i]='a'+j;
                        if(D.find(curr)!=D.end()){
                            q.push(curr);
                            D.erase(curr);
                        }
                    }
                    curr[i]=ch;
                }
            }
            steps++;
        }
        return 0;
    }
};
