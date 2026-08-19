/*
 * LeetCode #155 - Min Stack
 * https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

#include <stack>

#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
private:
    stack<int> st;
    stack<int> min_st;      
public:
    MinStack() {
            
    }

    void push(int value){
        st.push(value);
        min_st.push(min_st.empty() ? value : std::min(value, min_st.top()));
    }

    void pop(){
        st.pop();
        min_st.pop();
    }

    int top(){
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p155 {
void test() {

    MinStack* minStack = new MinStack();

    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);

    cout << "\nTest getMin(): " << minStack->getMin() << " (expected: -3)\n";

    cout << "\n============================================\n";
    
    minStack->pop();
        
    cout << "\nTest top(): " << minStack->top() << " (expected: 0)\n";
    cout << "\nTest getMin(): " << minStack->getMin() << " (expected: -2)\n";

    cout << "\n============================================\n";
}

REGISTER_PROBLEM(155, "Min Stack")
}
