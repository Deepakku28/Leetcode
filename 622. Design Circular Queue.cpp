class MyCircularQueue {
public:
    vector<int> a;
    int len=0;
    
    MyCircularQueue(int k) {
        len=k;
    }
    
    bool enQueue(int value) {
        if(a.size()<len){
            a.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!a.empty()){
            a.erase(a.begin());
            return true;
        }
        return false;
    }
    
    int Front() {
        return a.empty()?-1:a.front();
    }
    
    int Rear() {
        return a.empty()?-1:a.back();
    }
    
    bool isEmpty() {
        return a.empty();
    }
    
    bool isFull() {
        return a.size()==len;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
