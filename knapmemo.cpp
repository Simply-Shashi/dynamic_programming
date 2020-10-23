#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;

int tab[11][11];
class knapsack
{
public:
    int knap(int wt[], int val[], int w, int n)
    {
        memset(tab, -1, sizeof(tab));
        if (w == 0 || n == 0)
            return 0;
        if (tab[n][w] != -1)
            return tab[n][w];
        if (wt[n - 1] <= w)
        {
            return tab[n][w] = max(val[n - 1] + knap(wt, val, w - wt[n - 1], n - 1), knap(wt, val, w, n - 1));
        }
        else if (wt[n - 1] > w)
        {
            return tab[n][w] = knap(wt, val, w, n - 1);
        }
        return tab[n][w];
    }
};
int main()
{
    int wt[] = {12, 9, 13, 2, 8, 5};
    int val[] = {4, 12, 22, 15, 1, 7};
    int n = sizeof(val) / sizeof(val[0]);
    int w = 15;
    knapsack ob;
    cout << ob.knap(wt, val, w, n);
}