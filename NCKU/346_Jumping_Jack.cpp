#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int T, x;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &x);
        if(x < 0)
            x *= -1;
        int sum = 0, i;
        for(i = 1; sum < x || (sum - x) % 2; i++)
            sum += i;
        printf("%d\n", i - 1);
    }
    return 0;
}
