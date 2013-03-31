#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int C, N, above;
    double score[1005], sum, avg;

    scanf("%d", &C);
    while(C--){
        scanf("%d", &N);
        memset(score, 0, sizeof(score));
        above = sum = avg = 0;
        for(int i = 0; i < N; i++){
            scanf("%lf", &score[i]);
            sum += score[i];
        }
        avg = sum / N;
        for(int i = 0; i < N; i++)
            if(score[i] > avg)
                above++;
        printf("%.3f%%\n", above / (double)N * 100);
    }
    return 0;
}
