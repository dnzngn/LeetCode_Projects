/*
 * LeetCode #092 - Reverse Linked List
 * https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        // 1. left'ten bir ÖNCEKİ düğüme yürü
        ListNode* before = &dummy;
        for (int i = 1; i < left; ++i)
            before = before->next;

        // 2. Segmenti ters çevir — LC206'nın aynısı, sabit sayıda dönüyor
        ListNode* prev = nullptr;
        ListNode* curr = before->next;     // segmentin ilk düğümü
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. İki dikiş
        before->next->next = curr;         // eski segment başı → right'tan sonrası
        before->next = prev;               // left'ten önceki → yeni segment başı

        return dummy.next;
    }
};
// ==================== LEETCODE SOLUTION END ====================

namespace p092 {
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

    int left_1 = 2, right_1 = 4;

    cout << "\nTest 1:\n";

    auto res1 = sol.reverseBetween(head1,left_1,right_1);

    while (res1 != nullptr) {
        cout << res1->val;
        if (res1->next)
            cout << ",";
        res1 = res1->next;
    }
    cout << endl;


    cout << "\n(expected: [1,4,3,2,5])\n";

    cout << "\n============================================\n";


}
REGISTER_PROBLEM(92, "Reverse Linked List")
}
