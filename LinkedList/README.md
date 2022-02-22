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

## Double Linked List
### Advantages:
- can be traversed in both direction
- deletion of any given node in in O(1) time
- insertion of at any node is in O(1) time
### Disadvantages
- extra memory is needed
- code is complex

## Circular Linked List
### Advantages
- can traverse whole list from any node
- Round Robin Algorithm implementation
### Disadvantages
- implementation of operations becomes complex

## Find Middle/nth position of end of LInkded List1
- use 2 pointers instead of counting entire LL and then traversing
- for middle make Speed<sub>fast pointer</sub> = 2xSpeed<sub>slow pointer</sub>
- when fast reaches end slow will reach middle
- for nth pos from last place fast pointer n pos's ahead of slow and move at same speed

## Recursive reverse Linked List
### Method 1
```
// x1->[x2(rest_tail) <- x3 <- x4 <- x4 ... <- xn(rest_head)]
Node *recRevl(Node *head){
  // Base Case
  if (head == NULL || head->next == NULL) return head;
  
  Node *rest_head = recRevl(head->next);
  Node *rest_tail = head->next;
  rest_tail->next = head;
  head->next = NULL;
  return rest_head;
}
```
### Method 2 (tail recursion)
```
// [x1 <- x2 <- x3 <- x4 <- x4 ...] -> xn
Node *recRevl(Node *curr, Node *prev = NULL){
  // Base Case
  if (curr == NULL) return prev;
  
  Node* next = curr->next;
  curr->next = prev;
  return recRevl(next, curr);
}
```

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
