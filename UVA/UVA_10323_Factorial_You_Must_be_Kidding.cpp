#include <cstdio>
#include <cstring>
using namespace std;

long long f[21];

void init();

int main()
{
    int n;
    init();
    while(scanf("%d", &n) != EOF){
        if(n < 0){
            n = -n;
            switch(n % 2){
                case 0:
                    printf("Underflow!\n");
                    break;
                case 1:
                    printf("Overflow!\n");
                    break;
            }
        }
        else if(n > 20 || f[n] == 0)
            printf("Overflow!\n");
        else if(f[n] < 10000)
            printf("Underflow!\n");
        else
            printf("%lld\n", f[n]);
    }
    return 0;
}

void init()
{
    for(long long i = 0; i <= 20; i++){
        if(i == 0)
            f[i] = 1;
        else{
            f[i] = i * f[i-1];
            if(f[i] > 6227020800 || f[i] < f[i-1])
                f[i] = 0;
        }
    }
}
