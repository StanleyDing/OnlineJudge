#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int coinType[6] = {5, 10, 20, 50, 100, 200};
int numCoin[6], ways[705], change[205];

void Limited()
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < numCoin[i]; j++)
            for(int k = 700; k >= coinType[i]; k -= 5)
                if(k - coinType[i] == 0 || ways[k-coinType[i]] != 0)
                    ways[k] = ways[k-coinType[i]] + 1;
}

void Unlimited()
{
    for(int i = 0; i < 6; i++)
        for(int j = coinType[i]; j <= 200; j += 5)
            change[j] = change[j-coinType[i]] + 1;
}

int main()
{
    int x, y, z, target, ans;
    Unlimited();
    while(1){
        for(int i = 0; i < 6; i++)
            scanf("%d", &numCoin[i]);
        if(count(numCoin, numCoin + 6, 0) == 6)
            break;
        memset(ways, 0, sizeof(ways));
        y = 0;
        scanf("%d.%d", &x, &y);
        while(getchar() != '\n');
        target = 100 * x + y;
        Limited();

        ans = 50000;
        for(int i = target; i <= 700 && i - target <= 200; i += 5)
            if(ways[i] != 0){
                //ans = min(ans, ways[i] + change[i - target]);
                if(ans > ways[i] + change[i-target]){
                    ans = ways[i] + change[i-target];
                    x = i, y = i - target;
                }
            }
        printf("%3d\n", ans);
        //printf("%d %d %d %d T:%d\n", x, y, ways[x], change[y], target);
    }
    return 0;
}
