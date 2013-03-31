#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int n, cur, next, dif;
    bool find[3001], jolly;
    while(scanf("%d", &n) != EOF){
        jolly = true;
        memset(find, 0, sizeof(find));
        scanf("%d", &cur);
        for(int i = 1; i < n; i++){  //scan n - 1 times
            scanf("%d", &next);
            dif = abs(cur - next);
            find[dif] = true;
            cur = next;
        }
        for(int i = 1; i <= n - 1; i++)
            if(!find[i])
                jolly = false;
        if(jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
