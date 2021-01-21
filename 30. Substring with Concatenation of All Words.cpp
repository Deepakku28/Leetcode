class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size();
        int m=words[0].size();
        int k=s.size()-n*m;
        unordered_map<string,int> mp;
        for(auto it:words){
            mp[it]++;
        }
        vector<int> ans;
        for(int i=0;i<=k;i++){
            string curr=s.substr(i,(n*m));
            int count=0;
            unordered_map<string,int> tempMap;
            for(int j=0;j<curr.size();j=j+m){
                string str=curr.substr(j,m);
                tempMap[str]++;
                if(tempMap[str]<=mp[str]){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count==n){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
