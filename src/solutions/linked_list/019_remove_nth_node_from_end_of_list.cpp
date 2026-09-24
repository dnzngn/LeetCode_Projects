/*
 * LeetCode #019 - Remove Nth Node From End of List
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Medium
 */

#include <iostream>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // dummy on the stack: gives head a predecessor, no heap allocation
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // open a constant gap of n+1 between fast and slow
        for (int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }

        // lockstep: the gap is invariant, so when fast hits null,
        // slow sits exactly on the predecessor of the target
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* target = slow->next;
        slow->next = target->next;   // the only link that changes
        delete target;

        return dummy.next;           // not `head` — head may have been the target
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p019 {
void test() {
    Solution sol;

    ListNode* node1_1 = new ListNode(1);
    ListNode* node1_2 = new ListNode(2);
    ListNode* node1_3 = new ListNode(3);
    ListNode* node1_4 = new ListNode(4);
    ListNode* node1_5 = new ListNode(5);

    ListNode* head1 = node1_1;

    node1_1->next = node1_2;
    node1_2->next = node1_3;
    node1_3->next = node1_4;
    node1_4->next = node1_5;

    int n1 = 2;

    auto curr1 = sol.removeNthFromEnd(head1,n1);

    while (curr1 != nullptr) {
        cout << curr1->val;
        if (curr1->next)
            cout << ",";
        curr1 = curr1->next;
    }
    cout << endl;


    cout << "\n(expected: [1,2,3,5])\n";

    cout << "\n============================================\n";

    ListNode* node2_1 = new ListNode(1);

    ListNode* head2 = node2_1;


    int n2 = 1;

    auto curr2 = sol.removeNthFromEnd(head2,n2);

    while (curr2 != nullptr) {
        cout << curr2->val;
        if (curr2->next)
            cout << ",";
        curr2 = curr2->next;
    }
    cout << endl;


    cout << "\n(expected: [])\n";

    cout << "\n============================================\n";


}
REGISTER_PROBLEM(19, "Remove Nth Node From End of List")
}
