long long SubArraySum(int arr[], int n)
{
    long long sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += (arr[i]*(i+1)*(n-i));
    }
    return sum;
}
