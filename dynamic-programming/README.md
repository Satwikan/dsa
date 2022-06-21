# Dynamic Programming

- optimization over plain recursive, reuse the solutions of sub-problems when there are overlapping sub-problems

### Types
- Memoization [not Memorization] (Top Down)
- Tabulation (Bottom Up)
## Application
- Bellman Ford Algorithm
- Floyd Warshall Algorithm
- Diff Utility (Longest Common Subsequence) [eg. difference between two files]
- Search Closed words (Edit Distance)
- Resource Allocation (0-1 Knapsack)

## Memoization
- code with memoization for fibonacci
```
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
```
- Time Complexity: O(2<sup>n</sup>)
```
int store[n+1] = {0, 0, ..., 0};
int fib(int n, int &store[]) {
    if (n == 0 || n == 1) return n;
    if (store[n] != 0) return store[n];
    store[n] = fib(n - 1, store) + fib(n - 2, store);
    return store[n];
}
```
- Time Complexity: O(n)