/*
 * LeetCode #21 - Merge Two Sorted List
 * https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Easy
 */

#include <iostream>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }
    
};
// ==================== LEETCODE SOLUTION END ====================

namespace p21 {
void test() {
    Solution sol;

    ListNode* node1_1 = new ListNode(1);
    ListNode* node1_2 = new ListNode(2);
    ListNode* node1_3 = new ListNode(4);

    ListNode* node2_1 = new ListNode(1);
    ListNode* node2_2 = new ListNode(3);
    ListNode* node2_3 = new ListNode(4);

    ListNode* head1 = node1_1;

    node1_1->next = node1_2;
    node1_2->next = node1_3;

    ListNode* head2 = node2_1;

    node2_1->next = node2_2;
    node2_2->next = node2_3;

    cout << "\nTest 1:\n";

    auto res = sol.mergeTwoLists(head1,head2);
    ListNode* curr = res;

    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next)
            cout << ",";
        curr = curr->next;
    }
    cout << endl;


    cout << "\n(expected: [1,1,2,3,4,4])\n";

    
    /* cout << "\n============================================\n";

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

    cout << "\n============================================\n"; */


}

REGISTER_PROBLEM(21, "Merge Two Sorted List")
}
