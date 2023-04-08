#include<bits/stdc++.h>
using namespace std;

// finds where f(x) is minimum
/* double f(double x)
{
    
}*/
int main()
{
    double lo = 0, hi = 1e18;
    for(int itr = 0; itr < 100; itr++)
    {
        double m1 = (lo+lo+hi)/3.0, m2 = (lo+hi+hi)/3.0;
        if(f(m1) > f(m2)) lo = m1;
        else hi = m2;
    }
    cout << f(lo) << endl;
}
