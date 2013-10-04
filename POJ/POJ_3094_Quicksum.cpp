#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char s[300];
    while(1){
        int sum = 0;
        fgets(s, 300, stdin);
        if(s[0] == '#')
            break;
        int len = strlen(s) - 1;
        for(int i = 1; i <= len; i++){
            if(s[i-1] == ' ')
                continue;
            sum += (s[i-1] - 'A' + 1) * i;
        }
        printf("%d\n", sum);
    }
    return 0;
}
