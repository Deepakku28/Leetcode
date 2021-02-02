class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> mp;
    AllOne() {
        mp.clear();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        mp[key]++;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it=mp.find(key);
        if(it==mp.end()){
            return;
        }
        if(it->second==1){
            mp.erase(key);
        }
        else{
            mp[key]--;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(mp.empty()){
            return "";
        }
        int ans=0;
        string str="";
        for(auto it:mp){
            if(it.second>ans){
                str=it.first;
                ans=it.second;
            }
        }
        return str;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(mp.empty()){
            return "";
        }
        int ans=INT_MAX;
        string str="";
        for(auto it:mp){
            if(it.second<ans){
                str=it.first;
                ans=it.second;
            }
        }
        return str;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
