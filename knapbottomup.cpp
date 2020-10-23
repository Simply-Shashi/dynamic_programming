#include <iostream>
#include <math.h>
using namespace std;

class knapsack
{
public:
    int Knap(int val[], int wt[], int W, int n)
    {
        int K[n + 1][W + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i == 0 || j == 0)
                    K[i][j] = 0;
                else if (wt[i - 1] <= j)
                    K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
                else
                    K[i][j] = K[i - 1][j];
            }
        }
        return K[n][W];
    }
};

int main()
{
    int val[] = {10, 15, 40};
    int wt[] = {1, 2, 3};
    int n = sizeof(val) / sizeof(val[0]);
    int W = 6;
    knapsack ob;
    cout << ob.Knap(val, wt, W, n);
}