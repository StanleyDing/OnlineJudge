#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int people[2000005];

int main()
{
    int n;
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++)
            scanf("%d", &people[i]);
        sort(people, people + n);
        for(int i = 0; i < n; i++){
            if(i == n - 1)
                printf("%d\n", people[i]);
            else
                printf("%d ", people[i]);
        }
    }
    return 0;
}
