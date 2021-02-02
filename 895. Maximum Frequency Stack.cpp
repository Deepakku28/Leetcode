class FreqStack {
public:
    unordered_map<int,int> mp;
    map<int,vector<int>> freq;
    FreqStack() {
        mp.clear();
        freq.clear();
    }
    
    void push(int x) {
        mp[x]++;
        freq[mp[x]].push_back(x);
    }
    
    int pop() {
        auto it=freq.rbegin();
        int val1=it->first;
        int val2=it->second.back();
        freq[val1].pop_back();
        if(freq[val1].empty()){
            freq.erase(val1);
        }
        mp[val2]--;
        return val2;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
