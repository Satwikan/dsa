# Bit Maniluplations

# Properties:
- (1 << pos) left shifts 1 pos times
- a & b: applies AND operation to every bit in a and b
- a | b: applies OR operation to every bit in a and b
- (n & n - 1) has same bits as n except the rightmost set bit

<hr/>

## to check for a particular bit at some postion if it is 1 or not for any number
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
- 
