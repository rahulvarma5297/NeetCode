#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> stk;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mini = min(mini, val);
        stk.push({val, mini});
    }
    
    void pop() {
        stk.pop();
        if(stk.empty()){
            mini = INT_MAX;
            return;
        }
        mini = stk.top().second;
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */