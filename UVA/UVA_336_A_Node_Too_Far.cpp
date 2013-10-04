#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

bool network[50][50], visited[50];
int cases = 1;
map<int, int> m;
struct Pair{
    int node, level;
};

int query(int start, int TTL, int node_num);
void bfs(int start, int TTL);

int main()
{
    int NC, x, y, node_num;
    while(scanf("%d", &NC), NC){
        memset(network, 0, sizeof(network));
        m.clear();
        node_num = 1;
        for(int i = 0; i < NC; i++){
            scanf("%d %d", &x, &y);
            if(!m[x])
                m[x] = node_num++;
            if(!m[y])
                m[y] = node_num++;
            if(x != y){
                network[m[x]][m[y]] = 1;
                network[m[y]][m[x]] = 1;
            }
        }
        while(scanf("%d %d", &x, &y), x || y)
            query(x, y, node_num);
    }
    return 0;
}

int query(int start, int TTL, int node_num)
{
    int notvisited;
    memset(visited, 0, sizeof(visited));
    bfs(m[start], TTL);
    notvisited = count(visited + 1, visited + node_num, 0);
    printf("Case %d: %d nodes ", cases++, notvisited);
    printf("not reachable from node %d with TTL = %d.\n", start, TTL);
}

void bfs(int start, int TTL)
{
    Pair top, temp;
    queue<Pair> q;

    top.node = start, top.level = 0;
    q.push(top);

    while(!q.empty()){
        top = q.front(), q.pop();
        visited[top.node] = true;
        if(top.level == TTL)
            continue;
        for(int i = 0; i < 50; i++){
            if(network[top.node][i] && !visited[i]){
                temp.node = i;
                temp.level = top.level + 1;
                q.push(temp);
            }
        }
    }
}
