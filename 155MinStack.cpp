#include <stdint.h>
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        st.push(x);
        if (min.empty() || x <= min.top())
            min.push(x);
    }
    
    void pop() {
        int t = st.top();
        st.pop();
        if (t == min.top())
            min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};