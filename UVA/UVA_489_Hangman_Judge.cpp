#include <cstdio>
#include <cstring>
using namespace std;

int p[26], g[26];

int main()
{
    int n, goal, right, wrong, length;
    char s[500];
    while(scanf("%d", &n), n != -1){
        memset(p, 0, sizeof(p));
        memset(g, 0, sizeof(g));
        goal = right = wrong = 0;

        scanf("%s", s);
        length = strlen(s);
        for(int i = 0; i < length; i++)
            if(p[s[i]-'a'] == 0){
                p[s[i]-'a'] = 1;
                goal++;
            }

        scanf("%s", s);
        length = strlen(s);
        for(int i = 0; i < length && wrong < 7 && right < goal; i++){
            if(!g[s[i]-'a']){
                if(p[s[i]-'a'])
                    right++;
                else
                    wrong++;
                g[s[i]-'a'] = 1;
            }
        }

        if(right == goal)
            printf("Round %d\nYou win.\n", n);
        else if(wrong == 7)
            printf("Round %d\nYou lose.\n", n);
        else
            printf("Round %d\nYou chickened out.\n", n);
    }
    return 0;
}
