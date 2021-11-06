# Bit Manipulations

# Properties:
- (1 << pos) left shifts 1 pos times
- a & b: applies AND operation to every pair-bit in a and b
- a | b: applies OR operation to every pair-bit in a and b
- a ^ b: XOR: same 0, different 1
- a ^ a = 0
- a ^ 0 = a
- a ^ b = x, therefore x ^ a = b
- (n & n - 1) has same bits as n except the rightmost set bit

<hr/>

## to check for right most setbit
- [refer this program for more info](https://github.com/Satwikan/dsa/blob/master/bit/uniqueNumberFind.cpp)

## to check for a particular bit at some position if it is 1 or not for any number
- (1 << pos) left shifts 1 pos times
- take ((1 << pos) & n) 

## check for division of 2 for any number
- (n & n - 1) has same bits as n except the rightmost set bit
- to check for division for 2 therefore for any number take (n & n - 1) it will be zero

## no of ones in a binary number
- (n & n-1) has same bits as n except right most set bit
- take (n & n-1)
- make n = (n & n-1)
- repeat above steps until you reach 0
- number of times it took to reach zero is no of ones in binary

## generate all possible subsets of a set
- let's take example we have to generate all sets of {a, b, c}
- write its combination as binary by selecting or not selecting a particular character as 1 or 0 resp.
- therefore
```
{}    000
{c}   001
{b}   010
{b,c} 011
{a}   100
...
```
- number of combinations generated will equal to 2^n
- loop i through 2^n and print any digit only if its corresponding bit in i is 1

## find a unique number in an array where all numbers except one, are present twice
- use XOR operation between all elements in the array
- XOR only return 0 if both numbers are same, and returns a for a ^ 0
- therefor only 1 number would remain that would be unique
- [refer this program for more info](https://github.com/Satwikan/dsa/blob/master/bit/uniqueNumberFind.cpp)

## find 2 unique numbers in an array where all numbers except two, are present twice
- [same as this](https://github.com/Satwikan/dsa/blob/master/bit/readme.md#find-unique-number-in-an-array-where-all-numbers-except-one-are-present-twice)
- but when we reach at end with XOR of those 2 unique numbers (let's take it as x)
- check position of rightmost set bit of x,
- one of those 2 unique number would have 1 at that postion and other won't
- repeat [this](https://github.com/Satwikan/dsa/blob/master/bit/readme.md#find-unique-number-in-an-array-where-all-numbers-except-one-are-present-twice) again
- but instead of whole array select only number which has 1 at that position, you will get one of the unique number (take it as a)
- now (a ^ b = x) therefore (x ^ a = b) thus we get b
- [refer this program for more info](https://github.com/Satwikan/dsa/blob/master/bit/uniqueNumberFind.cpp)

## find a unique number in an array where all numbers except one, are present thrice
- given array arr
- make an int array of size 64, loop through it (i),
- store sum of no. of times 1 appears in arr in i<sup>th</sup> position
- sum at each position must be divisible of 3
- if it's not then our unique number has 1 in that position
- thus form a digit by that
- [refer this program for code](https://github.com/Satwikan/dsa/blob/master/bit/uniqueNumberFind.cpp)
