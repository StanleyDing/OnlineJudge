#include <cstdio>
#include <cstdlib>

int p[2000000];

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        qsort(p, n, sizeof(int), compare);
        for(int i = 0; i < n - 1; i++)
            printf("%d ", p[i]);
        printf("%d\n", p[n-1]);
    }
    return 0;
}
