#include <cstdio>
#include <algorithm>

using namespace std;

int sort(int[], int);

int main()
{
    int n, num[1000];
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        printf("Minimum exchange operations : %d\n", sort(num, n));
    }
    return 0;
}

int sort(int num[], int n)
{
    int count = 0;
    for(int j = n - 1; j >= 0; j--){
        for(int i = 0; i < j; i++){
            if(num[i] > num[i+1]){
                swap(num[i], num[i+1]);
                count++;
            }
        }
    }
    return count;
}
