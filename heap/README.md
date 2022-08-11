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

### Extract Min

- getMin: returns min value (doesn't modify array)
- get top value, put last value in first value, call heapify
- ![image](https://i.ibb.co/z4d9hW1/image-2022-08-01-155108535.png)

```
int arr[];
int size, capacity;
int extractMin() {
    if (size == 0) return INT_MAX;
    if (size == 1) {
        size--;
        return arr[0];
    }
    swap(arr[0], arr[size-1]);
    size--;
    minHeapify(0);
    return arr[size];
}
```

- Time Complexity: O(h) = O(logn)

### Decrease key

- take heap, index, newValue as a input and update the value at specified index
- note that heap must be modified in order to compensate the new value.
- ![image](https://i.ibb.co/1Grhq5H/image-2022-08-10-131150658.png)
- Idea: compare newValue to it's parent and swap if necessary, do this until parent is smaller or root is reached.

```
int arr[];
int size, capacity;
void decreasing(int i, int x) {
    arr[i] = x;
    while (i != 0 && arr[parent(i)] > arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}
```

### Delete

- given a heap and index, remove it from heap such that what remains is still a heap
- ![image](https://i.ibb.co/KyxWvXM/image-2022-08-11-152417573.png)
- Idea: call DecreaseKey [set value at -inf at given index] and then extractMin
- ![image](https://i.ibb.co/0nsWZyr/image-2022-08-11-152744850.png)
- Time Complexity: O(logn)

### Build Heap

- [Reference](https://www.youtube.com/watch?v=fUER3PZEjxU&list=PL0SWhLkCGuU8HuzHD3zglK5Mf4fawIVjV&index=10)
- given a random array, rearrange it's elements to form a min heap
- ![image](https://i.ibb.co/9gfsQGM/image-2022-08-11-153139530.png)
- Idea: begin with bottom-most, right-most internal node call minHeapify and decrement i, we are going bottom up because for minHeapify there is assumption that for index i to call minHeapify, it's left and right should already be heapified.

```
void buildHeap() {
    // parent(i) = (i-1)/2;
    // and last internal node will be parent of last node
    for (int i = (size-2)/2; i >= 0; i--) {
        minHeapify(i);
    }
}
```

- Time complexity: O(n) [this has some mathematically proof]

## HeapSort

- it is like selection sort, in selection sort we find max element swap it in last
- Step 1: Build a Max Heap
- Time Complexity: O(n)

```
void maxHeapify(int arr[], int n, int i) {
    int largest = i, left = 2*i+1, right = 2*i+2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest == i) return;
    swap(arr[largest], arr[i]);
    maxHeapify(arr, n, largest);
}
void buildHeap(int arr, int n) {
    for(int i = (n-2)/2; i >= 0; i--)
        maxHeapify(arr, n, i);
}
```

- Step 2: Repeatedly swap root with last node, reduce heap size by one heapify

```
void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n-1; i >= 1; i--) {
        swap(arr[i], arr[0]);
        maxHeapify(arr, i, 0); // reducing size by passing i
    }
}
```

- ![image](https://i.ibb.co/Qc6C6CW/image-2022-08-11-161431380.png)
- heap sort can be seen as improvement of selection sort.
- time complexity of heap sort is nlogn however constants hidden in it take more time than merge sort or quick sort
- introSort is a hybrid algorithm that uses quick sort and heap sort, quicksort may go beyond nlogn and that's when it switches to heap sort. It is part of standard c++ library.
- therefore heapsort is not used as standalone algo but as a part of hybrid algo in standard libraries.

## Priority Queue

- ![image](https://i.ibb.co/kDb3tWh/image-2022-08-11-163549302.png)
- however priority queue does not support decreaseKey, but we don't need it much

## Sort a K-sorted array

- given a array arr, and a number k, the array is such that an element will be present between the index i-k to i+k in the sorted array.
- sort this array

```
void sortK(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int = 0; i <= k; i++) pq.push(arr[i]);
    int j = 0;
    for (int i = k+1; i < n; i++) {
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty()) {
        arr[j++] = pq.top();
        pq.pop();
    }
}
```

- Time Complexity: O(n + k\*log(k))
- ![image](https://i.ibb.co/1GFzBpB/image-2022-08-11-173923454.png)

## Purchasing Max Items
