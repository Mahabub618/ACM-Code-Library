// Method 1: Using Division Check (No Extra Dependencies)

bool willMultiplyOverflow(long long a, long long b) {
    if (a == 0 || b == 0) return false;

    if (a > 0) {
        if (b > 0) return a > LLONG_MAX / b;
        else       return b < LLONG_MIN / a;
    } else {
        if (b > 0) return a < LLONG_MIN / b;
        else       return a != 0 && b < LLONG_MAX / a;
    }
}


// Method 2: Using __builtin_mul_overflow (GCC/Clang Only)

#include <iostream>
using namespace std;
int main() {
    long long a, b, result;
    cin >> a >> b;
    
    if (__builtin_mul_overflow(a, b, &result)) {
        cout << "Multiplication will overflow!\n";
    } else {
        cout << "Result: " << result << "\n";
    }
    
    return 0;
}
