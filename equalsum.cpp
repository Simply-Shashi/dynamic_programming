#include <iostream>
using namespace std;

class equalsumpartition
{
public:
    bool equalsum(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum = sum + arr[i];
        if (sum % 2 != 0)
            return false;
        else if (sum % 2 == 0)
            return subsetsum(arr, sum / 2, n);
    }
    bool subsetsum(int arr[], int sum, int n)
    {
        bool t[n + 1][sum + 1];
        if (sum == 0 || n == 0)
            return false;
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    t[i][j] = false;
                if (j == 0)
                    t[i][j] = true;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][sum];
    }
};

int main()
{
    int arr[] = {2, 8, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    equalsumpartition ob;
    cout << ob.equalsum(arr, n);
}