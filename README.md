# Problem 1964

## Imperative Solution (C++)

### C++ Implementation - Recursive Approach

I used a `vector<int>` to store the numbers from 1 to N. The main idea is to simulate the elimination process by creating a new vector after each move and keeping only the elements that should remain. I implemented this process inside a recursive function called `game`. It takes the current vector as an argument and returns an integer, which is the last remaining number.

At the beginning of each function call, I check whether the vector contains only one element. If it does, the function returns that element. This is the base case that stops the recursion Otherwise, the function goes through the current vector and adds the elements that should remain to a new vector, depending on the current move. I use a variable called `mv` to keep track of the move. After each elimination, I update it so that the next rule is applied.

The function then calls itself with the newly created vector. This continues until only one element remains, which is returned as the final result.
The following is the part of my code where I create a new vector and add the elements that should remain:
```
int game(vector<int> arr){
    if(arr.size()==1){
        return arr[0];
    }
    vector<int> next_arr;
    for(int i=0; i<arr.size(); i++){
        if(mv==1 && i%2 ==0){
            next_arr.push_back(arr[i]);
        }
        else if (mv==2 && i%2 ==1){
            next_arr.push_back(arr[i]);
        }
        else if (mv==3 && (i+1) % 3 != 0){
            next_arr.push_back(arr[i]);
        }
    }
    mv = mv % 3 +1;
    return game(next_arr);

}
```

### Submission Result

**E-olymp Result: 97/100**

<img width="467" height="131" alt="cpp_result" src="https://github.com/user-attachments/assets/5fccbb90-53e2-4adb-aa34-a8145fb47dc2" />

My C++ implementation passed 97% of the test cases. For Test 29, the memory usage reached the 512 MB limit. I think this happened because each recursive call creates a new vector to store the remaining elements. At the same time the previous vectors are still in memory because their function calls have not finished. As a result, multiple vectors occupy memory at the same time. 
This implementation did not exceed the time limit, the only issue was memory usage.

### Updated C++ Implementation(Memory Optimization)

After receiving a memory overflow on Test 29, I decided to improve my implementation. In my original solution, each recursive call created a new vector to store the remaining elements. This caused multiple vectors to occupy memory at the same time.

In my new implementation I changed the function to receive the vector by reference (`vector<int>& arr`) and modified the existing vector instead of creating a new one. I used `arr[j++] = arr[i]` to keep the elements that should remain and `arr.resize(j)` to update the vector's size after each move. In the end I wrote `arr.reserve(n)` to allocate enough capacity for the initial number of elements in advance.

These changes reduced memory usage and resolved the memory overflow problem. After updating the implementation, I received 100/100 on E-olymp.

### Submission Result

<img width="436" height="59" alt="cpp_result3" src="https://github.com/user-attachments/assets/4b56cfc3-c007-4457-a0b4-f18d075eb678" />


## Functional Implementation (Haskell)

To implement the same problem in a functional programming paradigm, I choosed Haskell because it is supported by E-olymp and is also covered in our Advanced Software Paradigms course. 

### Implementation

**1. Function Definition**

```haskell
game :: [Int] -> Int -> Int
```
I defined a function called `game`  that takes a list of integers and the current move number. It returns the last remaining integer as the problem requests.

**2. Recursive Approach - Base Case**

```haskell
game [x] _ = x
```

The game function repeatedly applies the elimination rules and calls itself with a new list until only one element remains. To stop the recursion, I first need to define a base case. When the list contains only one element, the function returns that element as the final answer.

**3. Recursive Elimination**

```haskell
game xs mv
    | mv == 1 = game [x | (i, x) <- zip [1..] xs, odd i] 2
    | mv == 2 = game [x | (i, x) <- zip [1..] xs, even i] 3
    | otherwise = game [x | (i, x) <- zip [1..] xs, i `mod` 3 /= 0] 1
```

I used guards to decide which elimination rule to apply. For each move, I use a list comprehension to create a new list containing the elements that should remain.

1.For the first move, I remove elements in even positions and keep elements in odd positions using `odd i`.
2. For the second move, I remove elements in odd positions and keep elements in even positions using `even i`.
3. For the third move, I remove elements in positions divisible by 3 using `i mod 3 /= 0`.

I use `zip [1..] xs` to associate each element with its position in the current list. This also means that positions start from 1 again after every elimination. At the end of each recursive call, I pass the next move number. I use `2` after the first move, `3` after the second move, and `1` after the third move. This makes the process repeat in the same order.

**4. Main Function**

```haskell
main :: IO ()
main = do
    n <- readLn
    let numbers = [1..n]
    print (game numbers 1)
```

In the main function, I read the input number `n` and create a list from 1 to n using `let` . The last line calls the function `game` starting from the first move, that's what 1 means in that line and `print` displays the output in the console.


I referred to the lecture notes for  the implementation, especially list comprehensions, recursion, guards, and the `zip` function.


## Submission Result of Functional Implementation

<img width="239" height="68" alt="haskell_result" src="https://github.com/user-attachments/assets/3ab5199c-a9ec-43eb-a2d5-800e1eca764b" />

**E-olymp Result: 97/100**

<img width="437" height="61" alt="haskell_result2" src="https://github.com/user-attachments/assets/e30fb30f-a28c-454f-83c3-1417c210d9e6" />

My Haskell implementation passed 97% of the test cases. All tests passed except Test 29, it exceeded the time limit of 5,000 ms.
I noticed that the Haskell implementation takes more time when processing some of the test cases. I think this is mainly related to the overhead of list processing in Haskell compared to C++. In my solution, the `game` function is called recursively, and a new list is created after each elimination step. I also use `zip` to get the positions of the elements and list comprehensions to filter the list. One difference I noticed is how the two languages store lists in memory. C++ vectors store their elements next to each other in a continuous block of memory, while Haskell lists consist of separate linked elements that point to the next one. Haskell also has some additional overhead from lazy evaluation.

### Comparison of C++ and Haskell Implementations

Both implementations use recursion and list processing to simulate the elimination process. However, their performance was different. My original C++ implementation received 97/100 because of a memory overflow on Test 29. After changing it to modify the existing vector instead of creating a new one, I managed to reduce memory usage and receive 100/100.My Haskell implementation received 97/100 because Test 29 exceeded the time limit. This shows that even though both implementations follow the same logic, the way each language handles lists and memory can affect their performance.


