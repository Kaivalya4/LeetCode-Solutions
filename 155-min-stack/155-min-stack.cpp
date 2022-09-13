class MinStack {
public:
    stack<long long> stk;
    long long minele ;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(val);
            minele = val;
        } else{
            if(val<minele){
                stk.push(2ll*(long long)val -minele);
                minele = val;
            } else
                stk.push(val);
        }
    }
    
    void pop() {
        if( stk.top() <minele){
            long long val = stk.top();
            minele = 2ll*minele - val;
        }
        stk.pop();
    }
    
    int top() {
        if(stk.top() < minele){
            return minele;
        }
        return stk.top();
    }
    
    int getMin() {
        return minele;
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