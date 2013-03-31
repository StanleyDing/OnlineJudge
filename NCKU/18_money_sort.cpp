#include <cstdio>
#include <cstdlib>

int compare(const void *elem1, const void *elem2);
int accounts[100000];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        for(int i = 0; i < n; i++)
            scanf("%d", &accounts[i]);
        qsort(accounts, n, sizeof(int), compare);
        for(int i = 0; i < n - 1; i++)
            printf("%d ", accounts[i]);
        printf("%d\n", accounts[n-1]);
    }
    return 0;
}

int compare(const void *elem1, const void *elem2)
{
    return (*(int*)elem1 - *(int*)elem2);
}
