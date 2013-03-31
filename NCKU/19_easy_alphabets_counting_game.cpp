#include <cstdio>
#include <cstring>

int main()
{
    char str[100000];
    char c;
    int count = 0;

    while(scanf("%s%c", str, &c) != EOF){
        if((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <='z'))
            count += strlen(str);
        if(c != '\n')
            continue;
        else{
            printf("%d\n", count);
            count = 0;
        }
    }
    return 0;
}
