#include <cstdio>
#include <cstring>
using namespace std;

int n, dp[91];
bool canStack[91][91];

struct Block{
    int x, y, z;
    void set(int xx, int yy, int zz)
    {
        x = xx;
        y = yy;
        z = zz;
    }
}blocks[91];

void tryStack();
int DP(int x);

int main()
{
    int x, y, z, max, cases = 1;
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &x, &y, &z);
            blocks[i*3].set(x, y, z);
            blocks[i*3+1].set(y, z, x);
            blocks[i*3+2].set(z, x, y);
        }
        tryStack();
        memset(dp, -1, sizeof(dp));

        int max = 0;
        for(int i = 0; i < 3 * n; i++)
            if(DP(i) > max)
                max = DP(i);
        printf("Case %d: maximum height = %d\n", cases++, max);
    }
    return 0;
}

void tryStack()
{
    for(int i = 0; i < 3 * n; i++)
        for(int j = 0; j < 3 * n; j++){
            Block &top = blocks[i], &down = blocks[j];
            //if block[i] can be stacked on block[j], set to true
            canStack[i][j] = ((top.x < down.x && top.y < down.y) || 
                    (top.y < down.x && top.x < down.y));
        }
}

int DP(int x)
{
    if(dp[x] != -1)
        return dp[x];

    int temp = 0;
    for(int i = 0; i < 3 * n; i++)
        if(canStack[i][x] && temp < DP(i))
            temp = DP(i);
    return dp[x] = temp + blocks[x].z;
}
