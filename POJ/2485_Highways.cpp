#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge{
    int v1, v2;
    int length;
    bool operator<(const Edge &t) const
    {
        return length < t.length;
    }
}e[250000];

int p[505], N, edgeCount;

void initP();
int find(int x);
void djsUnion(int x, int y);

int main()
{
    int cases, v1, v2, length, ans;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++){
        scanf("%d", &N);
        ans = edgeCount = 0;
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++){
                scanf("%d", &length);
                if(k > j && length != 0){
                    Edge &edge = e[edgeCount];
                    edge.v1 = j, edge.v2 = k, edge.length = length;
                    edgeCount++;
                }
            }
        sort(e, e + edgeCount);
        initP();
        for(int m = 0, n = 0; m < N - 1 && n < edgeCount; m++, n++){
            while(find(e[n].v1) == find(e[n].v2))
                n++;
            djsUnion(e[n].v1, e[n].v2);
            ans = e[n].length;
        }
        printf("%d\n", ans);
    }
    return 0;
}

void initP()
{
    for(int i = 0; i < N; i++)
        p[i] = i;
}

int find(int x)
{
    if(x == p[x])
        return x;
    return p[x] = find(p[x]);
}

void djsUnion(int x, int y)
{
    p[find(x)] = find(y);
}
