### Problems with an array
- size is fixed or preallocated or worst case insertion at the end is o(n)
- insertion or deletion on the beginning is costly

## Cpp Node Implemention
- ListNode is a self-reference data structure
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
- In Java memory is automatically deallocated, in Cpp we have to handle it
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
- deletion of any given node in O(1) time
- insertion of at any node is in O(1) time
### Disadvantages
- extra memory is needed
- code is complex

## Circular Linked List
### Advantages
- can traverse the whole list from any node
- Round Robin Algorithm implementation
### Disadvantages
- implementation of operations becomes complex

## Find Middle/nth position of the end of linked List1
- use 2 pointers instead of counting the entire LL and then traversing
- for middle make Speed<sub>fast pointer</sub> = 2xSpeed<sub>slow pointer</sub>
- when fast reaches end slowly will reach middle
- for nth pos from last place fast pointer n pos's ahead of slow and move at the same speed

## Detect Loop in LL
### Method 1
- make a dummy node
- start traversing given LL and point every node in it to the made dummy node
- if you find a node in given LL already pointing towards the dummy node then the loop is present
- O(1) space, O(n) speed but given LL is modified
### Method 2
- use hashmap
- uses O(n) space
- given LL is not modified

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

### Tortoise Hare Example (Floyd Algorithm)
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
## Clone LL with random pointer
- [Reference Video](https://www.youtube.com/watch?v=8XgCpA7OjQA&list=PL0SWhLkCGuU-7wyb8jswrv0MoKN0qXM8X&index=47)
### Method 1
- use hashmap to store addresses for corresponding nodes
- Time: O(n), Space: O(n)
### Method 2
- Step 1: create a copy node for every node and place it in between of the original nodes
- Step 2: traverse through LL and assign random to every clone node though given original nodes
- Step 3: traverse though LL assign next for every clone node and restore original LL
- Time: O(n), Space: O(1)
## ![msg960201314-2602](https://user-images.githubusercontent.com/69719072/158005025-dadf7fa7-b829-4339-bc8f-aeae3f441f64.jpg)

```
Original: [1]->[2]->[3]
Step 1: [1]->[1c]->[2]->[2c]->[3]->[3c]
```

### Detect and remove cycle from LL
- detect cycle by floyd's algorithm
- move "slow p" to the beginning of LL and keep "fast p" at the meeting point
- now one by one move slow and fast (at same speed), the point where they meet now is the first node of the loop
```
slow = head;
while (slow->next != fast->next) {
  slow = slow->next;
  fast = fast->next;
}
fast->next = NULL; // removing cycle
```
### Check if given LL is Palindrome or not
- [Reference Video](https://www.youtube.com/watch?v=yowT3YWOxEI&list=PL0SWhLkCGuU-7wyb8jswrv0MoKN0qXM8X&index=48)
- find middle of the LL
- reverse remaining LL starting from middle
- compare every element from starting to start from middle 
