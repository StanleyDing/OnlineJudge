#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n, steps, x, y, dif;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &x, &y);
        dif = y - x;
        if(dif == 0){
            printf("0\n");
            continue;
        }
        steps = (int)sqrt(dif);
        if(steps * steps == dif)
            printf("%d\n", 2 * steps - 1);
        else if(steps * steps + steps >= dif)
            printf("%d\n", 2 * steps);
        else
            printf("%d\n", 2 * steps + 1);
    }
    return 0;
}
