//binary search
#include <cstdio>

int N, M, money[100000];
int up_bound = 0, low_bound = 0;

int binarySearch();
bool valid(int min);

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &money[i]);
        if(money[i] > low_bound)
            low_bound = money[i];
        up_bound += money[i];
    }
    printf("%d\n", binarySearch());
    return 0;
}

int binarySearch()
{
    int mid;
    while(low_bound < up_bound){
        mid = (low_bound + up_bound) >> 1;
        if(valid(mid))
            up_bound = mid;
        else
            low_bound = mid + 1;
    }
    return low_bound;
}

bool valid(int min)
{
    int fjmonth = 1;
    int sum = 0, max = 0;

    for(int i = 0; i < N; i++){
        if(sum + money[i] > min){
            sum = 0;
            fjmonth++;
        }
        sum += money[i];
    }
    if(fjmonth <= M)
        return true;
    return false;
}
