// An efficient C++ program to find bit-wise & of all
// numbers from x to y.

/*
Example 1 :
x = 10, y = 20
Result is initially 0.
Position of MSB in x = 3
Position of MSB in y = 4
Since positions are different, return result.

Example 2 :
x = 17, y = 19
Result is initially 0.
Position of MSB in x = 4
Position of MSB in y = 4
Since positions are same, we compute 24.

We add 24 to result. 
Result becomes 16.

We subtract this value from x and y.
New value of x  = x - 24  = 17 - 16 = 1
New value of y  = y - 24  = 19 - 16 = 3

Position of MSB in new x = 1
Position of MSB in new y = 2
Since positions are different, we return result.
*/
// =================== Code ======================//


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Find position of MSB in n. For example if n = 17,
// then position of MSB is 4. If n = 7, value of MSB
// is 2
int msbPos(ll n)
{
	int msb_p = -1;
	while (n)
	{
		n = n>>1;
		msb_p++;
	}
	return msb_p;
}

// Function to find Bit-wise & of all numbers from x
// to y.
ll andOperator(ll x, ll y)
{
	ll res = 0; // Initialize result

	while (x && y)
	{
		// Find positions of MSB in x and y
		int msb_p1 = msbPos(x);
		int msb_p2 = msbPos(y);

		// If positions are not same, return
		if (msb_p1 != msb_p2)
			break;

		// Add 2^msb_p1 to result
		ll msb_val = (1LL << msb_p1);
		res = res + msb_val;

		// subtract 2^msb_p1 from x and y.
		x = x - msb_val;
		y = y - msb_val;
	}

	return res;
}

int main()
{
	ll x = 10, y = 15;
	cout << andOperator(x, y);
	return 0;
}
