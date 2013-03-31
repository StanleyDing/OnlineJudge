#include <cstdio>
using namespace std;

int chess[4][4];
int ans = 100;  //some random big number
int m[5][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};

void dfs(int depth, int flips);
bool finish();
void flip(int depth);

int main()
{
    char c;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%c", &c);
            if(c == 'w')
                chess[i][j] = 1;
            else
                chess[i][j] = 0;
        }
        getchar();
    }
    dfs(0, 0);
    if(ans == 100)
        printf("Impossible");
    else
        printf("%d\n", ans);
    return 0;
}

void dfs(int depth, int flips)
{
    if(finish()){
        if(ans > flips)
            ans = flips;
        return;
    }
    if(depth == 16)
        return;
    dfs(depth + 1, flips);
    flip(depth);
    dfs(depth + 1, flips + 1);
    flip(depth);
}

bool finish()
{
    int sum = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            sum += chess[i][j];
    if(sum % 16)
        return false;
    else
        return true;

}

void flip(int depth)
{
    int row = depth / 4, col = depth % 4;
    for(int i = 0; i < 5; i++){
        int r = row + m[i][0], c = col + m[i][1];
        if(r >= 0 && r < 4 && c >= 0 && c < 4)
            chess[r][c] = !chess[r][c];
    }
}
