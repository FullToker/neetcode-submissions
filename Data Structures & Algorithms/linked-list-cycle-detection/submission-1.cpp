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
    bool hasCycle(ListNode* head) { /*
         unordered_set<ListNode*> table;
         ListNode* curr = head;
         while (curr != nullptr) {
             if (table.count(curr)) return true;
             table.insert(curr);
             curr = curr->next;
         }
         return false;*/
                                    // 刚快的写法
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // 慢指针一次走1步
            fast = fast->next->next;  // 快指针一次走2步

            if (slow == fast) return true;  // 两个指针相遇,说明有环
        }

        return false;
    }
};
