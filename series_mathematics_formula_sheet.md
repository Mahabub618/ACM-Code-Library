# Complete Formula Sheet for Series Mathematics

A compact revision note for semester and competitive examinations.

## 1. Basic Summation Formulas

Let `n` be the number of terms.

| Series | Formula |
|---|---|
| Sum of first `n` natural numbers | \(\displaystyle \frac{n(n+1)}{2}\) |
| Sum of first `n` even numbers | \(\displaystyle n(n+1)\) |
| Sum of first `n` odd numbers | \(\displaystyle n^2\) |
| Sum of squares | \(\displaystyle \frac{n(n+1)(2n+1)}{6}\) |
| Sum of cubes | \(\displaystyle \left[\frac{n(n+1)}{2}\right]^2\) |
| Sum of first `n` multiples of `k` | \(\displaystyle k\frac{n(n+1)}{2}\) |

**Examples**

- \(1+2+3+4+5=\frac{5(6)}{2}=15\)
- \(2+4+6+8+10=5(6)=30\)
- \(1+3+5+7+9=5^2=25\)

## 2. Arithmetic Progression (AP)

An AP is a series where the difference between consecutive terms is constant.

Example: \(2,5,8,11,14,\ldots\)

Common difference:

\[
d=a_2-a_1
\]

| Formula | Expression |
|---|---|
| Common difference | \(d=a_2-a_1\) |
| nth term | \(a_n=a+(n-1)d\) |
| Last term | \(l=a+(n-1)d\) |
| Number of terms | \(\displaystyle n=\frac{l-a}{d}+1\) |
| Sum of n terms | \(\displaystyle S_n=\frac{n}{2}[2a+(n-1)d]\) |
| Sum using first and last term | \(\displaystyle S_n=\frac{n}{2}(a+l)\) |
| Arithmetic mean of `a`, `b` | \(\displaystyle AM=\frac{a+b}{2}\) |

Where:
- `a` = first term
- `d` = common difference
- `n` = number of terms
- `l` = last term

## 3. Geometric Progression (GP)

A GP is a series where each term is obtained by multiplying the previous term by a constant ratio.

Example: \(2,6,18,54,\ldots\)

Common ratio:

\[
r=\frac{a_2}{a_1}
\]

| Formula | Expression |
|---|---|
| Common ratio | \(\displaystyle r=\frac{a_2}{a_1}\) |
| nth term | \(a_n=ar^{n-1}\) |
| Sum of n terms | \(\displaystyle S_n=\frac{a(r^n-1)}{r-1},\ r\ne1\) |
| Alternative sum | \(\displaystyle S_n=\frac{a(1-r^n)}{1-r},\ r\ne1\) |
| When `r = 1` | \(S_n=na\) |
| Infinite GP | \(\displaystyle S_\infty=\frac{a}{1-r},\ |r|<1\) |
| Geometric mean | \(\displaystyle GM=\sqrt{ab}\) |

## 4. Harmonic Progression (HP)

A harmonic progression is a series whose reciprocals form an AP.

Example: \(1,\frac12,\frac13,\frac14,\ldots\)

| Formula | Expression |
|---|---|
| Harmonic mean of `a`, `b` | \(\displaystyle HM=\frac{2ab}{a+b}\) |
| Relationship between AM, GM, HM | \(AM\ge GM\ge HM\) |
| Product relationship | \(GM^2=AM\times HM\) |

For two positive numbers:

\[
AM=\frac{a+b}{2}
\]

\[
GM=\sqrt{ab}
\]

\[
HM=\frac{2ab}{a+b}
\]

## 5. Special Number Series

| Series | Formula |
|---|---|
| \(1+2+\cdots+n\) | \(\displaystyle \frac{n(n+1)}2\) |
| \(1^2+2^2+\cdots+n^2\) | \(\displaystyle \frac{n(n+1)(2n+1)}6\) |
| \(1^3+2^3+\cdots+n^3\) | \(\displaystyle \frac{n^2(n+1)^2}{4}\) |
| \(1^4+2^4+\cdots+n^4\) | \(\displaystyle \frac{n(n+1)(2n+1)(3n^2+3n-1)}{30}\) |
| \(1+3+5+\cdots+(2n-1)\) | \(n^2\) |
| \(2+4+6+\cdots+2n\) | \(n(n+1)\) |
| \(1+4+9+16+\cdots+n^2\) | \(\displaystyle \frac{n(n+1)(2n+1)}6\) |
| \(1+8+27+64+\cdots+n^3\) | \(\displaystyle \frac{n^2(n+1)^2}{4}\) |

## 6. Factorial Series

Factorial means multiplying a number by all positive integers below it.

\[
n!=n(n-1)(n-2)\cdots1
\]

| Number | Factorial |
|---|---|
| \(1!\) | 1 |
| \(2!\) | 2 |
| \(3!\) | 6 |
| \(4!\) | 24 |
| \(5!\) | 120 |
| \(6!\) | 720 |
| \(0!\) | 1 |

Important formulas:

\[
n!=n(n-1)!
\]

\[
\frac{n!}{(n-1)!}=n
\]

\[
\frac{n!}{(n-r)!}=n(n-1)\cdots(n-r+1)
\]

## 7. Fibonacci Series

In a Fibonacci series, every term is the sum of the previous two terms.

\[
F_n=F_{n-1}+F_{n-2}
\]

Starting values:

\[
F_0=0,\qquad F_1=1
\]

Series:

\[
0,1,1,2,3,5,8,13,21,34,\ldots
\]

## 8. Common Number Patterns for Missing-Term Series

| Pattern | Example |
|---|---|
| Addition | 5, 8, 11, 14, 17 |
| Subtraction | 50, 45, 40, 35, 30 |
| Multiplication | 2, 4, 8, 16, 32 |
| Division | 160, 80, 40, 20, 10 |
| Squares | 1, 4, 9, 16, 25, 36 |
| Cubes | 1, 8, 27, 64, 125 |
| Prime numbers | 2, 3, 5, 7, 11, 13 |
| Fibonacci | 1, 1, 2, 3, 5, 8 |
| Alternating series | 2, 10, 4, 20, 6, 30 |
| Increasing difference | 2, 5, 9, 14, 20 |
| Multiplication + addition | 2, 5, 11, 23, 47 |

## 9. First-Difference and Second-Difference Method

Useful when a series does not follow a simple AP or GP.

Example:

\[
2,\ 5,\ 10,\ 17,\ 26,\ ?
\]

First differences:

\[
3,\ 5,\ 7,\ 9
\]

Second differences:

\[
2,\ 2,\ 2
\]

The second difference is constant, so the next first difference is:

\[
9+2=11
\]

Therefore:

\[
26+11=\boxed{37}
\]

## 10. Quick Revision — Must-Memorize Formulas

\[
\boxed{1+2+\cdots+n=\frac{n(n+1)}2}
\]

\[
\boxed{1^2+2^2+\cdots+n^2=\frac{n(n+1)(2n+1)}6}
\]

\[
\boxed{1^3+2^3+\cdots+n^3=\left(\frac{n(n+1)}2\right)^2}
\]

\[
\boxed{a_n=a+(n-1)d}
\]

\[
\boxed{S_n=\frac n2(a+l)}
\]

\[
\boxed{a_n=ar^{n-1}}
\]

\[
\boxed{S_n=\frac{a(r^n-1)}{r-1}}
\]

\[
\boxed{F_n=F_{n-1}+F_{n-2}}
\]

## Exam-Solving Tip

For missing-number series, check in this order:

1. Difference between consecutive terms.
2. Second difference.
3. Multiplication or division.
4. Squares and cubes.
5. Prime numbers.
6. Alternating series.
7. Combination of two operations.

**Remember:** Recognizing the pattern is often more important than memorizing every formula.
