#include <cstdio>
#include <cstring>
using namespace std;

int dir[6];

void roll(char);

int main()
{
    int n;
    char s[10];
    while(scanf("%d", &n), n){
        dir[0] = 1, dir[1] = 2, dir[2] = 3;
        dir[3] = 6, dir[4] = 5, dir[5] = 4;
        while(n--){
            scanf("%s", s);
            roll(s[0]);
        }
        printf("%d\n", dir[0]);
    }
    return 0;
}

void roll(char c)
{
    int temp;

    if(c == 'n'){
        temp = dir[0];
        dir[0] = dir[4];
        dir[4] = dir[3];
        dir[3] = dir[1];
        dir[1] = temp;
    }
    else if(c == 's'){
        temp = dir[0];
        dir[0] = dir[1];
        dir[1] = dir[3];
        dir[3] = dir[4];
        dir[4] = temp;
    }
    else if(c == 'w'){
        temp = dir[0];
        dir[0] = dir[5];
        dir[5] = dir[3];
        dir[3] = dir[2];
        dir[2] = temp;
    }
    else{
        temp = dir[0];
        dir[0] = dir[2];
        dir[2] = dir[3];
        dir[3] = dir[5];
        dir[5] = temp;
    }
}
