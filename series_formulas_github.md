# All Important Series Formulas

Mathematics formula note for semester and competitive exam revision.

> **GitHub math syntax:** This note uses `$...$` for inline math and `$$...$$` for display math, which GitHub supports.

## 1. Basic Summation Formulas

Let $n$ be the number of terms.

| Series | Formula |
|---|---|
| Sum of first $n$ natural numbers | $\frac{n(n+1)}{2}$ |
| Sum of first $n$ even numbers | $n(n+1)$ |
| Sum of first $n$ odd numbers | $n^2$ |
| Sum of squares | $\frac{n(n+1)(2n+1)}{6}$ |
| Sum of cubes | $\left(\frac{n(n+1)}{2}\right)^2$ |
| Sum of first $n$ multiples of $k$ | $k\frac{n(n+1)}{2}$ |
| Sum of fourth powers | $\frac{n(n+1)(2n+1)(3n^2+3n-1)}{30}$ |

### Examples

- $1+2+3+4+5=\frac{5(6)}{2}=15$
- $2+4+6+8+10=5(6)=30$
- $1+3+5+7+9=5^2=25$

## 2. Arithmetic Progression (AP)

An AP has a constant difference between consecutive terms.

Example: $2,5,8,11,14,\ldots$

Common difference:

$$
d=a_2-a_1
$$

| Formula | Expression |
|---|---|
| Common difference | $d=a_2-a_1$ |
| $n$th term | $a_n=a+(n-1)d$ |
| Last term | $l=a+(n-1)d$ |
| Number of terms | $n=\frac{l-a}{d}+1$ |
| Sum of $n$ terms | $S_n=\frac{n}{2}[2a+(n-1)d]$ |
| Sum using first and last terms | $S_n=\frac{n}{2}(a+l)$ |
| Arithmetic mean of $a,b$ | $AM=\frac{a+b}{2}$ |

**Symbols:** $a$ = first term, $d$ = common difference, $n$ = number of terms, $l$ = last term.

### Inserting arithmetic means

To insert $m$ arithmetic means between $a$ and $b$:

$$
d=\frac{b-a}{m+1}
$$

The means are:

$$
a+d,\ a+2d,\ \ldots,\ a+md
$$

## 3. Geometric Progression (GP)

A GP has a constant ratio between consecutive terms.

Example: $2,6,18,54,\ldots$

Common ratio:

$$
r=\frac{a_2}{a_1}
$$

| Formula | Expression |
|---|---|
| Common ratio | $r=\frac{a_2}{a_1}$ |
| $n$th term | $a_n=ar^{n-1}$ |
| Sum of $n$ terms ($r\ne1$) | $S_n=\frac{a(r^n-1)}{r-1}$ |
| Equivalent sum ($r\ne1$) | $S_n=\frac{a(1-r^n)}{1-r}$ |
| When $r=1$ | $S_n=na$ |
| Infinite GP ($|r|<1$) | $S_\infty=\frac{a}{1-r}$ |
| Geometric mean of positive $a,b$ | $GM=\sqrt{ab}$ |

### Inserting geometric means

To insert $m$ geometric means between positive $a$ and $b$:

$$
r=\left(\frac{b}{a}\right)^{\frac{1}{m+1}}
$$

The means are:

$$
ar,\ ar^2,\ \ldots,\ ar^m
$$

## 4. Harmonic Progression (HP) and Means

An HP is a sequence whose reciprocals form an AP.

Example: $1,\frac12,\frac13,\frac14,\ldots$

| Formula | Expression |
|---|---|
| Harmonic mean of $a,b$ | $HM=\frac{2ab}{a+b}$ |
| Arithmetic mean | $AM=\frac{a+b}{2}$ |
| Geometric mean (positive $a,b$) | $GM=\sqrt{ab}$ |
| Means inequality (positive $a,b$) | $AM\ge GM\ge HM$ |
| Relationship | $GM^2=AM\times HM$ |

## 5. Factorials, Permutations, and Combinations

### Factorial

$$
n!=n(n-1)(n-2)\cdots2\cdot1
$$

$$
0!=1
$$

| Formula | Expression |
|---|---|
| Factorial recurrence | $n!=n(n-1)!$ |
| Factorial ratio | $\frac{n!}{(n-1)!}=n$ |
| Permutation | ${}^nP_r=\frac{n!}{(n-r)!}$ |
| Combination | ${}^nC_r=\frac{n!}{r!(n-r)!}$ |
| Combination symmetry | ${}^nC_r={}^nC_{n-r}$ |
| Pascal identity | ${}^nC_r+{}^nC_{r-1}={} ^{n+1}C_r$ |

### Factorial values

| Number | Value |
|---|---:|
| $0!$ | 1 |
| $1!$ | 1 |
| $2!$ | 2 |
| $3!$ | 6 |
| $4!$ | 24 |
| $5!$ | 120 |
| $6!$ | 720 |

## 6. Fibonacci and Figurative Number Series

### Fibonacci series

Each term is the sum of the previous two terms.

$$
F_n=F_{n-1}+F_{n-2}
$$

Starting values:

$$
F_0=0,\qquad F_1=1
$$

Series:

$$
0,1,1,2,3,5,8,13,21,34,\ldots
$$

### Figurative number formulas

| Sequence | Formula |
|---|---|
| Triangular numbers | $T_n=\frac{n(n+1)}{2}$ |
| Square numbers | $Q_n=n^2$ |
| Cube numbers | $C_n=n^3$ |
| Pentagonal numbers | $P_n=\frac{n(3n-1)}{2}$ |
| Hexagonal numbers | $H_n=n(2n-1)$ |

## 7. Useful Sigma ($\sum$) Identities

| Identity | Formula |
|---|---|
| Sum of a constant | $\sum_{k=1}^{n}c=nc$ |
| Sum of index | $\sum_{k=1}^{n}k=\frac{n(n+1)}{2}$ |
| Sum of squares | $\sum_{k=1}^{n}k^2=\frac{n(n+1)(2n+1)}{6}$ |
| Sum of cubes | $\sum_{k=1}^{n}k^3=\left(\frac{n(n+1)}{2}\right)^2$ |
| Linearity | $\sum(a_k+b_k)=\sum a_k+\sum b_k$ |
| Constant factor | $\sum(ca_k)=c\sum a_k$ |

## 8. First-Difference and Second-Difference Method

Use this method when a series does not follow a simple AP or GP.

**Example:** $2,5,10,17,26,\ ?$

First differences:

$$
3,\ 5,\ 7,\ 9
$$

Second differences:

$$
2,\ 2,\ 2
$$

The second difference is constant. Therefore, the next first difference is:

$$
9+2=11
$$

Next term:

$$
26+11=\boxed{37}
$$

## 9. Common Aptitude Series Patterns

| Pattern | Example |
|---|---|
| Constant addition | $5,8,11,14,17$ (add 3) |
| Constant subtraction | $50,45,40,35,30$ (subtract 5) |
| Multiplication | $2,4,8,16,32$ (multiply by 2) |
| Division | $160,80,40,20,10$ (divide by 2) |
| Squares | $1,4,9,16,25,36$ |
| Cubes | $1,8,27,64,125$ |
| Prime numbers | $2,3,5,7,11,13$ |
| Fibonacci-type | $1,1,2,3,5,8$ |
| Alternating series | $2,10,4,20,6,30$ |
| Increasing differences | $2,5,9,14,20$ (add 3, 4, 5, 6) |
| Multiply then add | $2,5,11,23,47$ (multiply by 2, then add 1) |

## 10. Quick Exam Checklist

For a missing-number series, check in this order:

1. Difference between consecutive terms.
2. Second difference.
3. Multiplication or division.
4. Squares, cubes, and prime numbers.
5. Alternating terms (check odd-position and even-position terms separately).
6. Combination of two operations.

## Must-Memorize Formulas

$$
\boxed{1+2+\cdots+n=\frac{n(n+1)}{2}}
$$

$$
\boxed{1^2+2^2+\cdots+n^2=\frac{n(n+1)(2n+1)}{6}}
$$

$$
\boxed{1^3+2^3+\cdots+n^3=\left(\frac{n(n+1)}{2}\right)^2}
$$

$$
\boxed{a_n=a+(n-1)d}
$$

$$
\boxed{S_n=\frac{n(a+l)}{2}}
$$

$$
\boxed{a_n=ar^{n-1}}
$$

$$
\boxed{S_n=\frac{a(r^n-1)}{r-1}\quad(r\ne1)}
$$

$$
\boxed{F_n=F_{n-1}+F_{n-2}}
$$

---

**Notation:** $a$ = first term, $d$ = common difference, $r$ = common ratio, $n$ = number of terms, $l$ = last term, $S_n$ = sum of $n$ terms.
