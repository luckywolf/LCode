/*
https://oj.leetcode.com/problems/min-stack/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        if (x <= getMin()) {
            min.push(x);
        }
        val.push(x);   
    }

    void pop() {
        if (min.top() == val.top()) {
            min.pop();
        }
        val.pop(); 
    }

    int top() {
        return val.top();
    }

    int getMin() {
        if (min.empty()) {
            return INT_MAX;
        } else {
            return min.top();
        }
    }

private:
    stack<int> min, val;    
};