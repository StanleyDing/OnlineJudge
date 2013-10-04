#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char s[55];

    while(scanf("%s", s)){
        if(s[0] == '#')
            break;
        if(next_permutation(s, s + strlen(s)))
            printf("%s\n", s);
        else
            printf("No Successor\n");
    }
    return 0;
}
