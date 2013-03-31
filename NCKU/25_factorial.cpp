//Compute the trailing zeros of n!
#include <cstdio>

int Z(int n)
{
    int fives = 0;
    for(int i = 5; i <= n; i *= 5)
        fives += n / i;
    return fives;
}

int main()
{
    int T, N;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &N);
        printf("%d\n", Z(N));
    }
    return 0;
}
