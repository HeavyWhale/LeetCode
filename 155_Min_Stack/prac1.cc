#include "../utils.h"

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            s.emplace(pair<int, int> {val, val});
            return;
        }
        s.emplace(pair<int, int> {val, min(val, s.top().second)});
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
