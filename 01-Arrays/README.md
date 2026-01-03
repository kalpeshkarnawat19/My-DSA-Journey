# Arrays
`Arrays` are the most fundamental data structure.

## Key Concepts
* **Time Complexity:** Most operations are $O(n)$, but searching can be $O(\log n)$ if the array is sorted.
* **Space Complexity:** Focused on $O(1)$ (in-place) solutions.
* **Techniques:** Traversal, Swapping, and Two-pointer approaches.

## Problem Log
| Problem | File Name | Time Complexity | Approach | Difficulty | LeetCode Problem No.
| :--- | :--- | :--- | :--- | :--- | :-- |
| Find Single Number | `SingleNumber.cpp` | $O(n)$ | Bitwise XOR (Self-inverse property) | Easy | 136


## Problem Logic Breakdowns

<details>
<summary><b>1. Find The Single Number </b></summary>

### Logic
1. Bitwise XOR - n^n = 0 and n^0 = n
2. Since only one number is unique, taking XOR of all elements, the same ones will cancel out.

### Edge Cases Handled 
- **Incorrect Input:** handled by checking `if (!(std::cin >> size)) return 0`. 

### Why this approach?
The question had specified solution must have a linear time complexity $O(n)$, therefore only one loop can be used. Also Bitwise operators work fast as they run in the CPU registers.
</details>



