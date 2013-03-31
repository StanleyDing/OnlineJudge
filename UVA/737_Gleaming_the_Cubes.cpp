#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n, x, y, z, length;
    int xMin, xMax, yMin, yMax, zMin, zMax;
    while(scanf("%d", &n), n){
        scanf("%d%d%d%d", &x, &y, &z, &length);
        xMin = x, yMin = y, zMin = z;
        xMax = x + length, yMax = y + length; zMax = z + length;
        for(int i = 1; i < n; i++){
            scanf("%d%d%d%d", &x, &y, &z, &length);
            xMin = max(xMin, x), yMin = max(yMin, y), zMin = max(zMin, z);
            xMax = min(xMax, x + length), yMax = min(yMax, y + length), zMax = min(zMax, z + length);
        }
        if(xMin > xMax || yMin > yMax || zMin > zMax)
            printf("0\n");
        else
            printf("%d\n", (xMax - xMin) * (yMax - yMin) * (zMax - zMin));
    }
    return 0;
}
