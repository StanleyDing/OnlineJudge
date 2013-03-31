#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

struct DNA{
    int ith;
    char s[55];
    int sortedness;
    bool operator<(const DNA &t) const{
        if(sortedness == t.sortedness)
            return ith < t.ith;
        return sortedness < t.sortedness;
    }
}dna[101];

int main()
{
    int cases, n, m;
    while(scanf("%d", &cases) != EOF){
        while(cases--){
            scanf("%d%d", &n, &m);
            for(int i = 0; i < m; i++){
                dna[i].ith = i;
                scanf("%s", dna[i].s);
                dna[i].sortedness = 0;
                for(int j = 0; j < n; j++)
                    for(int k = j + 1; k < n; k++)
                        if(dna[i].s[j] > dna[i].s[k])
                            dna[i].sortedness++;
            }
            sort(dna, dna + m);
            for(int i = 0; i < m; i++)
                printf("%s\n", dna[i].s);
            if(cases)
                printf("\n");
        }
    }
    return 0;
}
