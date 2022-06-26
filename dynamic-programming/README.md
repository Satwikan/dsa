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
- i.e; for each sub-problem, we should already have the solution for it's previous sub-problem unlike Memoization.
- we will have array of dimensions that is equal to number of variables changing

```
int fib(int n) {
    int store[n+1] = {0, 0, ..., 0};
    store[0] = 0; store[1] = 1;
    for (int i = 2; i <= n; i++)
        store[i] = store[i-1] + store[i-2];
    return store[n];
}
```

- please note that DP is not the most efficient approach to solve fibonacci problem, it can be done in O(log n) time.

## memoization vs tabulation

- memoization is easy to implement, whereas tabulation does not require recursion call overhead.
- so typically tabulation are faster.

## Longest Common Subsequence

- ![image](https://i.ibb.co/xFw7SqJ/image-2022-06-23-163007978.png)

### recursive solution without memoization

```
int lcs(string s1, string s2, int m, int n) {
    if (m == 0 || n == 0) return 0;
    if (s1[m-1] == s2[n-1])
        return 1 + lcs(s1, s2, m-1, n-1);
    return max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
}
```

- ![image](https://i.ibb.co/xFw7SqJ/image-2022-06-23-163007978.png)
- we can see here that some functions calls are repeated, so we can use memoization to reduce the number of calls.

### recursive solution with memoization

- we will use array of dimensions 2 because we have 2 variables changing

```
int memo[m+1][n+1] = {-1, -1, ..., -1};
int lcs(string s1, string s2, int m, int n) {
    if (memo[m][n] != -1) return memo[m][n];
    if (m == 0 || n == 0) return 0;
    if (s1[m-1] == s2[n-1])
        memo[m][n] = 1 + lcs(s1, s2, m-1, n-1);
    memo[m][n] = max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));
    return memo[m][n];
}
```

- leet-code
- 1 <= text1.length, text2.length <= 1000
- text1 and text2 consist of only lowercase English characters.

```
class Solution {
public:
    int lcs(string& text1, string& text2, int i, int j, int memo[][1001]) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (text1[i] == text2[j]) memo[i][j] =  1 + lcs(text1, text2, i+1, j+1, memo);
        else memo[i][j] =  max(lcs(text1, text2, i+1, j, memo), lcs(text1, text2, i, j+1, memo));
        return memo[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int memo[1001][1001];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                memo[i][j] = -1;

        int res = lcs(text1, text2, 0, 0, memo);
        return res < 0 ? 0 : res;
    }
};
```

- Tabulation
- ![image](https://i.ibb.co/gjxTJ1q/image-2022-06-23-173446983.png)

```
int lcs(string s1, string s2) {
    int store[s1.size()+1][s2.size()+1];
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0 || j == 0) store[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                store[i][j] = store[i-1][j-1] + 1;
            else
                store[i][j] = max(store[i-1][j], store[i][j-1]);
        }
    }
    return store[s1.size()][s2.size()];
}
```

- Time Complexity: O(m\*n)

### Variations of LCS

- Diff Utility
- Min insertion/deletion to make two strings equal
- Shortest Common Super-sequence
- Longest Palindromic Subsequence
- Longest Repeated Subsequence
- Space Optimized DP solution of LCS
- Print Longest Common Subsequence

## Coin Change (Count Combinations)

- ![image](https://i.ibb.co/hXb1NH5/image-2022-06-25-140507339.png)

### recursive solution

```
void getCount(int coins[], int n, int sum, int& count) {
    if (n == 0) {
        if (sum == 0) count++;
        return;
    }
    getCount(coins, n-1, sum, count);
    if (sum - coins[n-1] >= 0)
        getCount(coins, n, sum - coins[n-1] count);
}
```

### tabulation

```
int getCount(int coins[], int n, int sum) {
    int store[sum+1];
    for (int i = 0; i <= sum; i++)
        store[i] = 0;
    store[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = coins[i-1]; j <= sum; j++)
            store[j] += store[j-coins[i-1]];
    }
    return store[sum];
}
```

## Edit Distance

- calculate min total number of steps required to make two strings equal
- we use insertion, deletion, replace as a step
- ![image](https://i.ibb.co/T00y4zj/image-2022-06-25-141034300.png)

### recursive solution

```
int editDistance(string s1, string s2, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;
    if (s1[m-1] = s2[n-1]) return editDistance(s1, s2, m-1, n-1);
    return 1 + min(editDistance(s1, s2, m-1, n-1),
        editDistance(s1, s2, m, n-1),
        editDistance(s1, s2, m-1, n))
}
```

### tabulation

- ![image](https://i.ibb.co/P4kqKRf/image-2022-06-25-144518362.png)

```
int editDistance(string s1, string s2, int m, int n) {
    int store[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) store[i][j] = j;
            else if (j == 0) store[i][j] = i;
            else if (s1[i-1] == s2[j-1]) store[i][j] = store[i-1][j-1];
            else store[i][j] = 1 + min(store[i-1][j], store[i][j-1], store[i-1][j-1]);
        }
    }
    return store[m][n];
}
```
### application
- spelling correction
- dictionary search suggestion

## Longest Increasing Subsequence
- ![image](https://i.ibb.co/bvdqJ5B/image-2022-06-25-184057308.png)

### solution
- we won't generate all sub-sequences because that won't have overlapping sub-problems instead we will generate lis
- calculate lis at every index
- and then take max of each lis
- ![image](https://i.ibb.co/Y2XhsPw/image-2022-06-26-112550571.png)
```
int lis (int arr[], int n) {
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int i = 1; i < n; i++) {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    int mx = lis[0];
    for(int i = 0; i < n; i++) {
        mx = max(mx, lis[i]);
    }
    return mx;
}
```
- Time Complexity: O(n2)
- Space Complexity: O(n)
- not a best solution though, best solution is has binary search with O(nlogn)