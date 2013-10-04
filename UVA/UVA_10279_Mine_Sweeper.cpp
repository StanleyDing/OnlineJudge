#include <cstdio>
#include <cstring>
using namespace std;

int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                 {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
char game[11][11], play[11][11];

void start(int n);
char check(int i, int j, int n);

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        getchar();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                scanf("%c", &game[i][j]);
            getchar();
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                scanf("%c", &play[i][j]);
            getchar();
        }

        start(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                printf("%c", play[i][j]);
            printf("\n");
        }

        if(t)
            printf("\n");
    }
    return 0;
}

void start(int n)
{
    char result;
    bool exploded = false;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(play[i][j] == 'x'){
                play[i][j] = result = check(i, j, n);
                if(result == '*')
                    exploded = true;
            }
        }

    if(exploded)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(game[i][j] == '*')
                    play[i][j] = '*';
}

char check(int i, int j, int n)
{
    int bomb = 0, di, dj;
    if(game[i][j] == '*')
        return '*';
    for(int k = 0; k < 8; k++){
        di = i + dir[k][0];
        dj = j + dir[k][1];
        if(di < 0 || di >= n || dj < 0 || dj >= n)
            continue;
        if(game[di][dj] == '*')
            bomb++;
    }
    return '0' + bomb;
}
