#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point{
    double x, y;
} p[105];

struct Edge{
    int u, v;
    double w;
    bool operator<(const Edge t) const{
        return w < t.w;
    }
} e[5005];

int d[105];

double dis(int u, int v);
bool is_cycle(int u, int v);
void uni(int u, int v);
int root(int x);

int main()
{
    int t, n, cnt;
    double ans;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        cnt = 0, ans = 0;
        for(int i = 0; i < 105; i++)
            d[i] = i;

        for(int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++){
                e[cnt].u = i, e[cnt].v = j;
                e[cnt++].w = dis(i, j);
            }
        sort(e, e + cnt);
        for(int i = 0; i < cnt; i++){
            if(is_cycle(e[i].u, e[i].v))
                continue;
            uni(e[i].u, e[i].v);
            ans += e[i].w;
        }
        printf("%.2f\n", ans);
        if(t)
            printf("\n");
    }
    return 0;
}

double dis(int u, int v)
{
    double dx, dy;
    dx = p[u].x - p[v].x;
    dy = p[u].y - p[v].y;

    return sqrt(pow(dx, 2) +  pow(dy, 2));
}

bool is_cycle(int u, int v)
{
    return root(u) == root(v);
}

void uni(int u, int v)
{
    int n = root(u);
    int m = root(v);

    d[n] = m;
}

int root(int x)
{
    while(x != d[x]){
        d[x] = d[d[x]];
        x = d[x];
    }
    return d[x];
}
