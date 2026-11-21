# Problem 1964

## Imperative Solution (C++)

### C++ Implementation

I started by creating a vector to store all the numbers from 1 to n. I created a global variable called `mv` to keep track of the current elimination rule. I implemented the first rule, where I keep the elements at even indexes and remove the elements at the odd indexes. Then, I added the second rule, where I keep the elements at odd indexes. After that, I implemented the third rule, where I remove every third element. I used a separate vector called `next_arr` to store the elements that remain after each operation. Once an operation is completed, I update `mv` so that the next elimination rule is applied. I made the `game()` function recursive so that it repeats these three operations until only one element remains. I added a base case to stop the recursion when the vector contains just one element. Finally, I return the last remaining element as the answer.