/*
 * LeetCode #002 - Add Two Numbers
 * https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150
 * Difficulty: Medium
 */

#include <iostream>
#include "registry.hpp"

using namespace std;

// ==================== LEETCODE SOLUTION START ====================
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(NULL) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry{0};

        

        while (l1 || l2 || carry > 0) {

            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;

            int sum = a + b + carry;

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);

            tail = tail->next;


            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;       

        }

        return dummy.next;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p002 {
void test() {
    Solution sol;

    ListNode* node1_1 = new ListNode(2);
    ListNode* node1_2 = new ListNode(4);
    ListNode* node1_3 = new ListNode(3);

    ListNode* node2_1 = new ListNode(5);
    ListNode* node2_2 = new ListNode(6);
    ListNode* node2_3 = new ListNode(4);

    ListNode* head1 = node1_1;

    node1_1->next = node1_2;
    node1_2->next = node1_3;

    ListNode* head2 = node2_1;

    node2_1->next = node2_2;
    node2_2->next = node2_3;

    cout << "\nTest 1:\n";

    auto res = sol.addTwoNumbers(head1,head2);
    ListNode* curr1 = res;

    while (curr1 != nullptr) {
        cout << curr1->val;
        if (curr1->next)
            cout << ",";
        curr1 = curr1->next;
    }
    cout << endl;


    cout << "\n(expected: [7,0,8])\n";

    cout << "\n============================================\n";


}
REGISTER_PROBLEM(2, "Add Two Numbers")
}
