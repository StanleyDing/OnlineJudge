#include <cstdio>
#include <cstring>
#define MAXN 32005
using namespace std;

int s[MAXN], level[15005];

void change(int start, int delta);
int lowbit(int x);
int getsum(int x);

int main()
{
    int N, x, y;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &x, &y);
        x++;
        level[getsum(x)]++;
        change(x, 1);
    }
    for(int i = 0; i < N; i++)
        printf("%d\n", level[i]);
    return 0;
}

void change(int start, int delta)
{
    for(int i = start; i <= MAXN; i+= lowbit(i))
        s[i] += delta;
}

int lowbit(int x)
{
    return x & -x;
}

int getsum(int x)
{
    int ans = 0;
    while(x > 0){
        ans += s[x];
        x -= lowbit(x);
    }
    return ans;
}
