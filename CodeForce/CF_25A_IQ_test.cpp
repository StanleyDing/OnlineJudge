#include <cstdio>

int main()
{
    int n, count = 0;
    int num[105];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for(int i = 0; i < 3; i++){
        if(num[i] % 2 == 0)
            count++;
    }
    if(count >= 2){
        for(int i = 0; i < n; i++)
            if(num[i] % 2 == 1)
                printf("%d\n", i + 1);
    }
    else{
        for(int i = 0; i < n; i++)
            if(num[i] % 2 == 0)
                printf("%d\n", i + 1);
    }
    return 0;
}
