// Tortoise Hare example but you get the point
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       /**
        if you want to create a Node then
        ListNode **node=&ans;
        ListNode *node = new ListNode(val);
        node=&((*node)->next);
       */
        if (head == nullptr) return false;
        ListNode *tortoise = head;
        ListNode *hare = head;
        while (tortoise->next && hare->next && hare->next->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) return true;
        }
        return false;
        // if you want to create new nodes
        // for 20->30->10
        // Node == ListNode
        Node *head = new Node(20);
        head->next = new Node(30);
        head->next->next = new Node(10);
    }
};
