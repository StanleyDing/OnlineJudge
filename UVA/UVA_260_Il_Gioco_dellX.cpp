#include <cstdio>
#include <cstring>
using namespace std;

char board[205][205];
bool visited[205][205], white_win;
int move[6][2] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};

void dfs(int r, int c, int n);

int main()
{
    int n, cases = 1;
    while(scanf("%d", &n), n){
        memset(visited, 0, sizeof(visited));
        white_win = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf(" %c", &board[i][j]);
        for(int i = 0; i < n; i++){
            dfs(i, 0, n);
        }
        if(white_win)
            printf("%d W\n", cases++);
        else
            printf("%d B\n", cases++);
    }
}

void dfs(int r, int c, int n)
{
    if(c == n - 1)
        white_win = true;
    visited[r][c] = true;

    for(int i = 0; i < 6 && !white_win; i++){
        int nr = r + move[i][0];
        int nc = c + move[i][1];

        if(nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;
        if(board[nr][nc] == 'w' && !visited[nr][nc]){
            dfs(nr, nc, n);
        }
    }
}
