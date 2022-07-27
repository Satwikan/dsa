# Dynamic Programming

- optimization over plain recursive, reuse the solutions of sub-problems when there are overlapping sub-problems

## Topics I did'nt get yet

- [Optimal Strategy](https://github.com/Satwikan/dsa/tree/master/dynamic-programming#optimal-strategy-for-a-game)

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
        for (int j = 0; j < i; j++) {
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

### Binary solution (nlogn)

- it really very awesome algo not only it generates length of lis in nlogn
- but also generates the lis subsequence

#### Algo

- take a auxiliary array of length n tail
- now tail[i] = min tail of lis of length [i+1] i = 0 to i = n-1

```
int cellIdx(int tail[], int b, int e, int x) {
    while(r > l) {
        int m = l + (r-l)/2;
        if(tail[m] >= x) r = m;
        else l = m + 1;
    }
    return r;
}
int lis(int arr[], int n) {
    int tail[n];
    tail[0] = arr[0];
    int k = 0;
    for(int i = 1; i < arr.size(); i++) {
        if (tail[k] < arr[i]) tail[++k] = arr[i];
        else {
            int c = cellIdx(tail, 0, k, arr[i]);
            tail[c] = arr[i];
        }
    }
    return k+1;
}
```

- Time Complexity: O(nlogn)

## Variations of LIS

### Minimum number of deletions to make a array sorted

```
return n - lis(arr, n);
```

### Maximum Sum of increasing subsequence

```
int lis (int arr[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++) {
        lis[i] = arr[i]; // because we want sum
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + arr[i]);
        }
    }
    int mx = lis[0];
    for(int i = 0; i < n; i++) {
        mx = max(mx, lis[i]);
    }
    return mx;
}
```

### Maximum Length of Bitonic Subsequence

- a sequence is bitonic if it is increasing and then decreasing
- both increasing and decreasing sequences are bitonic sequences
- take 2 auxiliary arrays of length n, 1 for increasing subsequence at every element and 1 for decreasing subsequence.
- sum them and and subtract 1

### Build Bridges

- given some n numbers and array of pairs arr. a pair denotes a bridge between numbers.
- calculate maximum number of bridges possible without crossing.
- ![image](https://i.ibb.co/9tmHp29/image-2022-06-27-170249054.png)
- sort them with 1st number and then apply binary LIS.

### Longest Chain of Pairs

- ![image](https://i.ibb.co/B4n7Sy8/image-2022-06-28-144411000.png)
- ![image](https://i.ibb.co/j3px1yN/image-2022-06-28-144525918.png)
- sort the array of pairs according to first values.
- find the lis of the sorted array(according to first value).
- this is activity selection problem.

## Maximum Cuts

- given a rod of length n and 3 integers a, b, c, make maximum cuts such that every cut is either of length a, b or c.
- if none is possible return -1.
- ![image](https://i.ibb.co/dLF7t9B/image-2022-06-29-142600569.png)

### Recursion

```
int maxCuts(int n, int a, int b, int c) {
    if (n <= 0) return n;
    int res = max(
        maxCuts(n-a, a, b, c),
        maxCuts(n-b , a, b, c),
        maxCuts(n-c, a, b, c));
    if (res == -1) res;
    else return res+1;
}
```

- Time Complexity:O(3^n)

### Tabulation

```
int maxCuts(int n, int a, int b, int c) {
    int memo[n+1];
    memo[0] = 0;co
    for(int i = 1; i < n+1; i++) {
        memo[i] = -1;
        if (i-a >= 0) mx = max(memo[i], memo[i-a]);
        if (i-b >= 0) mx = max(memo[i], memo[i-b]);
        if (i-c >= 0) mx = max(memo[i], memo[i-c]);
        if (memo[i] != -1) memo[i];
    }
    return memo[n];
}
```

- Time Complexity: O(n)

## Minimum Coins

- given coins array with unlimited number of coins and a val
- output minimum coins to make up that value
- ![image](https://i.ibb.co/hyLH9xk/image-2022-06-29-155459338.png)

### Recursion

```
int minCoins(int coins[], int n, int val) {
    if (val <= 0 || n == 0) return 0;
    int res = INT_MAX:
    for(int i = 0; i < n; i++) {
        if (coins[i] <= val) {
            int sub_res = getMin(coins, n, val-coins[i]);
            if (sub_res != INT_MAX)
                res = min(res, sub_res+1);
        }
    }
    return res;
}
```

### Memoization

```
int minCoins(int coins[], int n, int val) {
    int dp[val+1]:
    dp[0] = 0;
    for(int i = 1; i <= val; i++)
        dp[i] = INT_MAX;
    for(int i = 0; i <= val; i++) {
        for(int j = 0; j < n; j++) {
            if (arr[i] <= i>) {
                int sub_res = dp[i-arr[i]];
                if (sub_res != INT_MAX)
                    dp[i] = min(dp[i], sub_res+1);
            }
        }
    }
    return dp[val];
}
```

- Time Complexity: O(val\*n)
- Space: O(n)

## Minimum Jumps to Reach End

- number of jumps are decided based on current value of of index
- ![image](https://i.ibb.co/pJvGnzQ/image-2022-07-11-191828055.png)

### Recursion

```
int minJumps(int arr[], int i, int n) {
    if (n == 1) return 0;
    int res = INT_MAX;
    for (int i = 0; i <= n-2; i++) {
        if (i+arr[j] >= n) {
            int sub_res = minJumps(arr, i+1);
            if (sub_res != INT_MAX)
                mn = min(mn, sub_res+1);
        }
    }
    return res;
}
```

### Memoization

```
// Time Complexity: O(n^2)
// Space: O(n)
int minJumps(int arr[], int n) {
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
        dp[i] = INT_MAX:
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j + arr[j] >= i) {
                if (dp[j] != INT_MAX)
                dp[i] = min(dp[i], 1+dp[j]);
            }
        }
    }
    return dp[n-1];
}
```

## 0-1 Knapsack

- ![image](https://i.ibb.co/x3GJYrb/image-2022-07-11-200017374.png)
- items are finite

### Recursion

```
// Time Complexity: O(2^n)
int knapsack(int v[], int w[], int n, W) {
    if (n == 0 || W == 0) return 0;
    int res = knapsack(v, w, n-1, W);
    if (W >= w[n])
        max(res, v[n-1] + knapsack(v, w, n-1, W-w[n-1]));
    return res;
}
```

### Memoization

```
// Time Complexity: O(N*W)
// N: number of items, W: weight limit of knapsack
int knapSack(int W, int wt[], int val[], int n) {
    int memo[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) memo[i][j] = 0;
            else {
                memo[i][j] = memo[i-1][j];
                if (wt[i-1] <= j)
                    memo[i][j]=max(memo[i][j], val[i-1]+memo[i-1][j-wt])
            }
        }
    }
    return memo[n][W];
}
```

- it might perform worse than recursive solution
- it is a pseudo hard problem it is a np-hard problem

## Optimal Strategy for a game

- [Reference](https://www.youtube.com/watch?v=MTNNGbFgejE&list=PL0SWhLkCGuU-HbPwaMNuopO8oHrVN0BcU&index=21)
- given a even number of coins
- there 2 players they make a move one by one
- in each move a player can select a number from either end
- that coin would be deleted and next player's turn would come up
- both players are playing optimally
- you start first, return maximum sum of selected coins you can get

```
I/P: 20, 5, 4, 6
O/P: 25

I/P: 2, 3, 15, 7
O/P: 17
```

- if we had problem statement as "ensure that you get more sum than your opponent"
- then that can be easily done as
- if n is even then we can make sure whether your opponent get only even or odd placed numbers then we can select which sum is max (odd or even)

### Recursion Solution 1

```
int sol(int arr[], int i, int j, int sum) {
    if (j == i+1) return max(arr[i], arr[j]);
    return max(sum-sol(arr, i+1, j, sum-arr[i]),
               sum-sol(arr, i, j-1, sum-arr[i]));
}
int mainSol (int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i]
    return sol(arr, 0, n-1, sum);
}
```

- if we make this solution into dp then we would have to memoize sum.
- and sum can be huge for large arrays

### Recursion Solution 2

- ![image](https://i.ibb.co/z8NGNbP/image-2022-07-13-120527930.png)

#### Dynamic Solution

- ![image](https://i.ibb.co/y80vxGB/image-2022-07-13-122153475.png)

## Egg Dropping Puzzle

- [Reference](https://www.youtube.com/watch?v=psbTOUl05T4&list=PL0SWhLkCGuU-HbPwaMNuopO8oHrVN0BcU&index=20)
- given no of eggs and number of floors calculate minimum number of trails we would need to pinpoint threshold floor.
- if egg is dropped and doesn't break then it can be used again.
- a threshold floor is a floor from which dropping an egg will break it
- floors above threshold floor will also break the egg but floors below the threshold won't.
- ![image](https://i.ibb.co/51v51c4/image-2022-07-14-170520283.png)
- ![image](https://i.ibb.co/SVnjKCP/image-2022-07-14-171407272.png)

### Recursion

```
#include <bits/stdc++.h>
using namespace std;

// A utility function to get
// maximum of two integers
int max(int a, int b) {
	return (a > b) ? a : b;
}

// Function to get minimum
// number of trials needed in worst
// case with n eggs and k floors
int eggDrop(int n, int k)
{
	// If there are no floors,
	// then no trials needed.
	// OR if there is one floor,
	// one trial needed.
	if (k == 1 || k == 0)
		return k;

	// We need k trials for one
	// egg and k floors
	if (n == 1)
		return k;

	int min = INT_MAX, x, res;

	// Consider all droppings from
	// 1st floor to kth floor and
	// return the minimum of these
	// values plus 1.
	for (x = 1; x <= k; x++) {
		res = max(
			eggDrop(n - 1, x - 1),
			eggDrop(n, k - x));
		if (res < min)
			min = res;
	}

	return min + 1;
}
int main() {
	int n = 2, k = 10;
	cout << "Minimum number of trials "
			"in worst case with "
		<< n << " eggs and " << k
		<< " floors is "
		<< eggDrop(n, k) << endl;
	return 0;
}
```

### Dynamic Programming

- ![image](https://i.ibb.co/PZs5FxK/image-2022-07-16-120326144.png)

```
int res(int e, int f) {
    int dp[f+1][e+1];
    for (int i = 0; i <= f; i++) {
        for (int i = 1; j <= e; j++) {
            if (i == 0 || i == 1) dp[i][j] = i;
            else if (j == 1) dp[i][j] == i;
            else {
                dp[i][j] = INT_MAX;
                for(int x = 1; x <= i; x++)
                    dp[i][j] = min(dp[i][j],
                        1+max(dp[x-1][j-1], dp[i-x][j]))
            }
        }
    }
    return[f][e];
}
```

## Count BSTs with n keys

- given a number n
- take n distinct numbers and calculate how many unique BSTs can be formed with them, values of these numbers don't matter.
- BST: all keys should be distinct and value on left of node should be smaller than value of parent which should be smaller than value on right child
- ![image](https://i.ibb.co/ggR0srq/image-2022-07-16-122901768.png)

### Algo

- ![image](https://i.ibb.co/59dfdBD/image-2022-07-18-134639170.png)
- ![image](https://i.ibb.co/y0DGfkP/image-2022-07-18-134733489.png)

### Recursion

```
int CountBST(int n) {
    if (n == 0 || n == 1) return 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += CountBST(i-1)*CountBST(n-i);
    return sum;
}
```

### Dynamic Programming

```
int CountBST(int n) {
    int memo[n+1];
    fill(memo, memo+n, 0);
    memo[0] = 1, memo[1] = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            memo[i] += memo[j]*memo[i-j-1];
    }
    return memo[n];
}
```

- the solution for this is catalan number it can be calculated in O(N) time and O(1) space
- ![image](https://i.ibb.co/TvGVQzr/image-2022-07-27-143847257.png)

## Max Sum with No Consecutive

- given array of positive integers calculate max sum that can be obtained by these numbers such that no 2 numbers are consecutive.
- ![image](https://i.ibb.co/5vcLxmz/image-2022-07-27-144135800.png)
### Recursion
```
int maxSum(int arr[], int n) {
    if (n == 1) return arr[0];
    if (n == 2) return max(arr[0], arr[1]);
    return max(maxSum(arr, n-1), arr[n-1]+maxSum(arr, n-2));
}
```
### Dynamic Programming
```
int maxSum(int arr[], int n) {
    int memo[n+1];
    memo[1] = arr[0];
    for (int i = 2; i <= n; i++) {
        if (i == 2) memo[i] = max(arr[0], arr[1]);
        else {
            memo[i] = max(memo[i-1], memo[i-2]+arr[i-1]);
        }
    }
    return memo[n];
}
```