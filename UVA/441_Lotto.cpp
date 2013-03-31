#include <cstdio>
#include <cstring>
using namespace std;

bool visited[49];
int S[13], ans[6];

void permu(int, int);

int main()
{
    int k;
    bool first_case = true;
    while(scanf("%d", &k) && k){
        if(!first_case)
            printf("\n");
        first_case = false;
        memset(S, 0, sizeof(S));
        memset(visited, 0, sizeof(visited));
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < k; i++)
            scanf("%d", &S[i]);
        permu(0, k);
    }
    return 0;
}

void permu(int n, int k)
{
    if(n == 6){
        for(int i = 0; i < 6; i++)
            if(i)
                printf(" %d", ans[i]);
            else
                printf("%d", ans[i]);
        printf("\n");
    }
    else{
        for(int i = 0; i < k; i++){
            if(!visited[S[i]]){
                if(n > 0 && S[i] < ans[n-1])
                    continue;
                ans[n] = S[i];
                visited[S[i]] = true;
                permu(n + 1, k);
                visited[S[i]] = false;
            }
        }
    }
}
