#include <bits/stdc++.h>

using namespace std;

const int maxn = 300005;

int n, h;

int da[maxn];

bool sol()
{
    for(int i=1; i<=h; i++)
    {
        if(da[i]!=1 && da[i-1]!=1)
            return 0;
    }
    return 1;
}

void left()
{
    printf("0");
    int pl = 1;
    int pr = 1;
    for(int i=1; i<=h; i++)
    {
        for(int j=0; j<da[i]; j++)
            printf(" %d", pl);
        pl = pr + 1;
        pr += da[i];
    }
    puts("");
}

void right()
{
    printf("0");
    int pl = 1;
    int pr = 1;
    for(int i=1; i<=h; i++)
    {
        for(int j=0; j<da[i]; j++)
            printf(" %d", pl + j%(pr-pl+1));
        pl = pr + 1;
        pr += da[i];
    }
    puts("");
}

int main()
{
    cin >> h;
    n = 0;
    for(int i=0; i<=h; i++)
    {
        cin >> da[i];
        n += da[i];
    }
    if(sol())
        puts("perfect");
    else
    {
        puts("ambiguous");
        left();
        right();
    }  
}
