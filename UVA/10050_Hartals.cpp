#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int day[3650];

int mark(int N, int h)
{
    for(int i = h - 1; i < N; i += h){
        if(i % 7 == 5 || i % 7 == 6)
            continue;
        day[i] = 1;
    }
}

int main()
{
    int T, N, P, h;
    scanf("%d", &T);
    while(T--){
        memset(day, 0, sizeof(day));
        scanf("%d %d", &N, &P);
        while(P--){
            scanf("%d", &h);
            mark(N, h);
        }
        printf("%d\n", count(day, day + N, 1));
    }
    return 0;
}
