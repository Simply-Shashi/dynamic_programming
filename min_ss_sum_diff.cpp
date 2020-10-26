#include <iostream>
#include <vector>
using namespace std;

class min_ss_sum_diff
{
public:
    int subsetsum(int arr[], int sum, int n)
    {
        bool t[n + 1][sum + 1];
        int mn = INT_MAX;
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
                if (arr[i - 1] < j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else if (arr[i - 1] > j)
                    t[i][j] = t[i - 1][j];
            }
        }
        for (int j = 0; j < (sum + 1) / 2; j++)
        {
            if (t[n][j] == true)
                ;
            mn = min(mn, sum - 2 * j);
        }
        return mn;
    }
};

int main()
{
    int arr[] = {1, 2, 4}, sum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    min_ss_sum_diff ob;
    int result = ob.subsetsum(arr, sum, n);
    cout << result;
}