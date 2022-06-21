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

- fibonacci

```
int fib(int n) {
    if (n == 0 || n == 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

- Time Complexity: O(2<sup>n</sup>)
- fibonacci with memoization

```
int store[n+1] = {0, 0, ..., 0};
int fib(int n, int &store[]) {
    if (n == 0 || n == 1) return n;
    if (store[n] == 0)
        store[n] = fib(n - 1, store) + fib(n - 2, store);
    return store[n];
}
```

- Time Complexity: O(n)

## Tabulation

- in top down we were building our solution from n to start, but in bottom up we are building our solution from start to n.

```
int fib(int n) {
    int store[n+1] = {0, 0, ..., 0};
    store[0] = 0; store[1] = 1;
    for (int i = 2; i <= n; i++)
        store[i] = store[i-1] + store[i-2];
    return store[n];
}
```
