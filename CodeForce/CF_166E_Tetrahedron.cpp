#include <cstdio>
#define MOD 1000000007

int main()
{
    long long n, toABC, toD, nABC, nD;

    toABC = 0;
    toD = 1;

    scanf("%lld", &n);

    for(int i = 0; i < n; i++){
        nD = 3 * toABC % MOD;
        nABC = (2 * toABC + toD) % MOD;
        toABC = nABC, toD = nD;
    }

    printf("%lld\n", nD);
    return 0;
}
