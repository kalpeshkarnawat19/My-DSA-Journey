# Arrays
`Arrays` are the most fundamental data structure.

## Key Concepts
* **Time Complexity:** Most operations are $O(n)$, but searching can be $O(\log n)$ if the array is sorted.
* **Space Complexity:** Focused on $O(1)$ (in-place) solutions.
* **Techniques:** Traversal, Swapping, and Two-pointer approaches.

## Problem Log
| Problem | File Name | Time Complexity | Approach | Difficulty | LeetCode Problem No.
| :--- | :--- | :--- | :--- | :--- | :-- |
| Find Single Number | [SingleNumber.cpp](./SingleNumber.cpp) | $O(n)$ | Bitwise XOR (Self-inverse property) | Easy | 136
| Maximum Subarray | [MaxSubArraySum.cpp](./MaxSubArraySum.cpp) | $O(n)$ | Kadane's Algorithm | Medium | 53


## Problem Logic Breakdowns

<details>
 <summary><b>1. Find The Single Number </b></summary>

 > **Solution File:** [SingleNumber.cpp](./SingleNumber.cpp)

 ### Logic
 1. Bitwise XOR - n^n = 0 and n^0 = n
 2. Since only one number is unique, taking XOR of all elements, the same ones will cancel out.

 ### Edge Cases Handled 
 - **Incorrect Input:** handled by checking `if (!(std::cin >> size)) return 0`. 

 ### Why this approach?
 The question had specified solution must have a linear time complexity $O(n)$, therefore only one loop can be used. Also Bitwise operators work fast as they run in the CPU registers.
</details>

<details>
<summary><b>2. Maximum Subarray Sum (Kadane's Algorithm)</b></summary>

>**Solution File:** [MaxSubArraySum.cpp](./MaxSubArraySum.cpp)

### Logic
1. **The Choice:** At each element, we decide whether to add the current element to our existing sum or start a new subarray.
2. **The Reset:** If `currentSum` drops below 0, it will only decrease the sum of any future subarray. Therefore, we reset it to 0 (effectively starting a new subarray from the next element).
3. **Global Max:** We keep track of the highest `currentSum` we've ever seen using `maxSum`.
4. **Key Intuition**: A subarray with a negative sum is a "liability." Adding a negative number to a future sequence will always result in a smaller sum than if that future sequence stood alone. Hence, we "cut our losses" and reset to zero.

### Complexity Analysis
- **Time Complexity:** $O(n)$ — Single pass through the array.
- **Space Complexity:** $O(1)$ — No extra data structures used.
</details>



