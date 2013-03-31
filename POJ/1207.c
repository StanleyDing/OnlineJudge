#include <stdio.h>
#include <stdlib.h>

long long int cycle_length(long long int);

int main()
{
    long long int i, j, cycle, iter, result, firsttime = 1;

    while(scanf("%lld %lld", &i, &j) != EOF){
        if(firsttime != 1)
            printf("\n");
        else
            firsttime = 0;

        cycle = 0;
        if(i >= j){
            for(iter = j; iter <= i; iter++){
                result = cycle_length(iter);
                if(result > cycle)
                    cycle = result;
            }
                printf("%lld %lld %lld", i, j, cycle);
        }
        else if(j > i){
            for(iter = i; iter <= j; iter++){
                result = cycle_length(iter);
                if(result > cycle)
                    cycle = result;
            }
                printf("%lld %lld %lld", i, j, cycle);
        }
    }
    return 0;
}

long long int cycle_length(long long int n)
{
    long long int cycle = 1;
    while(n != 1){
        cycle++;
        if(n % 2 == 1)
            n = 3 * n + 1;
        else
            n /= 2;
    }
    return cycle;
}