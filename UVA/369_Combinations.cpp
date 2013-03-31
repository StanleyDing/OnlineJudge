#include <cstdio>
using namespace std;

long long int result[101][101] = {0};

long long int c(int N, int M);

int main()
{
    int N, M;
    while(scanf("%d%d", &N, &M), N || M){
        printf("%d things taken %d at a time is %lld exactly.\n", N, M, c(N, M));
    }
    return 0;
}

long long int c(int N, int M)
{
    if(N == M || M == 0)
        return result[N][M] = 1;
    if(result[N][M])
        return result[N][M];
    if(result[N][N-M])
        return result[N][N-M];
    return result[N][M] = c(N - 1, M - 1) + c(N - 1, M);
}
