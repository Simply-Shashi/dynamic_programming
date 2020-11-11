#include<iostream>
#include<string.h>
using namespace std;

int static t[1000][1000];
class mcm
{
    public:
    bool palindrome(string st,int i,int j)
    {
        while(i<j)
        {
            if(st[i]!=st[j-1])
            return false;
            else 
                i++;
                j--;
        }
        return true;
    }
    int pal_part_optimized(string s,int x,int y)
    {
        if(x>=y)
        return 0;
        if(palindrome(s,x,y)==true)
        return 0;
        if(t[x][y]!=-1)
        return t[x][y];
        int left,right,temp,mn = INT_MAX;
        for(int k=x;k<=y-1;k++)
        {
            if(t[x][k]!=-1)
            left = t[x][k];
            else
            {
                left = pal_part_optimized(s,x,k);
                t[x][k] = left;
            }
            if(t[k+1][y]!=-1)
            right = t[k+1][y];
            else
            {
                right = pal_part_optimized(s,k+1,y);
                t[k+1][y] = right;
            }
            temp = 1 + left + right;
            if(temp<mn)
            mn = temp;
        }
        return t[x][y] = mn;
    }
};

int main()
{
    string s = "nitik";
    memset(t,-1,sizeof(t));
    mcm ob;
    cout<<ob.pal_part_optimized(s,0,s.length());
}