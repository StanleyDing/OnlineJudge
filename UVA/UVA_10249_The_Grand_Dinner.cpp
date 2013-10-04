#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Table{
    int cap, order;
    bool operator<(const Table &t) const{
        return cap < t.cap;
    }
} table[55];

int main()
{
    int M, N, team[75];
    bool can;
    while(scanf("%d %d", &M, &N), M || N){
        can = true;
        for(int i = 0; i < M; i++)
            scanf("%d", &team[i]);
        for(int i = 0; i < N; i++){
            scanf("%d", &table[i].cap);
            table[i].order = i + 1;
        }
        sort(table, table + N);
        for(int i = 0; i < M && can; i++){
            for(int j = 1; j <= team[i]; j++){
                if(N - j < 0 || table[N-j].cap <= 0){
                    can = false;
                    break;
                }
                table[N-j].cap--;
            }
        }
        if(can){
            printf("1\n");
            for(int i = 0; i < M; i++){
                for(int j = 1; j <= team[i]; j++){
                    if(j == 1)
                        printf("%d", table[N-j].order);
                    else
                        printf(" %d", table[N-j].order);
                }
                printf("\n");
            }
        }
        else
            printf("0\n");
    }
    return 0;
}
