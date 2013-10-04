#include <cstdio>
#include <cstring>
using namespace std;

int move[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                  {0, 1}, {1, -1}, {1, 0}, {1, 1}};
char grid[105][105];
int n, r, c, count, visited[105][105];

void dfs(int row, int col);

int main()
{
    int row, col;
    scanf("%d", &n);
    getchar(), getchar();
    while(n--){
        r = 0;
        while(1){
            fgets(grid[r], 105, stdin);
            if(grid[r][0] != 'L' && grid[r][0] != 'W')
                break;
            r++;
        }
        c = strlen(grid[0]) - 1;
        while(1){
            count = 0;
            sscanf(grid[r], "%d %d", &row, &col);
            memset(visited, 0, sizeof(visited));
            dfs(row - 1, col - 1);
            printf("%d\n", count);
            if(!fgets(grid[r], 105, stdin))
                break;
            if(grid[r][0] == '\n')
                break;
        }
        if(n)
            printf("\n");
    }
    return 0;
}

void dfs(int row, int col)
{
    if(grid[row][col] == 'L')
        return;
    if(row < 0 || row >= r || col < 0 || col >= c)
        return;
    visited[row][col] = true;
    count++;

    for(int i = 0; i < 8; i++){
        int nr = row + move[i][0];
        int nc = col + move[i][1];
        if(nr < 0 || nr >= r || nc < 0 || nc >= c)
            continue;
        if(grid[nr][nc] == 'W' && !visited[nr][nc])
            dfs(nr, nc);
    }
}
