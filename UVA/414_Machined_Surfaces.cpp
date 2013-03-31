#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N, totalB, minB, lineB;
    char c;
    while(scanf("%d", &N), N){
        getchar();
        totalB = 0;
        minB = 25;
        for(int i = 0; i < N; i++){
            lineB = 0;
            for(int j = 0; j < 25; j++){
                c = getchar();
                if(c == ' ')
                    totalB++, lineB++;
            }
            minB = min(lineB, minB);
            getchar();
        }
        printf("%d\n", totalB - N * minB);
    }
    return 0;
}
