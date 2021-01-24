class LRUCache {
    int len;
    deque<int> dq;
    unordered_map<int,int> mp;
public:
    LRUCache(int capacity) {
        mp.clear();
        dq.clear();
        len=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        deque<int> :: iterator it=dq.begin();
        while(*it!=key){
            it++;
        }
        dq.erase(it);
        dq.push_front(key);
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(dq.size()==len){
                int last=dq.back();
                dq.pop_back();
                mp.erase(last);
            }
        }
        else{
            deque<int> :: iterator it=dq.begin();
            while(*it!=key){
                it++;
            }
            dq.erase(it);
            mp.erase(key);
        }
        dq.push_front(key);
        mp[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
