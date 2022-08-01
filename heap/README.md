# Heap
## Intro
### Two Types of Heap
- Min heap
- Max heap
### Binary Heap
- heap made out of complete binary tree
- the benefit of this is we can store the heap in a single array without wasting any extra space
- and every element is stored continuously, so locality of reference(locality of reference)
- and it's height is minimum possible
## Min Heap
- min heap is binary heap
- ![image](https://i.ibb.co/23SK7vx/image-2022-08-01-100532154.png)
## Operations on Heap
### Heapify
- given a binary tree with one possible violation, for the heap
- ![image](https://i.ibb.co/mbNqYS9/image-2022-08-01-152506425.png)
- at every node:
- take min. of parent and it's two child if it not equals to parent
- then swap parent and min. child and recursively call heapify for that child 
- ![image](https://i.ibb.co/P12WnJj/image-2022-08-01-152920821.png)
- the below function is assuming only root might be in violation.
```
int arr[];
int size, capacity;
void minHeapify(int i) {
    int lt = left(i), rt = right(i);
    int smallest = i;
    if (lt < size && arr[lt] < arr[i]) smallest = lt;
    if (rt < size && arr[rt] < arr[i]) smallest = rt;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(smallest);
    }
}
```
- Time Complexity: O(h) = O(logn)