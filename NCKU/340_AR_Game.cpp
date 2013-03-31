#include <cstdio>
using namespace std;

char bit[255][255];

int main()
{
    int n, zero;
    double area[5] = {1828, 2840, 3852, 4746, 5772}, black, scale, rate;
    while(scanf("%d", &n), n){
        gets(bit[0]);
        black = 0;
        for(int i = 0; i < n; i++)
            gets(bit[i]);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(bit[i][j] == '0')
                    black++;
            }
        }
        scale = (double)n / 100;
        scale *= scale;
        for(int i = 0; i < 5; i++){
            if(black < area[i] * scale + (double)(n * n) * 0.04 && black > area[i] * scale - (double)(n * n) * 0.04){
                printf("%d\n", i + 1);
                break;
            }
        }
    }
    return 0;
}
