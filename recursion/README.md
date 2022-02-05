## tail recursion
- a function is tail recursive when parent call has nothing to do after calling child
- tail recursion uses less time than no-tail recursion on modern compilers
- because modern compilers do tail elimination thus doesn't have to save state for every recursive call
- quick sort is tail recursive, while merge sort is not
- [refrence video](https://www.youtube.com/watch?v=fBxfQJ92fz8&list=PL0SWhLkCGuU9UWKj4QA4Xc-jbrsd-FN1a&index=8)
