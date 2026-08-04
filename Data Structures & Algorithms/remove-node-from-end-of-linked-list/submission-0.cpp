/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // fast先走n步
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // fast和slow一起走,直到fast走到最后一个节点(fast->next为空)
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // 此时slow停在"要删除节点"的前一个位置
        slow->next = slow->next->next;

        return dummy.next;
    }
};
