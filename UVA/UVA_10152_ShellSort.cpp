#include <cstdio>
#include <cstring>
using namespace std;

char origin[205][85], target[205][85];

int main()
{
    int t, n, i, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        getchar();
        for(i = 0; i < n; i++){
            fgets(origin[i], 85, stdin);
            origin[i][strlen(origin[i])-1] = '\0';
        }
        for(i = 0; i < n; i++){
            fgets(target[i], 85, stdin);
            target[i][strlen(target[i])-1] = '\0';
        }
        for(i = n - 1, j = n - 1; i >= 0; i--, j--){
            while(j >= 0 && strcmp(target[i], origin[j]))
                j--;
            if(j < 0)
                break;
        }
        for(; i >= 0; i--)
            printf("%s\n", target[i]);
        printf("\n");
    }
    return 0;
}
