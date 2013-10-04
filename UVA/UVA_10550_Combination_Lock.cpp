#include <cstdio>

int main()
{
    int s, a, b, c, sum;
    while(scanf("%d%d%d%d", &s, &a, &b, &c)){
        if(!s && !a && !b && !c)
            break;

        sum = 120;
        if(s >= a)
            sum += s - a;
        else
            sum += s + 40 - a;
        if(a <= b)
            sum += b - a;
        else
            sum += 40 - a + b;
        if(b >= c)
            sum += b - c;
        else
            sum += b + 40 - c;
        printf("%d\n", sum * 360 / 40);
    }
    return 0;
}
