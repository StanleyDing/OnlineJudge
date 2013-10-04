#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int m;
    vector<int> v;
} node[10005];

bool visited[10005];
int ans;

void bfs(int, int);

int main()
{
    int N, v, m, d, c;
    while(scanf("%d", &N), N){
        memset(visited, 0, sizeof(visited));
        ans = 0;
        for(int i = 1; i <= N; i++){
            node[i].m = 0;
            node[i].v.clear();
        }

        for(int i = 1; i <= N; i++){
            scanf("%d%d%d", &v, &m, &d);
            node[v].m = m;
            while(d--){
                scanf("%d", &c);
                node[v].v.push_back(c);
                node[c].v.push_back(v);
            }
        }
        bfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}

void bfs(int now, int root)
{
    int move;

    visited[now] = true;
    for(int i = 0; i < node[now].v.size(); i++){
        if(!visited[node[now].v[i]])
            bfs(node[now].v[i], now);
    }

    move = node[now].m - 1;
    ans += (move >= 0 ? move : -move);
    node[root].m += move;
}
