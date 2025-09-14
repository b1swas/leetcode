- contiguous
- static array: fixed size
    * reading: O(1) -> constant time
    * writing: O(1)
    * insert (if space available) / removing from end: O(1)
    * insert middle = right shift **each** of the following: O(n)
    * remove middle = left shift each of the following: O(n)
- dynamic array: dynamic size
    * push and pop at the end: O(1)
    * when ran out of space, new memory allocated + copy each element: O(n) + O(n)
    * reallocation is generally done with double of previous size: amortized time complexity O(n)
    * so time complexity is same as static array
