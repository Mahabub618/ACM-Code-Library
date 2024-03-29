vector<int> kmp(string &s)
{
    int n = (int) s.length();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1; i<n; i++)
    {
        int j = pi[i-1];
        while(j > 0 and s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}
