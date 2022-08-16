# General
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
O(log2 n) - recursively divide in halves and took one half to process for next iteration (e.g. for (i = n; i > 1; i = i / 2) {} or binary tree) ([https://www.youtube.com/watch?v=M4ubFru2O80])
O(n) - for loop, linear recursion 
O(n^2) - for loop in for loop (linear progression)
O(2^n) - exponential, tree recursion with 2 calls on each iteration (geometric progression)
This measures only the order of dependence of executing time from input, so O(1) - means constant, to actually can be 999, e, π or even e^π,  O(n) - means linear dependence, it actually can be n + 100, 40*n etc.
Space complexity - measure ho much of main memory it will take for algorithm to execute (not exact bytes but dependence on elements count)

Static variable - mean global variable used by all function calls despite the space where it was initialized.

# Recursion
Recursion - function is calling itself again. There are concepts of calling (all that calls before recursive function call) and returning (all that calls after recursive function call) time.
Linear - function recursively call itself only one time
    Tail - if recursive call is last statement in function (can be easily turned into while loop, which is better in terms of space complexity)
    Head - if recursive call is first statement in function (can be turned into while loop without additional variable)
Tree -  function recursively call itself more than one time
Indirect - 2 or more functions call each other in circular fashion. e.g. function A calls B, function B calls A etc.
Nested - when recursive function calls itself with recursive param (e.g. fun(n){ fun(fun(n-1)) } )
There is also term as Excessive recursion - meaning that recursive function calls itself with the same params multiple times. To optimize this we can store calculated values by params and use them when called again with the same params (memoization). 

# Arrays
Variables types:
Scalar - have magnitude, can store 1 value (e.g. int)
Vector - have dimension, can store many values (e.g. int array)
 
Array is a collection of variables of same type.
If we print addresses of the elements of an array we will see that all of them are side by side with interval of sizeof stored value.

Arrays types:
Static - fixed size, in C size have to be set at compile time, in C++ can be set in runtime too (e.g. from user input)
Dynamic - dynamic size, type and size can be set in runtime (can be created only in Heap memory by "malloc"/"new" keyword and accessed by pointer)

2D Array - Array of Arrays, used for matrix

Arrays in compiler:
Compiler have to change variable names to addresses in machine code, but we have addresses only during execution, so how to perform this for arrays? 
To calculate address ov variable in array A[i] compiler use formula Addr(A[i]) = L0 + i * sizeof(data type), and L0 will be updated when the memory of array will be allocated (data binding).
This is also the reason why arrays start from 0, otherwise there will be extra operation for calculating address every time Addr(A[i]) = L0 + (i - 1) * sizeof(data type)

In fact for 2d arrays the memory allocated will be linear, single dimension array, but compiler will allow to access its values by row and column.
For 2d arrays there are 2 type of mapping (row- and column-major), and c/c++ use row-major mapping.
Row-major formula Addr(A[i][j]) = L0 + (i * n + j) * sizeof(data type), where n - number of rows
Row-major formula Addr(A[i][j]) = L0 + (j * m + i) * sizeof(data type), where m - number of columns

Row-major formula for 3-dimension:
A[d1][d2][d3]
Addr(A[i1][i2][i3]) = L0 + [i1*d2*d3 + i2*d3 + i3] * sizeof(data type)
Time complexity is O(n^2), so we can optimise it by using Horner's rule
i3 + d3 * (i2 + i3 * d2), this reduces number of multiplications and complexity to O(n)
So generic formula can be easily retrieved

Array size - for how many items memory os allocated
Array length - how many items are actually present in array

There are 2 methods to search item in array (linear / binary)
Linear - check 1 by 1, time complexity: best - O(1), worst - O(n) 
There are ways to optimize linear search
1. Transposition - move found element for 1 index closer to the head of array
2. Move to front/head - move found element to the head of array (0 index)
Binary - check the middle of sorted list and always split in 2 parts
Condition for binary search is that array should be sorted.
Time - O(log2 n)

