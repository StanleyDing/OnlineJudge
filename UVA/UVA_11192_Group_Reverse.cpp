#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n, g;
    char s[105];

    while(scanf("%d", &n), n){
        scanf("%s", s);
        g = strlen(s) / n;
        for(int i = 1; i <= n; i++)
            for(int j = i * g - 1; j >= (i-1) * g; j--)
                printf("%c", s[j]);
        printf("\n");
    }
    return 0;
}
