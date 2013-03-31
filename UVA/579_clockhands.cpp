#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    double H, M, H_angle, M_angle, dif;
    while(scanf("%lf:%lf", &H, &M), H || M){
        H_angle = H * 30 + M / 2;
        M_angle = M * 6;
        dif = H_angle - M_angle;
        if(dif < 0)
            dif += 360;
        printf("%.3f\n", min(dif, 360 - dif));
    }
    return 0;
}
