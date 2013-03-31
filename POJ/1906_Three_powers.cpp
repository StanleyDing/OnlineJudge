//find pattern, big int
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int pow3[100][50] = {0};

void power(int exp);

int main()
{
    unsigned long long int n;
    int exp, digit;
    bool isFirst;
    pow3[0][0] = 1;
    while(scanf("%llu", &n), n){
        n--;
        if(n == 0){
            printf("{ }\n");
            continue;
        }

        exp = 0;
        isFirst = true;
        printf("{ ");
        while(n){
            if(n & 1 == 1){
                power(exp);
                digit = 50 - 1;

                if(!isFirst)
                    printf(", ");
                while(pow3[exp][digit] == 0)
                    digit--;
                for(; digit >= 0; digit--)
                    printf("%d", pow3[exp][digit]);
                isFirst = false;
            }
            n >>= 1;
            exp++;
        }
        printf(" }\n");
    }
    return 0;
}

void power(int exp)
{
    if(pow3[exp][0] == 0){
        power(exp - 1);

        for(int digit = 0; digit < 50; digit++)
            pow3[exp][digit] = pow3[exp-1][digit] * 3;
        for(int digit = 0; digit < 50 - 1; digit++){
            pow3[exp][digit+1] += pow3[exp][digit] / 10;
            pow3[exp][digit] %= 10;
        }
    }
}
