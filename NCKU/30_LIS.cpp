#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 50000
using namespace std;

int seq[MAX], length[MAX], n;

int LIS()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(seq[j] < seq[i] && length[i] < length[j] + 1)
                length[i] = length[j] + 1;
        }
    }
    return *max_element(length, length + n);
}

int main()
{
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &seq[i]);
            length[i] = 1;
        }
        printf("%d\n", LIS());
    }
    return 0;
}
