# Binary Search
Binary Search reduces linear search spaces into $O(\log n)$ time by discarding half the elements per iteration. This is strictly required for high-performance lookups.

## Problem Log
| Problem | File Name | Time Complexity | Approach | Difficulty | LeetCode Problem No.
| :--- | :--- | :--- | :--- | :--- | :-- |
| Search in Rotated Sorted Array| [RotatedSortedArray.cpp](./RotatedSortedArray.cpp) | $O(\log n)$ | Modified Binary | Medium | 33
| Peak Index in Mountain Array | [PeakIndexMountainArray.cpp](./PeakIndexMountainArray.cpp) | $O(\log n)$ | Binary Search | Medium | 852
| Single Element in Sorted Array | [SingleElementInSortedArray.cpp](./SingleElementInSortedArray.cpp) | $O(\log n)$ | Binary Search  | Medium | 540


## Problem Logic Breakdowns

<!-- RotatedSortedArray -->
<details>
<summary><b> Search in Rotated Sorted Array </b> </summary>
 
 > **Solution File:** [RotatedSortedArray.cpp](./RotatedSortedArray.cpp)

 ### Logic
 1. **Initialize Pointers:** Set `st` to index 0 and `end` to the final index of the array to define the search space.
 2. **Locate Sorted Half:** Calculate `mid`. Determine which continuous half of the array is strictly sorted by comparing the value at `st` to the value at `mid`.
 3. **Target Verification:** If the left half is sorted, check if the target mathematically falls within its bounds (`nums[st] <= target && target < nums[mid]`). If true, eliminate the right half (`end = mid - 1`). Otherwise, eliminate the left half (`st = mid + 1`).
 4. **Mirror Logic:** Apply the exact inverse logic if the right half is identified as the sorted segment.

 ### Edge Cases Handled 
 - **Pointer Collision:** Handled the edge case where the search space shrinks to two elements (causing `st` and `mid` to point to the exact same index) by utilizing the `<=` operator (`nums[st] <= nums[mid]`).
 - **C++ Relational Evaluation:** Prevented the logical error of chained comparisons ($a \le b \le c$) by explicitly separating boundaries with the logical AND (`&&`) operator, ensuring the compiler does not evaluate the first condition as a boolean integer.

 ### Why this approach?
 The problem strictly requires an $O(\log n)$ runtime complexity, immediately ruling out an $O(n)$ linear scan. This modified Binary Search achieves this by guaranteeing that at least one half of the rotated array is always sorted, allowing us to safely discard half the search space at every step.

 ### Complexity Analysis
 - **Time Complexity:** $O(\log n)$ — The search space is halved in each iteration of the `while` loop.
 - **Space Complexity:** $O(1)$ — Only three integer pointer variables (`st`, `end`, `mid`) are allocated.
</details>

<!--------------------------------------------------------------------------------------------------------------------------------------------->
<!-- RotatedSortedArray -->
<details>
<summary><b> Peak Index in a Mountain Array </b> </summary>
 
 > **Solution File:** [PeakIndexMountainArray.cpp](./PeakIndexMountainArray.cpp)

 ### Logic
 1. **Initialize Pointers:** Set `st = 1` and `end = nums.size() - 2`. We strictly ignore the first and last elements because a valid mountain peak must have strictly smaller elements on both the left and right sides.
 2. **Analyze the Slope:** Calculate `mid`. We check the current trajectory of the mountain:
    - **Upward Slope:** If `nums[mid] < nums[mid+1]`, we have not reached the peak yet. The peak strictly lies to the right, so we eliminate the left half (`st = mid + 1`).
    - **Downward Slope:** If `nums[mid] > nums[mid+1]` (and it's not the peak), the peak strictly lies to the left, so we eliminate the right half (`end = mid - 1`).
 3. **Identify the Peak:** If `nums[mid]` is strictly greater than both `nums[mid-1]` and `nums[mid+1]`, the inflection point is found. Return `mid`.

 ### Edge Cases Handled 
 - **Segmentation Fault Prevention:** By binding the search space strictly between index `1` and `n-2`, the algorithm is mathematically immunized against Out-Of-Bounds memory access when evaluating `nums[mid-1]` and `nums[mid+1]`.
 - **Copy-Paste Logic Errors:** Ensured strict mutual exclusivity in the slope checks to prevent logical contradictions (e.g., checking if a value is simultaneously greater than and less than the same neighbor).

 ### Why this approach?
 A linear scan $O(n)$ would trivially find the max element, but the strictly increasing/decreasing nature of a Mountain Array guarantees a sorted property relative to the peak. This allows us to apply Modified Binary Search, dropping the time complexity to $O(\log n)$—the strict requirement for large-scale data lookups.

 ### Complexity Analysis
 - **Time Complexity:** $O(\log n)$ — The search space is halved in each iteration.
 - **Space Complexity:** $O(1)$ — Only three integer variables allocated.
</details>

<!--------------------------------------------------------------------------------------------------------------------------------------------->
<!-- Single Element in Sorted Array -->
<details>
<summary><b> Single Element in a Sorted Array </b> </summary>
 
 > **Solution File:** [SingleElementSortedArray.cpp](./SingleElementSortedArray.cpp)

 ### Logic
 1. **The Parity Pattern:** In a perfectly paired sorted array, duplicates always align on `(Even, Odd)` index pairs. The presence of a single element permanently disrupts this parity for all subsequent elements, shifting their pairs to `(Odd, Even)`.
 2. **Index Evaluation:** We calculate `mid` and check its parity (`mid % 2`).
    - **If `mid` is Even:** Its duplicate *should* be at `mid + 1`. If instead it matches `mid - 1`, the pattern was broken earlier in the array. We eliminate the right half (`end = mid - 1`). Otherwise, the left half is structurally sound, so we eliminate it (`st = mid + 1`).
    - **If `mid` is Odd:** Its duplicate *should* be at `mid - 1`. If it matches `mid - 1`, the left half is structurally sound (`st = mid + 1`). Otherwise, the pattern is broken (`end = mid - 1`).

 ### Edge Cases Handled 
 - **Out-of-Bounds Memory Safety:** Isolated the binary search space strictly to `st = 1` and `end = n - 2` to prevent Segmentation Faults when evaluating `nums[mid-1]` and `nums[mid+1]`. 
 - **Boundary Anomalies:** Explicitly handled scenarios where the single element is at index `0`, index `n-1`, or if the array size is exactly `1` before entering the search loop.
 - **Compiler Type-Checking:** Appended a fallback `return -1;` to satisfy strict non-void function return policies.

 ### Why this approach?
 While Bitwise XOR solves this in $O(n)$ time, the "sorted" constraint mandates a highly optimized $O(\log n)$ search space reduction. By searching for the structural disruption in index parity rather than evaluating the raw integers, we achieve sub-linear time complexity.

 ### Complexity Analysis
 - **Time Complexity:** $O(\log n)$ — The search space is halved every iteration.
 - **Space Complexity:** $O(1)$ — Only integer variables allocated.
</details>



