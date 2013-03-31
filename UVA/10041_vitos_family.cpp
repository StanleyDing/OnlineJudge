#include <cstdio>
#include <algorithm>
#include <cmath>
#define NUM_R 500
using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int r, s[NUM_R], cases, sum;
    while(scanf("%d", &cases) != EOF){
        for(int i = 0; i < cases; i++){
            sum = 0;
            scanf("%d", &r);
            for(int j = 0; j < r; j++)
                scanf("%d", &s[j]);
            sort(s, s + r, cmp);
            for(int j = 0; j < r; j++){
                sum += fabs(s[r/2] - s[j]);
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
