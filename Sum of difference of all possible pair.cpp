long long AllPairSum(int arr[], int n)
{
    long long sum = 0, bad = 0;
    for(int i=0; i<n; i++)
    {
        sum += (1LL*i*arr[i])-bad;
        bad += arr[i];
    }
    return sum;
}
