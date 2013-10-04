#include <cstdio>

int main()
{
    int n, k, count = 0;
    int score[55];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &score[i]);
    for(int i = 0; i < n; i++){
        if(score[i] >= score[k-1] && score[i] > 0)
            count++;
        else 
            break;
    }
    printf("%d\n", count);
    return 0;
}
