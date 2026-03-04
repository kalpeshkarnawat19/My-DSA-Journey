# Math and Bitwise
Bitwise operations execute directly in CPU registers, offering sub-millisecond execution times for low-latency calculations.

## Problem Log
| Problem | File Name | Time Complexity | Approach | Difficulty | LeetCode Problem No.
| :--- | :--- | :--- | :--- | :--- | :-- |
| Find Single Number | [SingleNumber.cpp](./SingleNumber.cpp) | $O(n)$ | Bitwise XOR (Self-inverse property) | Easy | 136
| Pow(x,n)| [Pow(x,n).cpp](./Pow(x,n).cpp) | $O(\log n)$ | Binary Exponentiation | Medium | 50


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

