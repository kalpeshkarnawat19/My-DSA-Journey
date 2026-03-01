# Two Pointers
Two Pointers optimize $O(n^2)$ nested loops into $O(n)$ linear scans by exploiting sorted properties or geometrical bounds.

## Problem Log
| Problem | File Name | Time Complexity | Approach | Difficulty | LeetCode Problem No.
| :--- | :--- | :--- | :--- | :--- | :-- |
| Pair Sum | [PairSum.cpp](./PairSum.cpp) | $O(n)$ | Two Pointer | Medium | 167
| Container With Most Water| [ContainerWithMostWater.cpp](./ContainerWithMostWater.cpp) | $O(n)$ | Two Pointer | Medium | 11


## Problem Logic Breakdowns

<!-- Pair Sum -->
<details>
 <summary><b> Pair Sum </b></summary>

 > **Solution File:** [PairSum.cpp](./PairSum.cpp)

### Logic
 1. **Initialize:** Exploit the sorted property of the array by placing two pointers: `start` at index 0 and `end` at the final index.
 2. **Compare:** Calculate the sum of the elements at these pointers.
    - If `sum == target`: Return the indices.
    - If `sum < target`: Move the `start` pointer forward to access a larger value.
    - If `sum > target`: Move the `end` pointer backward to access a smaller value. 

 ### Why this approach?
 Exploiting the sorted array property collapses an $O(n^2)$ nested-loop search into a highly efficient $O(n)$ linear scan.

 ### Complexity Analysis
 - **Time Complexity:** $O(n)$ — Bounded by a single `while` loop.
 - **Space Complexity:** $O(1)$ — Pointer variables only.
</details>

<!------------------------------------------------------------------------------------------------------------------------------------------ -->
<!-- Container with Most Water-->
<details>
<summary><b> Container With Most Water </b> </summary>
 
 > **Solution File:** [ContainerWithMostWater.cpp](./ContainerWithMostWater.cpp)

### Logic
 1. **Initialize:** Place one pointer at the start (`lp`) and one at the end (`rp`) to maximize initial width.
 2. **Iterate:** Calculate the area. The height is bottlenecked by the shorter line, and the width is the distance between the pointers.
 3. **Update:** Record the maximum area seen. Move the pointer of the *shorter* line inward, as this is the only mathematical way to potentially find a taller boundary that compensates for the decreasing width.

 ### Complexity Analysis
 - **Time Complexity:** $O(n)$ — Single linear pass.
 - **Space Complexity:** $O(1)$ — Constant auxiliary space.
</details>
