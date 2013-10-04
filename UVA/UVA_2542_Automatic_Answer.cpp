#include <cstdio>

int main()
{
    int t;
    long long n;

    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        n *= (567/9);
        n += 7492;
        n *= (235/47);
        n -= 498;
        n /= 10;
        if(n < 0)
            n = -n;
        printf("%lld\n", n % 10);
    }
    return 0;
}
