#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s[15], ans[15];
bool used[15];
int slen;

void backtrack(int ansLength);

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++){
        memset(used, 0, sizeof(used));
        memset(ans, 0, sizeof(ans));
        scanf("%s", s);
        slen = strlen(s);
        sort(s, s + slen);
        backtrack(0);
        printf("\n");
    }
    return 0;
}

void backtrack(int ansLength)
{
    char prevChar = 0;
    int i = 0;
    if(ansLength == slen){
        printf("%s\n", ans);
        return;
    }
    while(used[i])
        i++;
    for(; i < slen; i++){
        if(s[i] == prevChar || used[i])
            continue;
        prevChar = s[i];
        ans[ansLength] = s[i];
        used[i] = true;
        backtrack(ansLength + 1);
        used[i] = false;
    }
}
