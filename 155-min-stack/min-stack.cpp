class MinStack {
public:
    stack<int>st;
    stack<int>ms;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(ms.empty()){
            ms.push(val);
        }
        else{
            int mn=min(ms.top(),val);
            ms.push(mn);
        }
    }
    
    void pop() {
        st.pop();
        ms.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ms.top();
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