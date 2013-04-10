#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct data{
    int v;
    bool operator<(const data &t) const
    {
        return v > t.v;
    }
}d, a, b, cost;

int main()
{
    int n, sum;
    priority_queue<data> pq;
    while(scanf("%d", &n), n){
        sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &d.v);
            pq.push(d);
        }
        while(!pq.empty()){
            a = pq.top();
            pq.pop();
            if(pq.empty())
                break;
            b = pq.top();
            pq.pop();
            sum += a.v + b.v;
            cost.v = a.v + b.v;
            pq.push(cost);
        }
        printf("%d\n", sum);
    }
}
