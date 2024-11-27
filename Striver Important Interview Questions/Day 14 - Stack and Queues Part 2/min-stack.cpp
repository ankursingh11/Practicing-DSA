
// https://leetcode.com/problems/min-stack/

class MinStack {
    stack<int> st;
    stack<int> minStack;
public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        if (val <= minStack.top()) minStack.push(val);
    }
    
    void pop() {
        if(st.empty()) return;
        int val = st.top();
        st.pop();
        if(val == minStack.top()) minStack.pop();
        return;
    }
    
    int top() {
        if(st.empty()) return 0;
        return st.top();
    }
    
    int getMin() {
        if(minStack.top() == INT_MAX) return INT_MAX;
        return minStack.top();
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