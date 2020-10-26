#include <iostream>
using namespace std;

class ubknapsack
{
public:
    int rodcutting(int price[], int piece[], int l, int n)
    {
        int t[n + 1][l + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < l + 1; j++)
                if (i == 0 || j == 0)
                    t[i][j] = 0;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < l + 1; j++)
                if (piece[i - 1] <= j)
                    t[i][j] = max(price[i - 1] + t[i][j - piece[i - 1]], t[i - 1][j]);
                else if (piece[i - 1] > j)
                    t[i][j] = t[i - 1][j];
        }
        return t[n][l];
    }
};

int main()
{
    int piece[] = {1, 2, 3};
    int price[] = {6, 8, 4};
    int n = sizeof(piece) / sizeof(piece[0]);
    int l = 8;
    ubknapsack ob;
    int result = ob.rodcutting(price, piece, l, n);
    cout << result;
}