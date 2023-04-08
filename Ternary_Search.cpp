#include<bits/stdc++.h>
using namespace std;

// finds where f(x) is minimum
double lo = 0, hi = 1e18;
for(int itr = 0; itr < 100; itr++)
{
    double m1 = (lo+lo+hi)/3.0, m2 = (lo+hi+hi)/3.0;
    if(f(m1) > f(m2)) lo = m1;
    else hi = m2;
 }
 cout << f(lo) << endl;

// =========== Version-2 ==========//

ll lo = 0, hi = 1e18;
double ans = 1e18;
while(lo <= hi)
{
    double m1 = lo+(hi-lo)/3.0, m2 = hi-(hi-lo)/3.0;
    ans = min({ans, f(m1), f(m2)});
    if(f(m2) > f(m1)) hi = m2-1;
    else lo = m1+1;
  }
  cout << ans << endl;
}
