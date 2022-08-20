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

## ![image](https://i.ibb.co/23SK7vx/image-2022-08-01-100532154.png)

## Operations on Heap

### Heapify

- given a binary tree with one possible violation, for the heap

## ![image](https://i.ibb.co/mbNqYS9/image-2022-08-01-152506425.png)

- at every node:
- take min. of parent and it's two child if it not equals to parent
- then swap parent and min. child and recursively call heapify for that child

## ![image](https://i.ibb.co/P12WnJj/image-2022-08-01-152920821.png)

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

## ![image](https://i.ibb.co/z4d9hW1/image-2022-08-01-155108535.png)

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

## ![image](https://i.ibb.co/1Grhq5H/image-2022-08-10-131150658.png)

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

## ![image](https://i.ibb.co/KyxWvXM/image-2022-08-11-152417573.png)

- Idea: call DecreaseKey [set value at -inf at given index] and then extractMin

## ![image](https://i.ibb.co/0nsWZyr/image-2022-08-11-152744850.png)

- Time Complexity: O(logn)

### Build Heap

- [Reference](https://www.youtube.com/watch?v=fUER3PZEjxU&list=PL0SWhLkCGuU8HuzHD3zglK5Mf4fawIVjV&index=10)
- given a random array, rearrange it's elements to form a min heap

## ![image](https://i.ibb.co/9gfsQGM/image-2022-08-11-153139530.png)

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

## ![image](https://i.ibb.co/Qc6C6CW/image-2022-08-11-161431380.png)

- heap sort can be seen as improvement of selection sort.
- time complexity of heap sort is nlogn however constants hidden in it take more time than merge sort or quick sort
- introSort is a hybrid algorithm that uses quick sort and heap sort, quicksort may go beyond nlogn and that's when it switches to heap sort. It is part of standard c++ library.
- therefore heapsort is not used as standalone algo but as a part of hybrid algo in standard libraries.

## Priority Queue

## ![image](https://i.ibb.co/kDb3tWh/image-2022-08-11-163549302.png)

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

## ![image](https://i.ibb.co/1GFzBpB/image-2022-08-11-173923454.png)

## Purchasing Max Items

- given a array and sum output max number of int such that their sum is less that given sum

## ![image](https://i.ibb.co/W5dLK1S/image-2022-08-11-174232387.png)

- Idea: instead of sorting use heap
- Time Complexity: making heap + popping elements = O(n) + O(res+logn)

## Print K-Largest Elements

## ![image](https://i.ibb.co/b3j28fc/image-2022-08-11-183545913.png)

- method 1: use maxHeap Time Complexity: O(n) + O(k\*logn)
- method 2: use minHeap- store first k elements in min heap, start traversing from k+1 elem in array then if (cur < pq.top()) replaceTopFromCur

```
class Solution {
public:
    int findKthLargest(vector<int>& num, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++) pq.push(num[i]);
        for (int i = k; i < num.size(); i++) {
            if (pq.top() < num[i]) {
                pq.pop();
                pq.push(num[i]);
            }
        }
        return pq.top();
    }
};
```

- Time complexity: O(k + (n-k)\*log(k))
- for n >> k, Time complexity: ~ O(n)

## K Closet Elements

- given a array arr, an integer x, and an integer k
- return k closest integers to x present in arr.
- treat this question as k-smallest elements, in which each element is abs(arr[i]-x), thereby giving us closest elements to x.

```
class Solution {
public:
    int findKClosetElements(vector<int>& num, int k) {
        priority_queue<pair<int, int>,
        vector<pair<int, int>>, smaller<int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push(abs(num[i]-x), i);
        }
        for (int i = k; i < num.size(); i++) {
            int diff = abs(arr[i], x);
            if (pq.top().first > diff) {
                pq.pop();
                pq.push(diff, i);
            }
        }
        return pq.top();
    }
};
```

## Merge K sorted arrays

- do as the question demands
- to merge 2 sorted array we compare first element of both array, so for k-sorted arrays we will use heap for comparison of first element of each array

```
struct getIn{
    int val;
    int arrPos;
    int pos;
    getIn(int v, int a, int p) {
        this.val = v; this.arrPos = a; this.pos = p;
    }
}

static bool myCmp(getIn& g1, getIn& g2) {
    return g1.val >= g2.val;
}

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    int k = arrays.size();
    priority_queue<getIn, vector<getIn>, myCmp> pq;
    vector<int> res;
    for (int i = 0; i < k; i++) pq.push(getIn(arr[0], i, 0));
    while (!pq.empty()) {
        getIn g = pq.top();pq.pop();
        res.push_back(g.val);
        if (g.pos < arrays[g.arrPos].size()) {
            ++g.pos;
            pq.push(getIn(arr[g.arrPos][g.pos], g.arrPos, g.pos));
        }
    }
    return res;
}
```

## ![image](https://i.ibb.co/WHZVJxb/image-2022-08-14-174542410.png)

- Time Complexity: O(n*k*(log(k)))

## Median of Stream

- popular interview question
- Median of a array:(1) n is odd- a number which is smaller than half of elements and larger than half, (2) when n is even- then there will be 2 such elements, then median will be average of both numbers
- output a array denoting median prefixes

### Naive Implementation

- it is to maintain a sorted array and add elements to it linearly.
- insertion in that would take O(n)
- so Time Complexity: O(n^2)

### use binary search tree

- Time complexity: [Avg] O(nlogn)

### Heap

- maintain 2 containers for 1st half and 2nd half of elements
- if current n is even 2 containers would have equal elements, n is odd then 1st container would have 1 extra element
- 1st container would be maxHeap, 2nd container would be minHeap
- Time Complexity: O(nlogn), heap is cache friendly too.

```
vector<float> getMedian(vector<int>& arr) {
    vector<float> res;
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> g;
    priority_queue<int> s;
    s.push(arr[0]);
    res.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        int x = arr[i];
        if (s.size() > g.size()) {
            if (s.top() > x) {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else g.push(x);
            res.push_back((s.top()+g.top())/2);
        }
        else {
            if (x <= s.top()) s.push(x);
            else {g.push(x); s.push(g.top()); g.pop();}
            res.push_back(s.top());
        }
    }
    return res;
}
```

