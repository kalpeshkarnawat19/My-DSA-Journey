# Arrays
`Arrays` are the most fundamental data structure. They offer $O(1)$ spatial locality, making them highly optimized for CPU cache prefetching—a critical feature for low-latency and high-frequency systems.

## Problem Log
| Problem | File Name | Time Complexity | Approach | Difficulty | LeetCode Problem No.
| :--- | :--- | :--- | :--- | :--- | :-- |
| Majority Element | [MajorityElement.cpp](./MajorityElement.cpp) | $O(n \log n)$ | Sorting | Easy | 169
| Majority Element | [MajorityElement_Moore.cpp](./MajorityElement_Moore.cpp) | $O(n)$ | Moore's Voting Algorithm | Easy | 169
| Stock Buy & Sell | [StockBuyAndSell.cpp](./StockBuyAndSell.cpp) | $O(n)$ | Greedy (Min-So-Far)  | Easy | 121
| Maximum Subarray | [MaxSubArraySum.cpp](./MaxSubArraySum.cpp) | $O(n)$ | Kadane's Algorithm | Medium | 53
| Product Except Self| [ProductExceptSelf.cpp](./ProductExceptSelf.cpp) | $O(n)$ | Prefix & Suffix Product | Medium | 238


## Problem Logic Breakdowns

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

