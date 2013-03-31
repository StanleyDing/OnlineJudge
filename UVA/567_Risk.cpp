//bfs
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct NODE{
    int v, step;
}temp, cur, start;

vector<NODE> link[21];

int bfs(int, int);

int main()
{
    int cases = 1, x, n, A, B;
    while(scanf("%d", &x) != EOF){
        for(int i = 0; i < x; i++){
            scanf("%d", &n);
            temp.v = n, temp.step = 0;
            link[1].push_back(temp);
            temp.v = 1;
            link[n].push_back(temp);
        }
        for(int i = 2; i <= 19; i++){
            scanf("%d", &x);
            for(int j = 0; j < x; j++){
                scanf("%d", &n);
                temp.v = n;
                link[i].push_back(temp);
                temp.v = i;
                link[n].push_back(temp);
            }
        }
        printf("Test Set #%d\n", cases++);
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &A, &B);
            printf("%2d to %2d: %d\n", A, B, bfs(A, B));
        }
        for(int i = 1; i <= 20; i++)
            link[i].clear();
        printf("\n");
    }
    return 0;
}

int bfs(int a, int b)
{
    bool visited[21] = {0};
    queue<NODE> que;
    vector<NODE>::iterator itr;

    start.v = a, start.step = 0;
    que.push(start);
    visited[a] = true;

    while(!que.empty()){
        cur = que.front();
        que.pop();
        for(itr = link[cur.v].begin(); itr != link[cur.v].end(); itr++){
            if(visited[itr->v])
                continue;
            visited[itr->v] = true;
            itr->step = cur.step + 1;
            if(itr->v == b)
                return itr->step;
            que.push(*itr);
        }
    }
}
