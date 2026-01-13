/*
 * LeetCode #207 - Course Schedule
 * https://leetcode.com/problems/course-schedule/
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);

        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(i, graph, visited)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool hasCycle(int course, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[course] == 1) return true;
        if (visited[course] == 2) return false;

        visited[course] = 1;

        for (int next : graph[course]) {
            if (hasCycle(next, graph, visited)) {
                return true;
            }
        }

        visited[course] = 2;
        return false;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p207 {
void test() {
    Solution sol;
    
    vector<vector<int>> prereqs1 = {{1, 0}};
    cout << "Test 1: " << boolalpha << sol.canFinish(2, prereqs1) << " (expected: true)" << endl;
    
    vector<vector<int>> prereqs2 = {{1, 0}, {0, 1}};
    cout << "Test 2: " << boolalpha << sol.canFinish(2, prereqs2) << " (expected: false)" << endl;
}
REGISTER_PROBLEM(207, "Course Schedule")
}
