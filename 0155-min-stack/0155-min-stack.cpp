class MinStack {
public:
stack<int> st;
stack<int> minst;
int mini = INT_MAX;
    MinStack() {
        
    }
    void push(int value) {
        if(minst.empty()) mini = INT_MAX;
        mini = min (value , mini);
        st.push(value);
        minst.push(mini);
    }
    
    void pop() {
        st.pop();
        minst.pop();
        if(!minst.empty()) mini = minst.top();
        else mini = INT_MAX;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */