#include <iostream>
using namespace std;

int mcm(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int pseudo = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (pseudo < mn)
        {
            mn = pseudo;
        }
    }
    return mn;
}

int main()
{
    int arr[] = {5, 4, 8, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = mcm(arr, 1, n - 1);
    cout << result;
}