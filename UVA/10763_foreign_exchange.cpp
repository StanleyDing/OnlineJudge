#include <cstdio>
#include <cstdlib>
using namespace std;

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n, i;
    int o[500000], t[500000];
    while(scanf("%d", &n) && n != 0){
        for(i = 0; i < n; i++)
            scanf("%d %d", &o[i], &t[i]);
        qsort(o, n, sizeof(int), compare);
        qsort(t, n, sizeof(int), compare);
        i = 0;
        while(i < n && o[i] == t[i])
            i++;
        if(i == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
