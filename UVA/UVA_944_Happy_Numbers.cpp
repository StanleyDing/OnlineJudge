#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int num[100005] = {0};

int check(int);
int sum_digit(int);

int main()
{
    int L, H, first = 1;
    num[1] = 1;
    while(scanf("%d %d", &L, &H) != EOF){
        if(!first)
            printf("\n");
        else
            first = 0;
        for(int i = L; i <= H; i++){
            if(check(i) > 0)
                printf("%d %d\n", i, check(i));
        }
    }
    return 0;
}

int check(int x)
{
    if(num[x])
        return num[x];

    int count;
    num[x] = -1;
    count = check(sum_digit(x));
    return num[x] = count == -1 ? -1 : count + 1;
}

int sum_digit(int x)
{
    int sum = 0;
    for(int i = x; i > 0; i /= 10)
        sum += (i % 10) * (i % 10);
    return sum;
}
