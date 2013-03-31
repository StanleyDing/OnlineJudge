#include <cstdio>
#include <algorithm>
using namespace std;

struct Job{
    int ith;
    double avg; /* S/T */
    bool operator<(const Job &t) const
    {
        if(avg == t.avg && ith > t.ith)  return true;
        if(avg < t.avg)  return true;
        return false;
    }
};

int main()
{
    int cases, n, T, S;
    Job job[1000];
    while(scanf("%d", &cases) != EOF){
        for(int k = 0; k < cases; k++){
            if(k)
                printf("\n");
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                scanf("%d %d", &T, &S);
                job[i].ith = i + 1;
                job[i].avg = static_cast<double> (S) / T;
            }
            sort(job, job + n);
            for(int i = n - 1; i >= 0; i--){
                printf("%d", job[i].ith);
                if(i)
                    printf(" ");
            }
            printf("\n"); 
        }
    }
    return 0; 
}
