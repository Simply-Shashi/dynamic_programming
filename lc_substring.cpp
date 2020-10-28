#include <bits/stdc++.h>
using namespace std;

class lcs
{
public:
    int count = 0;
    int lc_substring(string x, string y, int m, int n)
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
                {
                    t[i][j] = (1 + t[i - 1][j - 1]);
                    count = max(count, t[i][j]);
                }
                else
                    t[i][j] = 0;
            }
        }
        return count;
    }
};

int main()
{
    string x = "abc";
    string y = "ab";
    lcs ob;
    cout << ob.lc_substring(x, y, x.length(), y.length());
}