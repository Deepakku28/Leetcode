class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<1){
            return {};
        }
        vector<string> result;
        unordered_map<string,int> mp;
        for(int i=0;i+10<=s.length();i++){
            string curr=s.substr(i,10);
            mp[curr]++;
        }
        for(auto it:mp){
            if(it.second>1){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
