Maim memory structure (RAM): Code segment (compiled programs here) + Stack (all active function's parameters and local variables here) + Heap (dynamically allocated variables here)

Data structures can be categorized as physical and logical.
Physical (Array, Linked list) define how memory is organized and allocated (they hold the value). Array for known size, linked list for dynamic length.
Logical (Stack, Queues, Trees, Graph, Hash Table) implemented by use/combination of physical data structures and created to optimise search/sorting/filtering of data. 

ADT - Abstract Data Type 
Data Type (e.g. int)
1. Representation of data (e.g. for int we take 2 bytes, 1 bit for sign and 15 bit for value)
2. Operations on data (e.g. for int operations are +, -, *, /, %, ++, --)
Abstract mean hide internal implementation.
In OOP creating class we also create ADT.

Time and Space complexity
Time complexity - measure how much time it will take at most for algorithm to execute. e.g. O(n), where O means Order(degree of polynomial).  
O(1) - constant
O(n) - for loop, linear recursion 
O(n^2) - for loop in for loop (linear progression)
O(log2 n) - recursively divide in halves and took one half to process for next iteration (e.g. for (i = n; i > 1; i = i / 2) {} or binary tree)
O(2^n) - exponential, tree recursion with 2 calls on each iteration (geometric progression)
Space complexity - measure ho much of main memory it will take for algorithm to execute (not exact bytes but dependence on elements count)

Static variable - mean global variable used by all function calls despite the space where it was initialized.

Recursion - function is calling itself again. There are concepts of calling (all that calls before recursive function call) and returning (all that calls after recursive function call) time.
Linear - function recursively call itself only one time
    Tail - if recursive call is last statement in function (can be easily turned into while loop, which is better in terms of space complexity)
    Head - if recursive call is first statement in function (can be turned into while loop without additional variable)
Tree -  function recursively call itself more than one time
Indirect - 2 or more functions call each other in circular fashion. e.g. function A calls B, function B calls A etc.
Nested - when recursive function calls itself with recursive param (e.g. fun(n){ fun(fun(n-1)) } )
There is also term as Excessive recursion - meaning that recursive function calls itself with the same params multiple times. To optimize this we can store calculated values by params and use them when called again with the same params (memoization). 

 