#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point{
    int x, y;
    bool operator<(const Point &t) const{
        return ((x < t.x) || (x == t.x && y > t.y));
    }
} p[1005], ch[1005];

int product(Point ref, Point p1, Point p2);

int main()
{
    int N, L, t = 0;
    double ans = 0;
    scanf("%d%d", &N, &L);
    for(int i = 0; i < N; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
    sort(p, p + N);     //sort points from left-to-right, top-to-bottom.

    for(int i = 0; i < N; i++){
        while(t >= 2 && product(ch[t-2], ch[t-1], p[i]) <= 0)
            t--;
        ch[t++] = p[i];
    }
    for(int i = N - 2, u = t + 1; i >= 0; i--){
        while(t >= u && product(ch[t-2], ch[t-1], p[i]) <= 0)
            t--;
        ch[t++] = p[i];
    }
    for(int i = 1; i < t; i++){
        ans += sqrt(pow((double)(ch[i].x - ch[i-1].x), 2)
                + pow((double)(ch[i].y - ch[i-1].y), 2));
    }
    ans += 2 * 3.14159 * (double)L;
    printf("%.lf\n", ans);
    return 0;
}

int product(Point ref, Point p1, Point p2)
{
    int v1x = p1.x - ref.x, v2x = p2.x - ref.x;
    int v1y = p1.y - ref.y, v2y = p2.y - ref.y;
    return v1x * v2y - v1y * v2x;
}
