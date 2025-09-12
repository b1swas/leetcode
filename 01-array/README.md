- contiguous
- static array: fixed size
    * reading: O(1) -> constant time
    * writing: O(1)
    * insert (if space available) / removing from end: O(1)
    * insert middle = right shift **each** of the following: O(n)
    * remove middle = left shift each of the following: O(n)
- 
