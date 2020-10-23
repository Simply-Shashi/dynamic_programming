#include <iostream>
using namespace std;

bool subsetsum(int arr[], int sum, int n)
{
    bool t[5][12];
    if (sum == 0 || n == 0)
        return false;
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;

            if (arr[i - 1] <= j)
                t[i][j] = t[i][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    return t[5][12];
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n; i++)
        arr[i] += sum;
    if (sum % 2 != 0)
        return false;
    else if (sum % 2 == 0)
        return subsetsum(arr, sum / 2, n);
}