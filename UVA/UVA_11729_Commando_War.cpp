#include <cstdio>
#include <algorithm>
using namespace std;

struct Task{
    int b, e;
    bool operator<(const Task &t) const{
        return b+max(t.b+t.e, e) < t.b+max(b+e, t.e);
    }
} t[1005];

int main()
{
    int N, cases = 1, b_time, time;
    while(scanf("%d", &N), N){
        for(int i = 0; i < N; i++)
            scanf("%d%d", &t[i].b, &t[i].e);

        sort(t, t + N);

        time = b_time = 0;
        for(int i = 0; i < N; i++){
            b_time += t[i].b;
            time = max(time, b_time + t[i].e);
        }
        printf("Case %d: %d\n", cases++, time);
    }
    return 0;
}
