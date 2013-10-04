#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m, count, p = 1;
vector<int> peg[3];
void rec(int disk, int from, int to);
void print_now();

int main()
{
    while(scanf("%d %d", &n, &m), n || m){
        for(int i = 0; i < 3; i++)
            peg[i].clear();
        for(int i = n; i >= 1; i--)
            peg[0].push_back(i);
        printf("Problem #%d\n\n", p++);
        print_now();
        count = 0;
        rec(n, 0, 2);
    }
    return 0;
}

void rec(int disk, int from, int to)
{
    if(disk == 1){
        peg[from].pop_back();
        peg[to].push_back(1);
        print_now();
        return;
    }

    rec(disk-1, from, 3-(from+to));
    if(count == m)
        return;
    peg[from].pop_back();
    peg[to].push_back(disk);
    print_now();
    if(count == m)
        return;
    rec(disk-1, 3-(from+to), to);
}

void print_now()
{
    for(int i = 0; i < 3; i++){
        if(i == 0)  printf("A=>");
        else if(i == 1)  printf("B=>");
        else  printf("C=>");

        for(int j = 0; j < peg[i].size(); j++){
            if(j == 0)
                printf("   %d", peg[i][j]);
            else
                printf(" %d", peg[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    count++;
}
