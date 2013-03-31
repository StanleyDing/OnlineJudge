#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

struct AGEN{
    char name[30];
    int A, B, cost;
    bool operator<(const AGEN &t) const{
        if(cost == t.cost)
            return strcmp(name, t.name) == -1;
        else
            return cost < t.cost;
    }
}temp;
char str[100], substr[100];

void cost(int M, int N);

int main()
{
    int cases, M, N, L;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; i++){
        vector<AGEN> agen;
        vector<AGEN>::iterator itr;
        scanf("%d%d%d", &M, &N, &L);
        getchar();
        while(L--){
            fgets(str, 100, stdin);
            strcpy(temp.name, strtok(str, ":"));
            temp.A = atoi(strtok(NULL, ","));
            temp.B = atoi(strtok(NULL, " "));
            temp.cost = 0;
            cost(M, N);
            agen.push_back(temp);
        }
        sort(agen.begin(), agen.end());
        printf("Case %d\n", i);
        for(itr = agen.begin(); itr != agen.end(); itr++)
            printf("%s %d\n", itr->name, itr->cost);
    }
    return 0;
}

void cost(int M, int N)
{
    while(M / 2 >= N && (M - M / 2) * temp.A > temp.B){
        M /= 2;
        temp.cost += temp.B;
    }
    if(M > N)
        temp.cost += temp.A * (M - N);
}
