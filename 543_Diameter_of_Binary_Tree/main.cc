#include "soln.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {},
        exp2 {},
        exp3 {};
    int
        h1   {},
        h2   {},
        h3   {};

    TreeNode t1, t2, t3, t4, t5;
    t1.left = &t2;
    t2.left = &t4;
    t2.right = &t5;
    t1.right = &t3;

    Solution so;
    cout << repr(so.diameterOfBinaryTree(&t1)) << '\n';     // 3
}
