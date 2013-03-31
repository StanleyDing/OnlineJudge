#include <cstdio>
#include <cstring>
#define MAX_DIMENSION 25 + 1

int n, count, cases = 1;
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
char img[MAX_DIMENSION][MAX_DIMENSION];
bool visit[MAX_DIMENSION][MAX_DIMENSION];

void dfs(int row, int col)
{
    if(row < 0 || col < 0 || row == n || col == n || visit[row][col] || img[row][col] == '0')
        return;

    visit[row][col] = true;
    for(int i = 0; i < 8; i++)
        dfs(row + dr[i], col + dc[i]);
}

int main()
{
    while(scanf("%d", &n) != EOF){
        count = 0;
        memset(visit, false, sizeof(visit));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf(" %c", &img[i][j]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(img[i][j] == '1' && !visit[i][j]){
                    count++;
                    dfs(i, j);
                }
            }
        printf("Image number %d contains %d war eagles.\n", cases++, count);
    }
    return 0;
}
