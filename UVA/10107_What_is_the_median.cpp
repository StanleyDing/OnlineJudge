#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int seq[10001] = {0}, n_int = 0, n, p;
    //seq[0] is not used
    while(scanf("%d", &n) != EOF){
        seq[++n_int] = n;
        for(int i = n_int; i >= 2; i--)
            if(seq[i] < seq[i-1])
                swap(seq[i], seq[i-1]);
        if(n_int % 2 == 0)
            printf("%d\n", (seq[n_int/2] + seq[n_int/2+1]) / 2);
        else
            printf("%d\n", seq[n_int/2+1]);
    }
    return 0;
}
