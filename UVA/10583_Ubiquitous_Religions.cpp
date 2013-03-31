#include <cstdio>
#include <algorithm>
using namespace std;

int p[50005], rank[50005];

int findSet(int x);
void Union(int x, int y);
void link(int x, int y);

int main()
{
    int n, m, p1, p2, ans, cases = 1;
    while(scanf("%d %d", &n, &m), n || m){
        ans = 0;
        for(int i = 1; i <= n; i++){
            p[i] = i;
            rank[i] = 0;
        }
        while(m--){
            scanf("%d %d", &p1, &p2);
            Union(p1, p2);
        }
        for(int i = 1; i <= n; i++)
            if(p[i] == i)
                ans++;
        printf("Case %d: %d\n", cases++, ans);
    }
    return 0;
}

int findSet(int x)
{
    if(p[x] != x)
        p[x] = findSet(p[x]);
    return p[x];
}

void Union(int x, int y)
{
    link(findSet(x), findSet(y));
}

void link(int x, int y)
{
    if(x == y)
        return;
    if(rank[y] > rank[x])
        p[x] = y;
    else{
        p[y] = x;
        if(rank[x] == rank[y])
            rank[x]++;
    }
}
