#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int height[10000], dp[10000], n;

int LDS()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(height[j] >= height[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
    return *max_element(dp, dp + n);
}

int main()
{
    int cases = 1;
    while(scanf("%d", &height[0])){
        if(height[0] == -1)
            break;
        dp[0] = 1;
        n = 1;
        while(scanf("%d", &height[n]), height[n] != -1){
            dp[n] = 1;
            n++;
        }
        if(cases != 1)
            printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n", cases++, LDS());
    }
    return 0;
}
