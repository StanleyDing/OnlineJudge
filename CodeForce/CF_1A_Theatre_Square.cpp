#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    long long m, n, a, x, y;
    scanf("%lld %lld %lld", &m, &n, &a);

    x = m / a;
    y = n / a;

    if(x * a < m)
        x++;
    if(y * a < n)
        y++;

    printf("%lld\n", x * y);
    return 0;
}
