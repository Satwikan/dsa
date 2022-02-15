### Problems with array
- size is fixed or prealocated or worst case insertion at end is o(n)
- insertion or deleteion on beggenning is costly

### [ListNode](https://github.com/Satwikan/dsa/blob/master/linked%20list/ListNode.cpp)
- ListNode is a self refrence data structure
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
