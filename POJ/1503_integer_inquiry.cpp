#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int i, j;
    int sum[102] = {0};
    char input[101];
    while(gets(input) && strcmp(input, "0")){
        for(i = strlen(input) - 1, j = 0; i >= 0; i--){
            sum[j++] += input[i] - '0';
        }
    }
    for(i = 1; i < 102; i++){
        if(sum[i-1] > 9){
            sum[i] += sum[i-1] / 10;
            sum[i-1] %= 10;
        }
    }
    i = 101;
    while(sum[i] == 0)  i--;
    for(; i >= 0; i--)
        printf("%d", sum[i]);
    return 0;
}
