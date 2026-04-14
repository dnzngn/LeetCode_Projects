/*
 * LeetCode #141 - Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle/
 * Difficulty: Easy
 */

#include <iostream>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;          // 1 adım
            fast = fast->next->next;    // 2 adım

            if (slow == fast) {
                return true; // cycle var
            }
        }

        return false; // cycle yok
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p141 {
void test() {
    Solution sol;

    ListNode* node1_1 = new ListNode(3);
    ListNode* node1_2 = new ListNode(2);
    ListNode* node1_3 = new ListNode(0);
    ListNode* node1_4 = new ListNode(-4);

    ListNode* head1 = node1_1;

    node1_1->next = node1_2;
    node1_2->next = node1_3;
    node1_3->next = node1_4;
    node1_4->next = node1_2;

    cout << "\nTest 1: " << sol.hasCycle(head1) << " (expected: 1)\n";

    cout << "\n============================================\n";

    ListNode* node2_1 = new ListNode(1);
    ListNode* node2_2 = new ListNode(2);

    ListNode* head2 = node2_1;

    node2_1->next = node2_2;
    node2_2->next = node2_1;

    cout << "\nTest 2: " << sol.hasCycle(head2) << " (expected: 1)\n";

    cout << "\n============================================\n";

    ListNode* node3_1 = new ListNode(3);

    ListNode* head3 = node3_1;

    cout << "\nTest 3: " << sol.hasCycle(head3) << " (expected: 0)\n";

    cout << "\n============================================\n";

    ListNode* node4_1 = new ListNode(1);
    ListNode* node4_2 = new ListNode(2);

    ListNode* head4 = node4_1;

    node4_1->next = node4_2;

    cout << "\nTest 4: " << sol.hasCycle(head4) << " (expected: 0)\n";

    cout << "\n============================================\n";


}
REGISTER_PROBLEM(141, "Linked List Cycle")
}
