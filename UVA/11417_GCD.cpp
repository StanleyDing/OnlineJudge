#include <cstdio>

int GCD(int i, int j)
{
    if(i % j != 0)
        return GCD(j, i % j);
    return j;
}

int main()
{
    int N, G;
    while(scanf("%d", &N) && N != 0){
        G = 0;
        for(int i = 1; i < N; i++)
            for(int j = i + 1; j <= N;j++)
                G += GCD(i, j);
        printf("%d\n", G);
    }
    return 0;
}
