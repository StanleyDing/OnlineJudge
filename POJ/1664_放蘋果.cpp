#include <cstdio>

int f(int, int);

int main()
{
    int t, M, N;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &M, &N);
        printf("%d\n", f(M, N));
    }
    return 0;
}

int f(int M, int N)
{
    if(M == 1 || N == 1 || M == 0)
        return 1;
    if(M >= N)
        return f(M, N - 1) + f(M - N, N);
    else if(M < N)
        return f(M, M);
}
