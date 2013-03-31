//bfs
#include <cstdio>
#include <queue>
#define MAX_DIMENSION 35
using namespace std;

int L, R, C, start_L, start_R, start_C;
struct POSITION{
    int L;
    int R;
    int C;
    int step;
}cur, next;

int bfs(char maze[][MAX_DIMENSION][MAX_DIMENSION], bool visited[][MAX_DIMENSION][MAX_DIMENSION]);

int main()
{
    int ans;
    while(scanf("%d %d %d", &L, &R, &C), L || R || C){
        bool visited[MAX_DIMENSION][MAX_DIMENSION][MAX_DIMENSION] = {0};
        char maze[MAX_DIMENSION][MAX_DIMENSION][MAX_DIMENSION] = {0};
        for(int i = 0; i < L; i++)
            for(int j = 0; j < R; j++)
                for(int k = 0; k < C; k++){
                    scanf(" %c", &maze[i][j][k]);
                    if(maze[i][j][k] == 'S'){
                        start_L = i;
                        start_R = j;
                        start_C = k;
                    }
                    else if(maze[i][j][k] == '#')
                        visited[i][j][k] = true;
                }
        ans = bfs(maze, visited);
        if(ans)
            printf("Escaped in %d minute(s).\n", ans);
        else
            printf("Trapped!\n");
    }
    return 0;
}

int bfs(char maze[][MAX_DIMENSION][MAX_DIMENSION], bool visited[][MAX_DIMENSION][MAX_DIMENSION])
{
    queue<POSITION> que;

    visited[start_L][start_R][start_C] = true;
    cur.L = start_L, cur.R = start_R, cur.C = start_C, cur.step = 0;
    que.push(cur);

    while(!que.empty()){
        cur = que.front();
        que.pop();
        if(maze[cur.L][cur.R][cur.C] == 'E')
            return cur.step;
        if(cur.L > 0 && !visited[cur.L-1][cur.R][cur.C]){
            next.L = cur.L - 1, next.R = cur.R, next.C = cur.C, next.step = cur.step + 1;
            visited[next.L][next.R][next.C] = true;
            que.push(next);
        }
        if(cur.R > 0 && !visited[cur.L][cur.R-1][cur.C]){
            next.L = cur.L, next.R = cur.R - 1, next.C = cur.C, next.step = cur.step + 1;
            visited[next.L][next.R][next.C] = true;
            que.push(next);
        }
        if(cur.C > 0 && !visited[cur.L][cur.R][cur.C-1]){
            next.L = cur.L, next.R = cur.R, next.C = cur.C - 1, next.step = cur.step + 1;
            visited[next.L][next.R][next.C] = true;
            que.push(next);
        }
        if(cur.L < L - 1 && !visited[cur.L+1][cur.R][cur.C]){
            next.L = cur.L + 1, next.R = cur.R, next.C = cur.C, next.step = cur.step + 1;
            visited[next.L][next.R][next.C] = true;
            que.push(next);
        }
        if(cur.R < R - 1 && !visited[cur.L][cur.R+1][cur.C]){
            next.L = cur.L, next.R = cur.R + 1, next.C = cur.C, next.step = cur.step + 1;
            visited[next.L][next.R][next.C] = true;
            que.push(next);
        }
        if(cur.C < C - 1 && !visited[cur.L][cur.R][cur.C+1]){
            next.L = cur.L, next.R = cur.R, next.C = cur.C + 1, next.step = cur.step + 1;
            visited[next.L][next.R][next.C] = true;
            que.push(next);
        }
    }
    return 0;
}
