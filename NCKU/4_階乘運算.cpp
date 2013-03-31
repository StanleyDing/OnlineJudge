#include <cstdio>

long long int factorial(int);

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
        printf("%lld\n", factorial(n));
    return 0;
}

long long int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    return (n * factorial(n - 1));
}
