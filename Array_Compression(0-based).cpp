const int N = 2e5+5;
int L[N], R[N];
void array_compression()
{
    set<int> Set;
    for(int i=1; i<=n; i++)
    {
        cin >> L[i] >> R[i];
        Set.insert(L[i]-1);
        Set.insert(R[i]);
    }
    Set.insert(0);
    Set.insert(n);
    
    map<int, int> Map, key;
    int idx = 0;
    for(auto x: Set)
    {
        Map[x] = idx;
        key[idx] = x;
        ++idx;
    }
    for(int i=1; i<=n; i++)
    {
        L[i] = Map[L[i]-1]+1;
        R[i] = Map[R[i]];
    }
}
// Total distinct number will be at most 8*10^5
