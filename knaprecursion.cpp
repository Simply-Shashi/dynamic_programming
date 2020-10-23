#include <iostream>
#include <math.h>
using namespace std;

class knapsack
{
public:
    int knap(int val[], int wt[], int w, int n)
    {
        int knapvalue;
        if (w == 0 || n == 0)
            return 0;

        if (wt[n - 1] < w)
        {
            knapvalue = max(val[n - 1] + knap(wt, val, w - wt[n - 1], n - 1), knap(wt, val, w, n - 1));
        }
        else if (wt[n - 1] > w)
            knapvalue = knap(wt, val, w, n - 1);
        return knapvalue;
    }
};

int main()
{
    int wt[] = {23, 19, 52, 12, 50, 43};
    int val[] = {10, 42, 21, 63, 23, 21};
    int n = sizeof(val) / sizeof(val[0]);
    int w = 34;
    knapsack ob;
    cout << ob.knap(val, wt, w, n);
}