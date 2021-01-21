class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>> sorted;
        for(auto it:mp){
            sorted.push_back({it.second,it.first});
        }
        string str="";
        sort(sorted.begin(),sorted.end(),greater<pair<int,char>>());
        for(int i=0;i<sorted.size();i++){
            int index=sorted[i].first;
            char ch=sorted[i].second;
            for(int j=0;j<index;j++){
                str+=ch;
            }
        }
        return str;
    }
};
