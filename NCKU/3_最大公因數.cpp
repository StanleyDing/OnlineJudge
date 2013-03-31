#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int, int);

int main()
{
    int x, y;
    while(scanf("%d %d", &x, &y) != EOF)
        printf("%d\n", gcd(x, y));
    return 0;
}

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    if(a < b)
         return gcd(b % a, a);
    else
        return gcd(b, a % b);
}
