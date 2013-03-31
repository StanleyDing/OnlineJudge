#include <cstdio>
#include <cmath>

int main()
{
    unsigned int n;
    int on;
    
    while(scanf("%d", &n) && n != 0){
        on = 0;
        if(sqrt(n) == static_cast <unsigned int> (sqrt(n)))
            on = 1;

        if(on == 1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
