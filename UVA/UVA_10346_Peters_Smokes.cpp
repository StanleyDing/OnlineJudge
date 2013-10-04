#include <cstdio>
using namespace std;

int main()
{
    int n, k, remain, ans;
    while(scanf("%d %d", &n, &k) != EOF){
        remain = ans = 0;
        for(int i = n; i > 0 || remain >= k; i /= k){
            i += remain / k;
            remain %= k;
            ans += i;
            remain += i % k;
        }
        printf("%d\n", ans);
    }
    return 0;
}
