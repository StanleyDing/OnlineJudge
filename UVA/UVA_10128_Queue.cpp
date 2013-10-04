#include <cstdio>

long long dp[20][20][20];

int main()
{
    int T, i, j, k;
    dp[1][1][1] = 1;
    for(i = 2; i <=13; i++){
        for(j = 1; j <= i; j++){
            for(k = 1; k <= i; k++){
                dp[i][j][k] = dp[i-1][j][k] * (i-2) + dp[i-1][j-1][k] + dp[i-1][j][k-1];
            }
        }
    }
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &i, &j, &k);
        printf("%lld\n", dp[i][j][k]);
    }
    return 0;
}
