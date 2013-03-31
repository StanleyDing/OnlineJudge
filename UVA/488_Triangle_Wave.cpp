#include <cstdio>

int main()
{
    int cases, a, f;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d%d", &a, &f);
        while(f--){
            for(int i = 1; i <= a; i++){
                for(int j = 1; j <= i; j++)
                    printf("%d", i);
                printf("\n");
            }
            for(int i = a - 1; i > 0; i--){
                for(int j = 1; j <= i; j++)
                    printf("%d", i);
                printf("\n");
            }
            if(f)
                printf("\n");
        }
        if(cases)
            printf("\n");
    }
    return 0;
}
