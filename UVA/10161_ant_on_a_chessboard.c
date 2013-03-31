#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int sqr;
    int N, dif, x;
    scanf("%d", &N);

    while(N){
        sqr = (int) sqrt(N);
        dif = N - pow(sqr, 2);
        x = 2 * (sqr + 1) - dif;
        if(dif == 0)
            if(sqr % 2 == 0)
                printf("%d %d\n", sqr, 1);
            else
                printf("%d %d\n", 1, sqr);
        else if(dif <= sqr + 1)
            if(sqr % 2 == 0)
                printf("%d %d\n", sqr + 1, dif);
            else
                printf("%d %d\n", dif, sqr + 1);
        else if(dif > sqr + 1)
            if(sqr % 2 == 0)
                printf("%d %d\n", x, sqr + 1);
            else
                printf("%d %d\n", sqr + 1, x);
        scanf("%d", &N);
    }
    return 0;
}
