#include <cstdio>

int f91(int x);

int main()
{
    int x;
    while(scanf("%d", &x) && x != 0)
        printf("f91(%d) = %d\n", x, f91(x));
    return 0;
}

int f91(int x)
{
    if(x <= 100)
        return f91(f91(x + 11));
    else if(x > 100)
        return x - 10;
}
