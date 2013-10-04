#include <cstdio>

int main()
{
    int n, m, a, b, c;
    long long t;

    scanf("%d", &n);
    while(n--){
        t = 0;
        scanf("%d", &m);
        while(m--){
            scanf("%d%d%d", &a, &b, &c);
            t += a * c;
        }
        printf("%lld\n", t);
    }
    return 0;
}
