#include <cstdio>
#include <cstring>
using namespace std;

struct Grid{
    bool visited;
    int step;
}grid[15][15];

char m[15][15];
int row, col, start;

void path();

int main()
{
    while(scanf("%d %d %d", &row, &col, &start), row || col || start){
        getchar();
        memset(grid, 0, sizeof(grid));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++)
                scanf("%c", &m[i][j]);
            getchar();
        }
        path();
    }
    return 0;
}

void path()
{
    int step = 0;
    int nextR = 0, nextC = start - 1;
    char nextmove = m[0][start-1];
    grid[0][start-1].step = 0;
    grid[0][start-1].visited = true;

    while(1){
        step++;
        if(nextmove == 'N')
            nextR--;
        else if(nextmove == 'S')
            nextR++;
        else if(nextmove == 'W')
            nextC--;
        else
            nextC++;
        if(nextR < 0 || nextR == row || nextC < 0 || nextC == col){
            printf("%d step(s) to exit\n", step);
            break;
        }
        if(grid[nextR][nextC].visited){
            printf("%d step(s) before a loop of %d step(s)\n", grid[nextR][nextC].step, step - grid[nextR][nextC].step);
            break;
        }
        else{
            grid[nextR][nextC].step = step;
            grid[nextR][nextC].visited = true;
        }
        nextmove = m[nextR][nextC];
    }
}
