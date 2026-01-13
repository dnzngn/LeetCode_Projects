/*
 * LeetCode #399 - Evaluate Division
 * https://leetcode.com/problems/evaluate-division/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> graph;
        
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0], B = equations[i][1];
            double value = values[i];

            graph[A].emplace_back(B, value);
            graph[B].emplace_back(A, 1.0 / value);
        }

        vector<double> result;
        for (auto& query : queries) {
            unordered_map<string, bool> visited;
            result.push_back(dfs(query[0], query[1], graph, visited));
        }

        return result;
    }

private:
    double dfs(const string& start, const string& end,
               unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_map<string, bool>& visited) {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) 
            return -1.0;
        if (start == end) 
            return 1.0;

        visited[start] = true;
        
        for (auto& [next, weight] : graph[start]) {
            if (!visited[next]) {
                double result = dfs(next, end, graph, visited);
                if (result != -1.0) {
                    return result * weight;
                }
            }
        }
        
        return -1.0;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p399 {
void test() {
    Solution sol;
    
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}};
    
    auto result = sol.calcEquation(equations, values, queries);
    
    cout << "Test 1: ";
    for (double r : result) cout << r << " ";
    cout << "(expected: 6.0 0.5 -1.0)" << endl;
}
REGISTER_PROBLEM(399, "Evaluate Division")
}
