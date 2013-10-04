#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int seq[1005];
int bubble(int x[], int n);

int main()
{
    int C, N;
    scanf("%d", &C);
    for(int i = 1; i <= C; i++){
        scanf("%d", &N);
        for(int j = 0; j < N; j++)
            scanf("%d", &seq[j]);
        printf("Scenario #%d:\n%d\n\n", i, bubble(seq, N));
    }
    return 0;
}

int bubble(int x[], int n)
{
    int ans = 0;
    for(int i = n - 1; i >= 1; i--)
        for(int j = 0; j < i; j++)
            if(x[j] > x[j+1]){
                ans++;
                swap(x[j], x[j+1]);
            }
    return ans;
}
