/*
 * LeetCode #210 - Course Schedule II
 * https://leetcode.com/problems/course-schedule-ii/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <stack>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);
        stack<int> order;

        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(i, graph, visited, order)) {
                    return {};
                }
            }
        }

        vector<int> result;
        while (!order.empty()) {
            result.push_back(order.top());
            order.pop();
        }

        return result;
    }

private:
    bool hasCycle(int course, vector<vector<int>>& graph, 
                  vector<int>& visited, stack<int>& order) {
        if (visited[course] == 1) return true;
        if (visited[course] == 2) return false;

        visited[course] = 1;

        for (int next : graph[course]) {
            if (hasCycle(next, graph, visited, order)) {
                return true;
            }
        }

        visited[course] = 2;
        order.push(course);
        return false;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p210 {
void test() {
    Solution sol;
    
    vector<vector<int>> prereqs1 = {{1, 0}};
    auto res1 = sol.findOrder(2, prereqs1);
    cout << "Test 1: [";
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i];
        if (i < res1.size() - 1) cout << ", ";
    }
    cout << "] (expected: [0, 1])" << endl;
}
REGISTER_PROBLEM(210, "Course Schedule II")
}
