#include <iostream>
#include <string.h>
using namespace std;

class lcs
{
public:
    int lcsrec(string x, string y, int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;

        if (x[m - 1] == y[n - 1])
            return (1 + lcsrec(x, y, m - 1, n - 1));
        else
            return max(lcsrec(x, y, m - 1, n), lcsrec(x, y, m, n - 1));
    }
};

int main()
{
    string x = "Shashikant";
    string y = "Sharma";
    int m = x.size();
    int n = y.size();
    lcs ob;
    cout << ob.lcsrec(x, y, m, n);
}