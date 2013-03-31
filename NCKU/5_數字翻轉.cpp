#include <cstdio>
#include <cstring>

char s[10];

int main()
{
    while(scanf("%s", s) != EOF){
        int i = strlen(s) - 1;
        while(i >= 0 && s[i--] == '0');
        for(++i; i >= 0; i--){
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}
