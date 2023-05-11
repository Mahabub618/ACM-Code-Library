/// Version-1
#include<bits/stdc++.h>
using namespace std;
int n, a[21];
void print()
{
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
void Generate(int i)
{
    if(i==n)
    {
        print();
        return;
    }
    a[i] = 0;
    Generate(i+1);
    a[i] = 1;
    Generate(i+1);
}
int main()
{
    cin >> n;
    Generate(0);
}

/// Version-2
for(int i=0; i<(1<<n); i++)
{
  ll sum = 0;
  for(int j=0; j<n; j++)
  {
    if(i&(1<<j)) sum += v[j];
  }
}

/// M digit of 1's on N

int n, m, a[21];
void print()
{
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
void Generate(int i, int cnt)
{
    if(i==n)
    {
        if(cnt == m) print();
        return;
    }
    a[i] = 0;
    Generate(i+1, cnt);
    a[i] = 1;
    Generate(i+1, cnt+1);
}
int main()
{
    init_code();
    cin >> n >> m;
    Generate(0, 0);
     
return 0;
}
