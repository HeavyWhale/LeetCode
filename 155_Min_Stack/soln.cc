#include "../utils.h"

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minV = val;
        if (!s.empty()) minV = min(s.top().second, minV);
        s.push({val, minV});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }

private:
    stack<pair<int, int>> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
