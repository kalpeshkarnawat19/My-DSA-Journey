# Arrays
`Arrays` are the most fundamental data structure. They offer $O(1)$ spatial locality, making them highly optimized for CPU cache prefetching—a critical feature for low-latency and high-frequency systems.

## Problem Log
| Problem | File Name | Time Complexity | Approach | Difficulty | LeetCode Problem No.
| :--- | :--- | :--- | :--- | :--- | :-- |
| Find Single Number | [SingleNumber.cpp](./SingleNumber.cpp) | $O(n)$ | Bitwise XOR (Self-inverse property) | Easy | 136
| Majority Element | [MajorityElement.cpp](./MajorityElement.cpp) | $O(n \log n)$ | Sorting | Easy | 169
| Majority Element | [MajorityElement_Moore.cpp](./MajorityElement_Moore.cpp) | $O(n)$ | Moore's Voting Algorithm | Easy | 169
| Stock Buy & Sell | [StockBuyAndSell.cpp](./StockBuyAndSell.cpp) | $O(n)$ | Greedy (Min-So-Far)  | Easy | 121
| Maximum Subarray | [MaxSubArraySum.cpp](./MaxSubArraySum.cpp) | $O(n)$ | Kadane's Algorithm | Medium | 53
| Pair Sum | [PairSum.cpp](./PairSum.cpp) | $O(n)$ | Two Pointer | Medium | 167
| Container With Most Water| [ContainerWithMostWater.cpp](./ContainerWithMostWater.cpp) | $O(n)$ | Two Pointer | Medium | 11
| Product Except Self| [ProductExceptSelf.cpp](./ProductExceptSelf.cpp) | $O(n)$ | Prefix & Suffix Product | Medium | 238
| Pow(x,n)| [Pow(x,n).cpp](./Pow(x,n).cpp) | $O(\log n)$ | Binary Exponentiation | Medium | 50
| Search in Rotated Sorted Array| [RotatedSortedArray.cpp](./RotatedSortedArray.cpp) | $O(\log n)$ | Modified Binary | Medium | 33


## Problem Logic Breakdowns

<!-- //Single number -->
<details>
<summary><b> Find The Single Number </b> </summary>
 
 > **Solution File:** [SingleNumber.cpp](./SingleNumber.cpp)

 ### Logic
 1. **Apply Bitwise XOR:** Utilize the properties $n \oplus n = 0$ and $n \oplus 0 = n$.
 2. **Elimination:** Since only one number is unique, take the XOR of all elements. Duplicate numbers will mathematically cancel out, leaving only the unique number.

 ### Edge Cases Handled 
 - **Incorrect Input:** Prevent invalid streams by checking `if (!(std::cin >> size)) return 0;`. 

 ### Why this approach?
 The constraints strictly demand linear time complexity $O(n)$ and $O(1)$ auxiliary space. Furthermore, bitwise operations are exceptionally fast as they execute directly within CPU registers.
</details>


<!------------------------------------------------------------------------------------------------------------------------------------------ -->
<!-- majority element -->
<details>
 <summary><b> Majority Element (sorting) </b></summary>

 > **Solution File:** [MajorityElement.cpp](./MajorityElement.cpp)

 ### Logic
 1. **Sort:** Sort the array using `std::sort` to guarantee all identical elements are placed consecutively.
 2. **Count:** Traverse the sorted array and count occurrences. If the current element matches the previous, increment the frequency counter. Otherwise, reset the counter to 1 and update the candidate.
 3. **Verify:** At each step, check if `freq > size / 2`. If true, return the element immediately.

 ### Why this approach?
 Sorting maps the $O(n^2)$ Brute Force search down to a single linear pass following an $O(n \log n)$ operation, drastically reducing the total number of comparisons.

 ### Complexity Analysis
 - **Time Complexity:** $O(n \log n)$ — Dominated by the sorting algorithm. The subsequent traversal is $O(n)$.
 - **Space Complexity:** $O(1)$ — The algorithm sorts in-place.
</details>


<!------------------------------------------------------------------------------------------------------------------------------------------ -->
<!-- Majority element -->
<details>
 <summary><b> Majority Element (Moore's Voting Algorithm) </b></summary>

 > **Solution File:** [MajorityElement_Moore.cpp](./MajorityElement_Moore.cpp)

### Logic
 1. **Initialize:** Maintain a `candidate` variable and a `count`.
 2. **Process:** Traverse the array. If `count == 0`, assign the current element as the new `candidate`. If the current element matches the candidate, increment the `count`. If it differs, decrement the `count`.
 3. **The Survivor:** Because the majority element strictly exists $> n/2$ times, it mathematically remains the last candidate standing after all elements are processed.

 ### Complexity Analysis
 - **Time Complexity:** $O(n)$ — Optimal single linear pass.
 - **Space Complexity:** $O(1)$ — Only two integer variables are allocated.
</details>


<!------------------------------------------------------------------------------------------------------------------------------------------ -->
<!-- Max Subarray Sum  -->
<details>
 <summary><b> Maximum Subarray Sum (Kadane's Algorithm)</b></summary>

 > **Solution File:** [MaxSubArraySum.cpp](./MaxSubArraySum.cpp)

### Logic
 1. **The Choice:** At each element, determine whether to add the current element to the existing sequence sum or start a new sequence.
 2. **The Reset:** If `currentSum` drops below 0, reset it to 0. A negative sum is a liability that strictly decreases the overall value of any future sequence.
 3. **Global Max:** Track the highest `currentSum` encountered using the `maxSum` variable.

 ### Edge Cases Handled
 - **Integer Overflow:** Handled potential overflow for large arrays ($10^5$ elements) by tracking sums using `long long` instead of standard 32-bit integers.

 ### Complexity Analysis
 - **Time Complexity:** $O(n)$ — Single pass through the array.
 - **Space Complexity:** $O(1)$ — No extra data structures utilized.
</details>


<!------------------------------------------------------------------------------------------------------------------------------------------ -->
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
<!-- Stock Buy and Sell-->
<details>
<summary><b> Best Time to Buy and Sell Stock </b> </summary>
 
 > **Solution File:** [StockBuyAndSell.cpp](./StockBuyAndSell.cpp)

 ### Logic
 1. **Greedy Tracking:** Maintain two states: `bestBuy` (the absolute minimum price seen) and `maxProfit`.
 2. **Iterate:** Traverse the array. If the current price exceeds `bestBuy`, calculate the potential profit and update `maxProfit` if it is the highest seen. Update `bestBuy` at every iteration to lock in the lowest historical price.

 ### Why this approach?
 Maximizing profit only requires knowing the lowest price that occurred *prior* to the current day, eliminating the need for an $O(n^2)$ exhaustive search.

 ### Complexity Analysis
 - **Time Complexity:** $O(n)$ — Single linear pass.
 - **Space Complexity:** $O(1)$ — Constant auxiliary space.
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


<!------------------------------------------------------------------------------------------------------------------------------------------ -->
<!-- Product Except Self-->
<details>
<summary><b> Product Except Self </b> </summary>
 
 > **Solution File:** [ProductExceptSelf.cpp](./ProductExceptSelf.cpp)

 ### Logic
 1. **Prefix Pass:** Create an array `ans` where `ans[i]` stores the product of all elements to the left. Initialize `ans[0] = 1` since there are no elements left of index 0.
 2. **Suffix Pass:** Initialize a single integer variable `suffix = 1` to track the running product of all elements to the right.
 3. **Combine:** Traverse the array from right to left. Multiply `ans[i]` by `suffix`, then update `suffix` by multiplying it with `nums[i]`.

 ### Complexity Analysis
 - **Time Complexity:** $O(n)$ — Two linear passes (one forward, one backward).
 - **Space Complexity:** $O(1)$ — Excluding the required output array, only one integer variable (`suffix`) is utilized.
</details>


<!------------------------------------------------------------------------------------------------------------------------------------------ -->
<!-- Pow(x,n) -->
<details>
<summary><b> Pow(x,n) </b> </summary>
 
 > **Solution File:** [Pow(x,n).cpp](./Pow(x,n).cpp)

### Logic
 1. **Divide and Conquer:** Instead of multiplying $x$ by itself $n$ times ($O(n)$), utilize the binary exponentiation property $x^n = (x^{n/2})^2$.
 2. **Bitwise Execution:** Traverse the bits of $n$. If the current bit is 1, multiply the running result by the current power of $x$. At every step, square $x$ ($x = x * x$).
 3. **Edge Case Handling:**
    - **Negative Exponents:** If $n < 0$, transform the problem to $(1/x)^{-n}$. Cast $n$ to a `long long` to prevent integer overflow when $n = -2^{31}$.
    - **Base Cases:** Handle $x=0$, $x=1$, and $n=0$ explicitly for early exit efficiency.

### Why this approach?
A linear $O(n)$ approach will trigger a Time Limit Exceeded (TLE) verdict for $n = 2^{31}-1$. Binary Exponentiation drops the multiplication operations to approximately $\log_2(n)$, making it strictly optimal for massive limits.

### Complexity Analysis
- **Time Complexity:** $O(\log n)$ — The exponent is halved in each iteration.
- **Space Complexity:** $O(1)$ — Only a fixed amount of extra space (`ans` and `long long` for the exponent) is allocated.
</details>


<!------------------------------------------------------------------------------------------------------------------------------------------ -->
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

 ### Why this approach?
 The problem strictly requires an $O(\log n)$ runtime complexity, immediately ruling out an $O(n)$ linear scan. This modified Binary Search achieves this by guaranteeing that at least one half of the rotated array is always sorted, allowing us to safely discard half the search space at every step.

 ### Complexity Analysis
 - **Time Complexity:** $O(\log n)$ — The search space is halved in each iteration of the `while` loop.
 - **Space Complexity:** $O(1)$ — Only three integer pointer variables (`st`, `end`, `mid`) are allocated.
</details>



