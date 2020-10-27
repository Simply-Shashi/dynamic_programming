#include <iostream>
using namespace std;

class coinchange
{
public:
    int coin(int arr[], int sum, int n)
    {
        int t[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    t[i][j] = 0;
                if (j == 0)
                    t[i][j] = 1;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
                if (arr[i - 1] <= j)
                    t[i][j] = t[i][j - arr[i - 1]] + t[i - 1][j];
                else if (arr[i - 1] > j)
                    t[i][j] = t[i - 1][j];
        }
        return t[n][sum];
    }
};

int main()
{
    int arr[] = {1, 2, 3}, sum;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter the sum to be found" << endl;
    cin >> sum;
    coinchange ob;
    cout << ob.coin(arr, sum, n);
}