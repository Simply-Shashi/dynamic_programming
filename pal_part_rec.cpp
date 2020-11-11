#include<iostream>
#include<string.h>
using namespace std;

class mcm
{
    public:
    bool is_palindrome(string st,int x,int y)
    {
        if(x==y)
        return true;
        if(x>y)
        return true;
        while(x<y)
        {
            if(st[x]!=st[y-1])
            return false;
            else
            {
                x++;
                y--;
            }
        }
        return true;
    }
    int pal_part_rec(string s,int i,int j)
    {
        if(i>=j)
        return 0;
        if(is_palindrome(s,i,j) == true)
        return 0;
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp = 1 + pal_part_rec(s,i,k) + pal_part_rec(s,k+1,j);
            if(temp<mn)
                mn = temp;
        }
        return mn;
    }
};
int main()
{
    string pal = "abcabcbacdefefd";
    mcm ob;
    cout<<ob.pal_part_rec(pal,0,pal.length());
}