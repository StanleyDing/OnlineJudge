#include <cstdio>
#include <cstdlib>

int cow[10000];

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int N;
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i++)
            scanf("%d", &cow[i]);
        qsort(cow, N, sizeof(int), compare);
        printf("%d\n", cow[N/2]);
    }
    return 0;
}
