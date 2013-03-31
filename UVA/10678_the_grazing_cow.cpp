#include <cstdio>
#include <cmath>
#define PI 2 * acos(0)

int main()
{
    int n;
    double D, L, a, b, c;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &D, &L);
            a = L / 2;
            c = D / 2;
            b = sqrt(pow(a, 2) - pow(c, 2));
            printf("%.3f\n", a * b * PI);
        }
    }
    return 0;
}
