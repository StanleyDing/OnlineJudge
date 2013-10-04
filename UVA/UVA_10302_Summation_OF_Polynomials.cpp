#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    long long x;
    while(scanf("%lld", &x) != EOF){
        printf("%lld\n", x * x * (x + 1) * (x + 1) / 4);
    }
    return 0;
}
