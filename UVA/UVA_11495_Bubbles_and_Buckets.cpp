#include <cstdio>
#include <cstring>
#define MAXN 100005
using namespace std;

int num[MAXN], count;
void merge_sort(int head, int tail);
void merge(int head, int tail);

int main()
{
    int N;
    while(scanf("%d", &N), N){
        count = 0;
        for(int i = 0; i < N; i++)
            scanf("%d", &num[i]);
        merge_sort(0, N - 1);
        if(count % 2)
            printf("Marcelo\n");
        else
            printf("Carlos\n");
    }
    return 0;
}

void merge_sort(int head, int tail)
{
    int mid = (head + tail) / 2;
    if(head < tail){
        merge_sort(head, mid);
        merge_sort(mid+1, tail);
        merge(head, tail);
    }
}

void merge(int head, int tail)
{
    int i, j, k, mid, temp[MAXN];
    mid = (head + tail) / 2;
    i = head, j = mid + 1, k = 0;

    while(i <= mid || j <= tail){
        if(i > mid)
            temp[k++] = num[j++];
        else if(j > tail)
            temp[k++] = num[i++];
        else if(num[j] < num[i]){
            temp[k++] = num[j++];
            count += (mid + 1) - i;
        }
        else
            temp[k++] = num[i++];
    }

    for(i = head, k = 0; i <= tail; i++)
        num[i] = temp[k++];
}
