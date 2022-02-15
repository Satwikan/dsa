### Problems with array
- size is fixed or prealocated or worst case insertion at end is o(n)
- insertion or deleteion on beggenning is costly

## Cpp Node Implemention
- ListNode is a self refrence data structure
```
/**
 * Definition for singly-linked list.
 * struct Node {
 *     int val;
 *     Node *next;
 *     Node(int x) : val(x), next(NULL) {}
 * };
 */
  // if you want to create new nodes
  // for 20->30->10
  Node *head = new Node(20);
  head->next = new Node(30);
  head->next->next = new Node(10);
};
```
### Delete a node
- In Java memory is atomatically deallocated, in Cpp we have to handle it
```
Node *delNode(Node *head){
  if (head == NULL) return NULL;
  Node *temp = head->next;
  delete head;
  return temp;
}
```
- when you pass a node as an argument like
```
void printNode(Node *head) {
  ...
}
```
- then it is called by value like a regular variable thus for this code
```
// head = 10->NULL
printNode(head);
printNode(head);
```
- output will be ``` 10 10 ```

### Tortoise Hare Example
```
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
    }
};
```
