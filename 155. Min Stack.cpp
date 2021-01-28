class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> s;
    vector<int> minS;
    MinStack() {
        minS.push_back(INT_MAX);
    }
    
    void push(int x) {
        s.push_back(x);
        if(x<minS.back()){
            minS.push_back(x);
        }
        else{
            minS.push_back(minS.back());
        }
    }
    
    void pop() {
        s.pop_back();
        minS.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return minS.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
