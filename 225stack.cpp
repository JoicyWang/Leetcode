#include <stdint.h>
#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while (q2.size() > 0) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Get the top element.
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int t = q1.front();
        q2.push(t);
        q1.pop();
        while (q2.size() > 0) {
            q1.push(q2.front());
            q2.pop();
        }
        return t;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};