#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int p[30005], rank[30005];

int findSet(int);
void link(int, int);

int main()
{
    int T, N, M, p1, p2;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &M);
        for(int i = 1; i <= N; i++){
            p[i] = i;
            rank[i] = 1;
        }
        while(M--){
            scanf("%d%d", &p1, &p2);
            link(p1, p2);
        }
        printf("%d\n", *max_element(rank, rank + N));
    }
    return 0;
}

int findSet(int x)
{
    if(p[x] != x)
        p[x] = findSet(p[x]);
    return p[x];
}

void link(int x, int y)
{
    x = findSet(p[x]);
    y = findSet(p[y]);
    if(x == y)
        return;
    if(rank[y] > rank[x]){
        p[x] = y;
        rank[y] += rank[x];
    }
    else{
        p[y] = x;
        rank[x] += rank[y];
    }
}
