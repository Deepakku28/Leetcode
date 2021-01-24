class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> mp;
        for (auto &ch:paragraph){
            ch=isalpha(ch)?tolower(ch):' ';
        }
        stringstream str(paragraph);
        string temp;
        while(str>>temp){
            mp[temp]++;
        }
        for(auto it:banned){
            transform(it.begin(),it.end(),it.begin(),::tolower);
            mp.erase(it);
        }
        int maxVal=0;
        string maxStr="";
        for(auto it:mp){
            if(maxVal<it.second){
                maxVal=it.second;
                maxStr=it.first;
            }
        }
        return maxStr;
    }
};
