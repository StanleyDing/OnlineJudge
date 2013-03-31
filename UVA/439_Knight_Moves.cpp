//bfs
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct POSITION{
    int r, c, step;
    bool operator==(const POSITION &t) const{
        return r == t.r && c == t.c;
    }
}start, end, temp, cur;

int move[8][2] = {
    {-1, -2}, {-2, -1},
    {-2, 1}, {-1,2},
    {1, -2}, {2, -1},
    {2, 1}, {1, 2}
};

int visited[9][9];

int bfs();
bool valid(int, int);

int main()
{
    char s1[3], s2[3];
    while(scanf("%s %s", s1, s2) != EOF){
        memset(visited, 0, sizeof(visited));
        start.r = s1[1] - '0', start.c = s1[0] - 'a' + 1, start.step = 0;
        end.r = s2[1] - '0', end.c = s2[0] - 'a' + 1;
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, bfs());
    }
    return 0;
}

int bfs()
{
    if(start == end)
        return 0;
    queue<POSITION> que;
    que.push(start);
    while(!que.empty()){
        cur = que.front();
        que.pop();
        for(int i = 0; i < 8; i++){
            if(!valid(cur.r + move[i][0], cur.c + move[i][1]))
                continue;
            temp.r = cur.r + move[i][0];
            temp.c = cur.c + move[i][1];
            temp.step = cur.step + 1;
            if(temp == end)
                return temp.step;
            visited[temp.r][temp.c] = true;
            que.push(temp);
        }
    }
}

bool valid(int r, int c)
{
    if(r > 0 && r < 9 && c > 0 && c < 9 && !visited[r][c])
        return true;
    return false;
}
