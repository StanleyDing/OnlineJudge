//disjoint set
#include <cstdio>
#include <algorithm>
#define MAX_COMPUTER 300001
using namespace std;

int p[MAX_COMPUTER], rank[MAX_COMPUTER], root[MAX_COMPUTER];

void Union(int x, int y);
int find(int x);
void link(int x, int y);

int main()
{
    int cases, N, M, p1, p2;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++){
            rank[i] = 0;
            root[i] = 1;
            p[i] = i;
        }
        for(int i = 1; i <= M; i++){
            scanf("%d %d", &p1, &p2);
            Union(p1, p2);
        }
        printf("%d\n", *max_element(root + 1, root + N + 1));
    }
}

void Union(int x, int y)
{
    if(find(x) == find(y))  return;
    link(find(x), find(y));
}

int find(int x)
{
    if(p[x] != x){
        p[x] =  find(p[x]);
        return p[x];
    }
    return x;
}

void link(int x, int y)
{
    if(rank[x] > rank[y]){
        p[y] = x;
        root[x] += root[y];
    }
    else{
        p[x] = y;
        root[y] += root[x];
        if(rank[x] == rank[y])
            rank[y]++;
    }
}
