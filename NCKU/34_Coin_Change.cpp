#include <cstdio>
using namespace std;

int ways[8000];
int type[5] = {1, 5, 10, 25, 50};

int main()
{
    int n;
    for(int i = 0; i < 8000; i++)
        ways[i] = 1;
    for(int i = 1; i < 5; i++)
        for(int j = type[i]; j < 8000; j++)
            ways[j] += ways[j - type[i]];
    while(scanf("%d", &n) != EOF){
        printf("%d\n", ways[n]);
    }
    return 0;
}
