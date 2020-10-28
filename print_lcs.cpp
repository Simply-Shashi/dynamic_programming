#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

class lcs
{
public:
    string print_lcs(string x, string y, int m, int n)
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
        int i = m, j = n;
        string s;
        while (i > 0 && j > 0)
        {
            if (x[i - 1] == y[j - 1])
            {
                s.push_back(x[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (t[i - 1][j] > t[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    string x = "Shashikant";
    string y = "Sharma";
    lcs ob;
    cout << ob.print_lcs(x, y, x.length(), y.length());
}