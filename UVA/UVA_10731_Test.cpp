//SCC
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

bool G[26][26], visit[26];
set<int> V;
stack<int> S;

void dfs(int x);
void dfs_T(int x, int num);

struct Set{
    set<int> alphas;
    bool operator<(const Set &t) const{
        return alphas < t.alphas;
    }
} sets[26];

int main()
{
    int n;
    char x[5], ans;
    set<int>::iterator itr, begin, end;
    bool first_case = true;

    while(scanf("%d", &n), n){
        //init
        memset(G, 0, sizeof(G));
        memset(visit, 0, sizeof(visit));
        V.clear();
        for(int i = 0; i < 26; i++)
            sets[i].alphas.clear();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                scanf(" %c", &x[j]);
                x[j] -= 'A';
                V.insert(x[j]);
            }
            scanf(" %c", &ans);
            ans -= 'A';
            for(int j = 0; j < 5; j++)
                G[ans][x[j]] = true;
        }

        //first dfs
        for(itr = V.begin(); itr != V.end(); itr++){
            if(!visit[*itr])
                dfs(*itr);
        }

        //second dfs
        int set_count = 0;
        memset(visit, 0, sizeof(visit));
        while(!S.empty()){
            int top = S.top();
            S.pop();
            if(!visit[top]){
                dfs_T(top, set_count);
                set_count++;
            }
        }

        sort(sets, sets + set_count);

        if(first_case)
            first_case = false;
        else
            printf("\n");

        for(int i = 0; i < set_count; i++){
            begin = sets[i].alphas.begin();
            end = sets[i].alphas.end();
            for(itr = begin; itr != end; itr++){
                if(itr == begin)
                    printf("%c", *itr + 'A');
                else
                    printf(" %c", *itr + 'A');
            }
            printf("\n");
        }
    }
    return 0;
}

void dfs(int x)
{
    visit[x] = true;
    for(int i = 0; i < 26; i++){
        if(G[x][i] && !visit[i])
            dfs(i);
    }
    S.push(x);
}

void dfs_T(int x, int num)
{
    visit[x] = true;
    sets[num].alphas.insert(x);
    for(int i = 0; i < 26; i++){
        if(G[i][x] && !visit[i])
            dfs_T(i, num);
    }
}
