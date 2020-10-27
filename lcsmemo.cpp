#include <iostream>
#include <string.h>
using namespace std;

int static t[101][101];
class lcs
{
public:
    int lcsmemo(string x, string y, int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;
        if (t[m][n] != -1)
            return t[m][n];

        if (x[m - 1] == y[n - 1])
            return t[m][n] = (1 + lcsmemo(x, y, m - 1, n - 1));
        else
            return t[m][n] = max(lcsmemo(x, y, m - 1, n), lcsmemo(x, y, m, n - 1));
    }
};

int main()
{
    string x = "Shashikant";
    string y = "Sharma";
    memset(t, -1, sizeof(t));
    lcs ob;
    cout << ob.lcsmemo(x, y, x.length(), y.length());
}