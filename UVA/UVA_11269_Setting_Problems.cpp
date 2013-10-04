#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Problem{
    int x, y;
    bool operator<(const Problem &t) const{
        return x+max(y, t.x)+t.y < t.x+max(t.y, x)+y;
    }
} temp;

Problem p[25];

int main()
{
    int N, time, x_time;
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i++)
            scanf("%d", &p[i].x);
        for(int i = 0; i < N; i++)
            scanf("%d", &p[i].y);
        sort(p, p + N);

        time = x_time = 0;
        for(int i = 0; i < N; i++){
            x_time += p[i].x;
            time = max(x_time, time);
            time += p[i].y;
        }
        printf("%d\n", time);
    }
    return 0;
}
