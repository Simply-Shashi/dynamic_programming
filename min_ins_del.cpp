#include <iostream>
using namespace std;

class lcs
{
public:
    int min_ins_del(string x, string y, int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;
        int t[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (x[i - 1] == y[j - 1])
                    t[i][j] = (1 + t[i - 1][j - 1]);
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
        int a = m > n ? m - t[m][n] : n - t[m][n];
        return a;
    }
};

int main()
{
    string x = "heap";
    string y = "pea";
    lcs ob;
    cout << ob.min_ins_del(x, y, x.length(), y.length());
}