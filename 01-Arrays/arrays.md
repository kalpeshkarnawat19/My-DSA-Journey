# Arrays
`Arrays` are the most fundamental data structure.

## Problem Log
| Problem | File Name | Time Complexity | Approach | Difficulty | LeetCode Problem No.
| :--- | :--- | :--- | :--- | :--- | :-- |
| Find Single Number | [SingleNumber.cpp](./SingleNumber.cpp) | $O(n)$ | Bitwise XOR (Self-inverse property) | Easy | 136
| Majority Element | [MajorityElement.cpp](./MajorityElement.cpp) | $O(n \log n)$ | Sorting | Easy | 169
| Majority Element | [MajorityElement_Moore.cpp](./MajorityElement_Moore.cpp) | $O(n)$ | Moore's Voting Algorithm | Easy | 169
| Maximum Subarray | [MaxSubArraySum.cpp](./MaxSubArraySum.cpp) | $O(n)$ | Kadane's Algorithm | Medium | 53


## Problem Logic Breakdowns

<!-- //Single number -->
<details>
<summary><b> Find The Single Number </b> </summary>
 
 > **Solution File:** [SingleNumber.cpp](./SingleNumber.cpp)

 ### Logic
 1. Bitwise XOR - n^n = 0 and n^0 = n
 2. Since only one number is unique, taking XOR of all elements, the same ones will cancel out.

 ### Edge Cases Handled 
 - **Incorrect Input:** handled by checking `if (!(std::cin >> size)) return 0`. 

 ### Why this approach?
 The question had specified solution must have a linear time complexity $O(n)$, therefore only one loop can be used. Also Bitwise operators work fast as they run in the CPU registers.
</details>

<!-- majority element -->
<details>
 <summary><b> Majority Element (sorting) </b></summary>

 > **Solution File:** [MajorityElement.cpp](./MajorityElement.cpp)

 ### Logic
 1. Sorting: We first sort the array using std::sort. This ensures all identical elements are placed consecutively.
 2. Frequency Count: We traverse the sorted array and count the occurrences of each element.
    - If the current element is the same as the previous one, we increment the freq counter.
    - If it's different, we reset the freq counter to 1 and update our ans candidate.
 3. Majority Check: At each step, we check if freq > size / 2. If true, the current element is the majority element, and we return it immediately.

 ### Why this approach?
 Sorting allows us to identify the majority element in a single linear pass after the $O(n \log n)$ sort. This is a significant improvement over the $O(n^2)$ Brute Force method, as it reduces the number of comparisons needed.

 ### Complexity Analysis
 - **Time Complexity:** $O(n \log n)$ The subsequent linear traversal is $O(n)$.
 - **Space Complexity:** $O(1)$ — The algorithm sorts in-place.
</details>


<!-- Majority element -->
<details>
 <summary><b> Majority Element (Moore's Voting Algorithm) </b></summary>

 > **Solution File:** [MajorityElement_Moore.cpp](./MajorityElement_Moore.cpp)

 ### Logic
 1. Candidate Selection: We maintain a candidate and a count
 2. The Process:
    - If count == 0, we pick the current element as our new candidate.
    - If the current element matches the candidate, we increment count.
    - If it doesn't match, we decrement count.
 3. The Survivor: Because the majority element exists > $n/2$ times, it will mathematically always be the last candidate standing after all "votes" are processed.

 ### Complexity Analysis
 - **Time Complexity:** $O(n)$ — Single linear pass.
 - **Space Complexity:**  $O(1)$ — Only two integer variables used.
</details>

<!-- Max Subarray Sum  -->
<details>
 <summary><b> Maximum Subarray Sum (Kadane's Algorithm)</b></summary>

 > **Solution File:** [MaxSubArraySum.cpp](./MaxSubArraySum.cpp)

 ### Logic
 1. **The Choice:** At each element, we decide whether to add the current element to our existing sum or start a new subarray.
 2. **The Reset:** If `currentSum` drops below 0, it will only decrease the sum of any future subarray. Therefore, we reset it to 0 (effectively starting a new subarray from the next element).
 3. **Global Max:** We keep track of the highest `currentSum` we've ever seen using `maxSum`.
 4. **Key Intuition**: A subarray with a negative sum is a "liability." Adding a negative number to a future sequence will always result in a smaller sum than if that future sequence stood alone. Hence, we "cut our losses" and reset to zero.

 ### Complexity Analysis
 - **Time Complexity:** $O(n)$ — Single pass through the array.
 - **Space Complexity:** $O(1)$ — No extra data structures used.
</details>

