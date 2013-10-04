#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    int N, M, x, y, now, counter[26], wake[26], count;
    bool con[26][26];
    char in[5];
    queue<int> q;

    while(scanf("%d%d", &N, &M) != EOF){
        memset(con, 0, sizeof(con));
        memset(wake, -1, sizeof(wake));
        memset(counter, 0, sizeof(counter));
        count = 3;

        scanf("%s", in);
        for(int i = 0; i < 3; i++){
            q.push(in[i] - 'A');
            wake[in[i]-'A'] = 0;
        }

        for(int i = 0; i < M; i++){
            scanf("%s", in);
            x = in[0] - 'A', y = in[1] - 'A';
            con[x][y] = con[y][x] = true;
        }

        while(!q.empty()){
            now = q.front(), q.pop();
            for(int i = 0; i < 26; i++){
                if(con[now][i] && wake[i] < 0){
                    counter[i]++;
                    if(counter[i] == 3){
                        wake[i] = wake[now] + 1;
                        q.push(i);
                        count++;
                    }
                }
            }
        }

        if(count != N)
            printf("THIS BRAIN NEVER WAKES UP\n");
        else
            printf("WAKE UP IN, %d, YEARS\n", wake[now]);
    }
    return 0;
}
