class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> mp;
        string str="";
        for(auto it:T){
            mp[it]++;
        }
        for(auto it:S){
            if(mp.find(it)==mp.end()){
                continue;
            }
            while(mp[it]>0){
                str+=it;
                mp[it]--;
            }
            mp.erase(it);
        }
        for(auto it:mp){
            int i=0;
            while(i<it.second){
                str+=it.first;
                i++;
            }
        }
        return str;
    }
};
