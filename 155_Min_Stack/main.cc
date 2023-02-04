#include "prac3.cc"

int main() {
    MinStack ms = MinStack();
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    assert(ms.getMin() == -3);
    ms.pop();
    assert(ms.top() == 0);
    assert(ms.getMin() == -2);
    cout << "Basic test passed!\n";
}
