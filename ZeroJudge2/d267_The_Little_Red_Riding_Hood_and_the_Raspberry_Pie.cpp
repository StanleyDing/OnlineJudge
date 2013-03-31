#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int nr, nc;
int map[105][105], burden[105][105], berries[105][105], prev[105][105];
stack<int> route;

int DP(int r, int c)
{
    if(r < 0 || c < 0)
        return -10;
    if(berries[r][c] != -1)
        return berries[r][c];
    int berriesFromNorth = DP(r - 1, c);
    int berriesFromWest = DP(r, c - 1);
    int burdenFromNorth = burden[r-1][c] + berriesFromNorth;
    int burdenFromWest = burden[r][c-1] + berriesFromWest;
    if(berriesFromNorth > berriesFromWest){
        berries[r][c] = berriesFromNorth + map[r][c];
        burden[r][c] = burden[r-1][c] + berries[r-1][c];
    }
    if(berriesFromNorth < berriesFromWest){
        berries[r][c] = berriesFromWest + map[r][c];
        burden[r][c] = burden[r][c-1] + berries[r][c-1];
    }
    if(berriesFromNorth == berriesFromWest){
        berries[r][c] = berriesFromWest + map[r][c];
        burden[r][c] = min(burdenFromNorth, burdenFromWest);
    }
    //berries[r][c] = max(berriesFromNorth, berriesFromWest) + map[r][c];
    return berries[r][c];
}

void plot()
{
    int R = nr - 1, C = nc - 1, dir;
    while(R > 0 && C > 0){
        if(berries[R-1][C] > berries[R][C-1]){
            route.push(1);
            R--;
        }
        else if(berries[R-1][C] < berries[R][C-1]){
            route.push(0);
            C--;
        }
        else if(burden[R][C-1] < burden[R-1][C]){
            route.push(0);
            C--;
        }
        else{
            route.push(1);
            R--;
        }
    }
    while(R--)
        route.push(1);
    while(C--)
        route.push(0);
    while(!route.empty()){
        dir = route.top();
        printf("%d", dir);
        route.pop();
    }
}

int main()
{
    while(scanf("%d%d", &nr, &nc), nr || nc){
        memset(berries, -1, sizeof(berries));
        memset(burden, 0, sizeof(burden));
        for(int i = 0; i < nr; i++)
            for(int j = 0; j < nc; j++)
                scanf("%d", &map[i][j]);
        berries[0][0] = map[0][0];
        DP(nr - 1, nc - 1);
        printf("%d %d ", berries[nr-1][nc-1], burden[nr-1][nc-1]);
        plot();
        printf("\n");
    }
    return 0;
}
