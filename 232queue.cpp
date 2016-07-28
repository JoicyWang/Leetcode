#include <stdint.h>
#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    stack<int> in;
    stack<int> out;
    // Push element x to the back of queue.
    void push(int x) {
        in.push(x);
    }

    void move() {
        while (!in.empty()) {
            int x = in.top();
            in.pop();
            out.push(x);
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (out.empty())
            move();
        if (!out.empty())
            out.pop();
    }

    // Get the front element.
    int peek(void) {
        if (out.empty())
            move();
        return out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in.empty() && out.empty();
    }
};