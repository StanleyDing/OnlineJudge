#include <cstdio>

int num[10000];

int main()
{
    int m, n;

    scanf("%d %d", &n, &m);

    while(n--){
        int j = 0, same = 0, temp;
        for(int i = 0; i < m; i++)
            scanf("%d", &num[i]);

        for(int i = 0; i < m; i++){
            scanf("%d", &temp);
            if(temp < num[j])
                continue;
            while(j < m && num[j] < temp)
                j++;
            if(j < m && temp == num[j])
                same++;
        }
        printf("%d\n", same);
    }
    return 0;
}
