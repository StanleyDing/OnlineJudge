#include <cstdio>

int main()
{
    int bx, by, x, y, n;
    while(scanf("%d", &n), n){
        scanf("%d%d", &bx, &by);
        while(n--){
            scanf("%d%d", &x, &y);
            if(x == bx || y == by)
                printf("divisa\n");
            else if(x > bx){
                if(y > by)
                    printf("NE\n");
                else
                    printf("SE\n");
            }
            else{
                if(y > by)
                    printf("NO\n");
                else
                    printf("SO\n");
            }
        }
    }
    return 0;
}
