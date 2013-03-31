#include <cstdio>
#include <cstring>
using namespace std;

int a[10000];

int findMax(int, int);
int findCross(int, int);

int main()
{
    int n;
    while(scanf("%d", &n) && n){
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int ans = findMax(0, n - 1);
        if(ans > 0)
            printf("The maximum winning streak is %d.\n", ans);
        else
            printf("Losing streak.\n");
    }
    return 0;
}

int findMax(int low, int high)
{
    if(low == high)
        return a[low];
    else{
        int mid = (low + high) / 2;
        int left = findMax(low, mid);
        int right = findMax(mid + 1, high);
        int cross = findCross(low, high);
        if(left >= right && left >= cross)
            return left;
        else if(right >= left && right >= cross)
            return right;
        else
            return cross;
    }
}

int findCross(int low, int high)
{
    int mid = (low + high) / 2;
    int max_l = 0, max_r = 0;
    for(int i = mid, sum = 0; i >= low; i--){
        sum += a[i];
        if(sum > max_l)
            max_l = sum;
    }
    for(int i = mid + 1, sum = 0; i <= high; i++){
        sum += a[i];
        if(sum > max_r)
            max_r = sum;
    }
    return max_l + max_r;
}
