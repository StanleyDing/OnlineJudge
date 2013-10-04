#include <cstdio>
using namespace std;

bool ishappy(int);
int sum_digit(int);

int main()
{
    int N, x;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &x);
        if(ishappy(x))
            printf("Case #%d: %d is a Happy number.\n", i, x);
        else
            printf("Case #%d: %d is an Unhappy number.\n", i, x);
    }
    return 0;
}

bool ishappy(int now)
{
    while(now >= 10)
        now = sum_digit(now);

    if(now == 1)
        return true;
    else if(now == 7){
        while(now != 1)
            now = sum_digit(now);
        return true;
    }
    return false;
}

int sum_digit(int x)
{
    int sum = 0;
    for(int i = x; i > 0; i /= 10)
        sum += (i % 10) * (i % 10);
    return sum;
}
