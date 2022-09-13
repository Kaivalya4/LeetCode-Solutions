class MinStack {
public:
    stack<int> stk;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.size() == 0){
            stk.push(val);
            mins.push(val);
        } else {
            if(val<=mins.top()){
                mins.push(val);
            }
            stk.push(val);
        }
    }
    
    void pop() {
        int val = stk.top();
        if(val == mins.top())
            mins.pop();
        stk.pop();
        return ;
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */