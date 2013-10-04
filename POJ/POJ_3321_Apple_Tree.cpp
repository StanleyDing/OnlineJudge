#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 

struct Node{
    int root, count; 
    bool intree, hasapple;
} node[100005];

void add_fork(int father, int child);
void change(int x, int delta);

int main()
{
    int N, M, x, y;
    char s[2];
    node[1].count++;
    node[1].hasapple = true;

    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++){
        scanf("%d %d", &x, &y);
        add_fork(x, y);
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%s %d", s, &x);

        if(s[0] == 'Q')
            printf("%d\n", node[x].count);
        else{
            if(node[x].hasapple){
                node[x].hasapple = false;
                node[x].count--;
                change(node[x].root, -1);
            }
            else{
                node[x].hasapple = true;
                node[x].count++;
                change(node[x].root, 1);
            }
        }
    }
    return 0;
}

void add_fork(int father, int child)
{
    if(child == 1 || node[child].intree)
        swap(father, child);
    node[child].intree = true;
    node[child].hasapple = true;
    node[child].count++;
    node[child].root = father;
    change(father, 1);
}

void change(int x, int delta)
{
    if(!x)
        return;
    node[x].count += delta;
    change(node[x].root, delta);
}
