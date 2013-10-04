#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Ele{
    int id, w, s;
    bool operator<(const Ele &t) const{
        return (w < t.w || (w == t.w && s > t.s));
    }
} ele[1005];

void trace(int x, int prev[]);

int main()
{
    int w, s, n = 0;
    int length[1005], prev[1005];

    memset(prev, -1, sizeof(prev));

    while(scanf("%d %d", &w, &s) != EOF){
        ele[n].id = n, ele[n].w = w, ele[n].s = s;
        length[n++] = 1;
    }
    sort(ele, ele + n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(ele[i].w != ele[j].w && ele[i].s < ele[j].s){
                if(length[j] + 1 > length[i]){
                    length[i] = length[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }

    int max = 0, pos = 0;
    for(int i = 0; i < n; i++)
        if(length[i] > max){
            max = length[i];
            pos = i;
        }

    printf("%d\n", max);
    trace(pos, prev);

    return 0;
}

void trace(int x, int prev[])
{
    if(prev[x] != -1)
        trace(prev[x], prev);
    printf("%d\n", ele[x].id + 1);
}
