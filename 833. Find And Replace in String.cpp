class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n=indexes.size();
        string ans="";
        vector<pair<int,int>> sorted;
        for(int i=0;i<n;i++){
            sorted.push_back({indexes[i],i});
        }
        sort(sorted.rbegin(),sorted.rend());
        for(int i=0;i<n;i++){
            pair<int,int> curr=sorted[i];
            string s=sources[curr.second];
            string t=targets[curr.second];
            if(S.substr(curr.first,s.size())==s){
                S=S.substr(0,curr.first)+t+S.substr(curr.first+s.size());
            }
        }
        return S;
    }
};
