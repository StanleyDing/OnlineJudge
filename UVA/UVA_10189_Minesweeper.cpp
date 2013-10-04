#include <cstdio>
#include <cstring>
using namespace std;

char mine[105][105];
int d[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
               {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main()
{
    int m, n, nx, ny, count, cases = 1;
    while(scanf("%d%d", &m, &n), m || n){
        for(int i = 0; i < m; i++)
            scanf("%s", mine[i]);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                count = 0;
                if(mine[i][j] == '.'){
                    for(int k = 0; k < 8; k++){
                        nx = i + d[k][0];
                        ny = j + d[k][1];
                        if(nx >= 0 && nx < m && ny >= 0 && ny < n)
                            if(mine[nx][ny] == '*')
                                count++;
                    }
                    mine[i][j] = '0' + count;
                }
            }
        }

        if(cases != 1)
            printf("\n");
        printf("Field #%d:\n", cases++);
        for(int i = 0; i < m; i++)
            printf("%s\n", mine[i]);
    }
    return 0;
}
