//DP, LIS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int seq[20000], dp[20000], pre[20000];
int num, Max;

int DP();
void printSeq();

int main()
{
    int n;
    char s[20];
    scanf("%d\n\n", &n);

    while(n--){
        num = 0;
        memset(pre, -1, sizeof(pre));

        while(fgets(s, 20, stdin) != NULL){
            if(s[0] == '\n')  break;
            sscanf(s, "%d", &seq[num]);
            dp[num++] = 1;
        }
        Max = DP();
        printf("Max hits: %d\n", Max);
        printSeq();
        if(n != 0)
            printf("\n");
    }
    return 0;
}

int DP()
{
    for(int i = 0; i < num; i++)
        for(int j = 0; j < i; j++){
            if(seq[j] < seq[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
    return *max_element(dp, dp + num);
}

void printSeq()
{
    int stack[20000], top = -1, i;
    for(i = num - 1; dp[i] != Max; i--);
    while(i != -1){
        stack[++top] = seq[i];
        i = pre[i];
    }
    while(1){
        printf("%d\n", stack[top--]);
        if(top == -1)
            break;
    }
}
