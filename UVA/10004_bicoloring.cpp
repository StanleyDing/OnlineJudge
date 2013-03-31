#include <cstdio>
#include <vector>
#define MAX_NODE 200
using namespace std;

vector<int> list[MAX_NODE];

bool bicolor(int color, int node, int visited[]);

int main()
{
    int n, l, node1, node2;
    while(scanf("%d", &n) && n != 0){
        int visited[MAX_NODE] = {0};
        scanf("%d", &l);
        for(int i = 0; i < l; i++){
            scanf("%d %d", &node1, &node2);
            list[node1].push_back(node2);
            list[node2].push_back(node1);
        }
        if(bicolor(1, 0, visited))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        for(int i = 0; i < MAX_NODE; i++)
            list[i].clear();
    }
    return 0;
}

bool bicolor(int color, int node, int visited[])
{
    visited[node] = color;
    vector<int>::iterator itr = list[node].begin();
    for(; itr != list[node].end(); itr++){
        if(visited[*itr] == color)
            return false;
        if(visited[*itr] == 0)
            return bicolor(-1 * color, *itr, visited);
    }
    return true;
}
