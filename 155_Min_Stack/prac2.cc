#include "../utils.h"

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal = val;
        if (!data.empty()) minVal = min(val, data.top().second);
        data.emplace(pair<int, int> {val, minVal});
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        return data.top().first;
    }
    
    int getMin() {
        return data.top().second;
    }

private:
    stack<pair<int, int>> data;
};
