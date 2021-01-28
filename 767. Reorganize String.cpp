class Solution {
public:
    string reorganizeString(string S) {
        vector<int> mp(26,0);
        int n=S.size();
        for(int i=0;i<n;i++){
            mp[S[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(mp[i]>(n+1)/2){
                return "";
            }
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            if(mp[i]){
                pq.push(make_pair(mp[i],'a'+i));
            }
        }
        string ans="";
        while(!pq.empty()){
            pair<int, char> p1,p2;
            p1=pq.top();
            pq.pop();
            ans.push_back(p1.second);
            if(!pq.empty()) {
                p2=pq.top();
                pq.pop();
                ans.push_back(p2.second);
                p2.first--;
                if(p2.first){
                    pq.push(p2);
                }
            }
            p1.first--;
            if(p1.first){
                pq.push(p1);
            }
        }
        return ans;
    }
};
