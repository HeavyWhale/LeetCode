#include "../utils.h"

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        int minVal = val;
        if (!st.empty()) minVal = min(st.top().second, val);
        st.emplace(val, minVal);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
