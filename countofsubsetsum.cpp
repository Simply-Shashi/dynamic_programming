#include <iostream>
using namespace std;

class countofss
{
public:
    int subsetsum(int arr[], int sum, int n)
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
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
                else if (arr[i - 1] > j)
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][sum];
    }
};

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum;
    cout << "Enter the subset to be found" << endl;
    cin >> sum;
    countofss ob;
    int result = ob.subsetsum(arr, sum, n);
    cout << result;
}