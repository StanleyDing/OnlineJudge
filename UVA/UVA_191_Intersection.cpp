#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point{
    int x, y;
} rec[4], line[2];

struct Line{
    Point p1, p2;
} seg[5];

void init();
bool intersect(Line, Line);
int cross_product(Line l, Point p);
bool on_seg(Line l, Point p);
bool inside();

int main()
{
    int N;
    scanf("%d", &N);
    while(N--){
        init();
        if(intersect(seg[0], seg[1]))
            printf("T\n");
        else if(intersect(seg[0], seg[2]))
            printf("T\n");
        else if(intersect(seg[0], seg[3]))
            printf("T\n");
        else if(intersect(seg[0], seg[4]))
            printf("T\n");
        else if(inside())
            printf("T\n");
        else 
            printf("F\n");
    }
    return 0;
}

void init()
{
    scanf("%d %d", &line[0].x, &line[0].y);
    scanf("%d %d", &line[1].x, &line[1].y);
    scanf("%d %d", &rec[0].x, &rec[0].y);
    scanf("%d %d", &rec[2].x, &rec[2].y);
    rec[1].x = rec[0].x, rec[1].y = rec[2].y;
    rec[3].x = rec[2].x, rec[3].y = rec[0].y;

    seg[0].p1 = line[0], seg[0].p2 = line[1];
    seg[1].p1 = rec[0], seg[1].p2 = rec[1];
    seg[2].p1 = rec[1], seg[2].p2 = rec[2];
    seg[3].p1 = rec[2], seg[3].p2 = rec[3];
    seg[4].p1 = rec[3], seg[4].p2 = rec[0];
}

bool intersect(Line l1, Line l2)
{
    int cp1 = cross_product(l1, l2.p1);
    int cp2 = cross_product(l1, l2.p2);
    int cp3 = cross_product(l2, l1.p1);
    int cp4 = cross_product(l2, l1.p2);

    if(cp1 * cp2 < 0 && cp3 * cp4 < 0)
        return true;
    if(cp1 == 0 && on_seg(l1, l2.p1))
        return true;
    if(cp2 == 0 && on_seg(l1, l2.p2))
        return true;
    if(cp3 == 0 && on_seg(l2, l1.p1))
        return true;
    if(cp4 == 0 && on_seg(l2, l1.p2))
        return true;
    return false;
}

int cross_product(Line l, Point p)
{
    int basex = l.p2.x - l.p1.x;
    int basey = l.p2.y - l.p1.y;
    int v1x = p.x - l.p1.x;
    int v1y = p.y - l.p1.y;

    return basex * v1y - basey * v1x;
}

bool on_seg(Line l, Point p)
{
    int xmin = min(l.p1.x, l.p2.x);
    int xmax = max(l.p1.x, l.p2.x);
    int ymin = min(l.p1.y, l.p2.y);
    int ymax = max(l.p1.y, l.p2.y);
    if(xmin <= p.x && p.x <= xmax &&
            ymin <= p.y && p.y <= ymax)
        return true;
    else 
        return false;
}

bool inside()
{
    int xmin = min(rec[0].x, rec[2].x);
    int xmax = max(rec[0].x, rec[2].x);
    int ymin = min(rec[0].y, rec[2].y);
    int ymax = max(rec[0].y, rec[2].y);
    if(xmin < line[0].x && line[0].x < xmax &&
            ymin < line[0].y && line[0].y < ymax)
        return true;
    if(xmin < line[1].x && line[1].x < xmax &&
            ymin < line[1].y && line[1].y < ymax)
        return true;
    return false;
}
