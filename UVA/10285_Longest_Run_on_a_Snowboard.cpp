#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N, R, C;
int board[105][105], p[105][105];
bool visited[105][105];
int m[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bt(int r, int c);
bool isValid(int r, int c);

int main()
{
    char name[100];

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int ans = 0;
        memset(board, 0, sizeof(board));
        memset(p, 0, sizeof(p));
        memset(visited, 0, sizeof(visited));
        scanf("%s %d %d", name, &R, &C);
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                scanf("%d", &board[i][j]);
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                ans = max(ans, bt(i, j));
        printf("%s: %d\n", name, ans + 1);
    }
}

int bt(int r, int c)
{
    if(visited[r][c] == true)
        return p[r][c];
    for(int i = 0; i < 4; i++){
        if(isValid(r + m[i][0], c + m[i][1])){
            if(board[r][c] > board[r+m[i][0]][c+m[i][1]])
                p[r][c] = max(p[r][c], bt(r + m[i][0], c + m[i][1]) + 1);
        }
    }
    visited[r][c] = true;
    return p[r][c];
}

bool isValid(int r, int c)
{
    if(r >= 0 && r < R && c >= 0 && c < C)
        return true;
    return false;
}
