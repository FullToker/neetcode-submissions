/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> oldnew;
        Node* curr = head;
        while (curr != nullptr) {
            oldnew[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr != nullptr) {
            oldnew[curr]->next = oldnew[curr->next];
            oldnew[curr]->random = oldnew[curr->random];
            curr = curr->next;
        }
        return oldnew[head];
    }
};
