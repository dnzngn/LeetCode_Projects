/*
 * LeetCode #150 - Evaluate Reverse Polish Notation
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=study-plan-v2&envId=top-interview-150
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
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(const string& token : tokens){

            if(token == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                cout << '\n' << a << '\t' << b << '\n';
                st.push(a + b); 
            }
            else if(token == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                cout << '\n' << a << '\t' << b <<  '\n';
                st.push(a * b); 
            }
            else if(token== "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                cout << '\n' << a << '\t' << b << '\n';
                st.push(b / a); 
            }
            else if(token == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                cout << '\n' << a << '\t' << b << '\n';
                st.push(b - a); 
            } else{
                st.push(stoi(token));
                cout << st.top()<<'\t';
            }
        }

        return st.top(); 
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p150 {
void test() {

    Solution sol;
    
    vector<string> tokens1 = {"2","1","+","3","*"};

    auto ans1 = sol.evalRPN(tokens1);

    cout << "\nTest 1: " << ans1 << " (expected: 9)\n";

    cout << "\n============================================\n";
    vector<string> tokens2 = {"4","13","5","/","+"};

    auto ans2 = sol.evalRPN(tokens2);

    cout << "\nTest 2: " << ans2 << " (expected: 6)\n";

    cout << "\n============================================\n";
    vector<string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    auto ans3 = sol.evalRPN(tokens3);

    cout << "\nTest 3: " << ans3 << " (expected: 22)\n";

    cout << "\n============================================\n";
}

REGISTER_PROBLEM(150, "Evaluate Reverse Polish Notation")
}
