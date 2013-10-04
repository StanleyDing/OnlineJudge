#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double side[10005];

int main()
{
    int N, t;
    double s, temp, ans;
    scanf("%d", &N);
    while(N--){
        ans = 0;

        scanf("%d", &t);
        for(int i = 0; i < t; i++)
            scanf("%lf", &side[i]);

        sort(side, side + t);
        for(int i = t - 1; i >= 2; i--){
            if(side[i] >= side[i-1] + side[i-2])
                continue;
            s = (side[i] + side[i-1] + side[i-2]) / 2;
            temp = s * (s-side[i]) * (s-side[i-1]) * (s-side[i-2]);
            if(temp > ans)
                ans = temp;
        }

        printf("%.2f\n", sqrt(ans));
    }
    return 0;
}
