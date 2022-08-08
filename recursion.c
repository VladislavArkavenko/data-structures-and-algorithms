#include <stdio.h>

// LINEAR TAIL RECURSION
// Time - O(n)
// Space - O(n)
// Output - 3, 2, 1
void linearTailRecursion(int n)
{
    if(n > 0)
    {
        printf("%d ", n);
        linearTailRecursion(n - 1);
    }
}
// Rewritten in while loop
// Time - O(n)
// Space - O(1)
// Output - 3, 2, 1
void linearTailRecursionToLoop(int n)
{
    while(n > 0)
    {
        printf("%d ", n);
        n--;
    }
}

// LINEAR HEAD RECURSION
// Time - O(n)
// Space - O(n)
// Output - 1, 2, 3
void linearHeadRecursion(int n)
{
    if(n > 0)
    {
        linearHeadRecursion(n - 1);
        printf("%d ", n);
    }
}
// Rewritten in while loop
// Time - O(n)
// Space - O(1)
// Output - 1, 2, 3
void linearHeadRecursionToLoop(int n)
{
    int i = 1;
    while(i < n)
    {
        printf("%d ", i);
        i++;
    }
}

// TREE RECURSION
// Time - O(2^n)
// Space - O(n)
// Output - 3, 2, 1, 1, 2, 1, 1
void treeRecursion(int n)
{
    if(n > 0)
    {
        printf("%d ", n);
        treeRecursion(n - 1);
        treeRecursion(n - 1);
    }
}

// INDIRECT RECURSION
// Time - O(n)
// Space - O(n)
// Output - 3, 2, 1
void indirectRecursionFunctionA(int n);
void indirectRecursionFunctionB(int n);

void indirectRecursionFunctionA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        indirectRecursionFunctionB(n - 1);
    }
}
void indirectRecursionFunctionB(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        indirectRecursionFunctionA(n/2);
    }
}

// NESTED RECURSION
// Time - O(n)
// Space - O(n)
// Output - 3, 13, 8, 18, 13

int nestedRecursion(int n)
{
    printf("%d ", n);
    if (n > 10)
        return n - 5;
    return nestedRecursion(nestedRecursion(n+10));
}

// USE CASES
// Sum of natural numbers (still formula for arithmetic progression is preferred)
int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n-1);
}

// Factorial of a number
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

// Exponent/Power of number m^n
int powerSlow(int m, int n)
{
    if (n == 0)
        return 1;
    return m * powerSlow(m, n-1);
}
int powerFast(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0) // is even
        return powerFast(m * m, n / 2);
    return m * powerFast(m * m, (n - 1) / 2);
}

// Taylor series for e^x function = 1 + (x / 1!) + (x^2/2!) + (x^3/3!) + ... + (x^n/n!), where n - number of terms (accuracy cof)
// Taylor series used in calculus to approximate different functions near some input.
// It takes non-polynomial functions and find polynomials that approximate them, because they are much easier to deal with: compute/find derivatives etc.).
// Details: https://www.youtube.com/watch?v=3d6DsjIBzJ4
double calcTaylorSeries(int x, int n)
{
    static double p = 1, f = 1; // p is accumulative value for Powers of x, f is accumulative value for Factorial of n
    double r;
    if (n == 0)
        return 1;
    r = calcTaylorSeries(x, n - 1);
    p = p * x;
    f = f * n;
    return r + (p / f);
}
// To reduce the number of multiplications we can rewrite formula using Horner's rule: e^x = 1 + x/1 * (1 + x/2 * (1 + x/3 * (1 * x/4 * 1)))
double calcTaylorSeriesOptimised(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return s;
    s = 1 + x * s / n; // it's not (x / n) * s because x and n are both int and in order to get double after division it's better to multiply x by s first to convert result into double
    return calcTaylorSeriesOptimised(x, n - 1);
}

// Fibonacci sequence (golden ration)
// 0, 1, 1, 2, 3, 5, 8, 13 ..., (n - 2) + (n - 1)
// Time - O(2^n)
int calcFibonacciSlow(int n)
{
    if (n <= 1) // 0, 1
        return n;
    return calcFibonacciSlow(n - 2) + calcFibonacciSlow(n - 1);
}
// Time - O(n)
int cachedValues[10];
int calcFibonacciFast(int n)
{
    if (n <= 1) // 0, 1
    {
        cachedValues[n] = n;
        return n;
    } else  {
        if (cachedValues[n-2] == -1)
            cachedValues[n-2] = calcFibonacciFast(n - 2);
        if (cachedValues[n-1] == -1)
            cachedValues[n-1] = calcFibonacciFast(n - 1);
        return cachedValues[n-2] + cachedValues[n-1];
    }
}
// Combination formula C(n, r) = n! / (r! * (n - r)!)
// Used to find all possible variations of values (consisting of r terms) from a set (consisting of n terms) without counting (e.g. 123 = 132 = 321 = ...)
// Time - O(n)
int calcCombination(int n, int r)
{
    int num = factorial(n);
    int den = factorial(r) * factorial(n - r);

    return num / den;
}
// Using pascal triangle
int calcCombinationRecursive(int n, int r) {
    if (n == r || r == 0)
        return 1;
    return calcCombinationRecursive(n - 1, r - 1) + calcCombinationRecursive(n - 1, r);
}

// Tower of Hanoi
// Time - O(2^n)
void toh(int n, int A, int B, int C)
{
    if (n > 0)
    {
        toh(n-1, A, C, B);
        printf("from %d to %d\n", A, C);
        toh(n-1, B, A, C);
    }
}

int main() {
    int x = 3;

//    linearTailRecursion(x);
//    linearTailRecursionToLoop(x);
//    linearHeadRecursion(x);
//    linearHeadRecursionToLoop(x);
//    treeRecursion(x);
//    indirectRecursionFunctionA(x);
//    nestedRecursion(x);
//    toh(1, 1, 2, 3);
    return 0;
}
