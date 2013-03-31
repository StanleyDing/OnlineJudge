#include <cstdio>
using namespace std;

int main()
{
    double n, x;
    while(scanf("%lf", &n) && n > 0){
        if(n == 1)
            printf("0%%\n");
        else{
            x = n / 4 * 100;
            printf("%.0f%%\n", x);
        }
    }
    return 0;
}
