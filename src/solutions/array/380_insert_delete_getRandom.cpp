/*
 * LeetCode #380 - Insert Delete GetRandom O(1)
 * https://leetcode.com/problems/insert-delete-getrandom-o1
 * Difficulty: Medium
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>


#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
class Solution {
public:
    unordered_set<int> randomSet;

    Solution() {
        auto sol_randomSet = randomSet;
    }
    
    bool insert(int val) {

        auto it = randomSet.find(val);

        if (it != randomSet.end()){
            cout << *it << " Element Found! Not Insert to Set!\n";
            return false;
        }  
        else
            cout << "Element not Found!\n";
            randomSet.insert(val);
        return true;

    }
    
    bool remove(int val) {
        auto it = randomSet.find(val);
        if (it != randomSet.end()){
            cout << *it << " Element Found! Erase from Set!\n";
            randomSet.erase(val);
            return true;     
        }  
        else
            cout << "Element not Found!\n";
            randomSet.erase(val);
        return false;

        randomSet.erase(val);
    }
    
    int getRandom() {
        std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<std::size_t> distribution(0, randomSet.size() - 1);

        std::size_t number = distribution(generator);

        auto it = next(randomSet.begin(), number);

        return *it;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p380 {
void test() {
    Solution sol;

    int val1 = 5;
    int val2 = 3;
    int val3 = 2;
    int val4 = 8;
    int val5 = 7;

    Solution* obj = new Solution();
    
    bool param_1 = obj->insert(val1);
    cout << "Test insert: [" << param_1 << "] (expected: True)" << endl;
    bool param_2 = obj->insert(val2);
    cout << "Test insert: [" << param_2 << "] (expected: True)" << endl;
    bool param_3 = obj->insert(val3);
    cout << "Test insert: [" << param_3 << "] (expected: True)" << endl;
    bool param_4 = obj->insert(val4);
    cout << "Test insert: [" << param_4 << "] (expected: True)" << endl;
    bool param_5 = obj->insert(val5);
    cout << "Test insert: [" << param_5 << "] (expected: True)" << endl;
    bool param_6 = obj->insert(val5);
    cout << "Test insert: [" << param_6 << "] (expected: False)" << endl;
    
    bool param_del1 = obj->remove(val1);
    cout << "Test remove: [" << param_del1 << "] (expected: True)" << endl;
    bool param_del2 = obj->remove(12);
    cout << "Test remove: [" << param_del2 << "] (expected: False)" << endl;

    int random_number = obj->getRandom();
    cout << "Test random element: [" << random_number << "] (expected: random element)" << endl;
}
REGISTER_PROBLEM(380, "Insert Delete GetRandom O(1)")
}
