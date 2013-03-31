#include <cstdio>
#define MAX 500000
using namespace std;

void mergeSort(long long int[], int, int);
void merge(long long int[], int, int);

long long int count;

int main()
{
    int n;
    long long int a[MAX];
    while(scanf("%d", &n) && n != 0){
        count = 0;
        for(int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        mergeSort(a, 0, n - 1);
        printf("%lld\n", count);
    }
    return 0;
}

void mergeSort(long long int a[], int low, int high)
{
    if(low < high){
        mergeSort(a, low, (low + high) / 2);
        mergeSort(a, (low + high) / 2 + 1, high);
        merge(a, low, high);
    }
}

void merge(long long int a[], int low, int high)
{
    long long int b[MAX];
    int mid = (low + high) / 2;
    int i, j, k = 0;
    for(i = low, j = mid + 1; i <= mid || j <= high;){
        if(i > mid)
            b[k++] = a[j++];
        else if(j > high){
            b[k++] = a[i++];
            count += j - mid - 1;
        }
        else if(a[i] < a[j]){
            b[k++] = a[i++];
            count += j - mid - 1;
        }
        else if(a[i] >= a[j])
            b[k++] = a[j++];
    }
    k = 0;
    for(i = low; i <= high; i++)
        a[i] = b[k++];
}
