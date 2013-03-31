#include <cstdio>
#include <cstring>
using namespace std;

int sets, ROW, COL, ans[9], count;
bool row[9], d1[17], d2[17];

void backtrack(int C);

int main()
{
    bool flag = false;
    scanf("%d", &sets);
    while(sets--){
        if(flag)
            printf("\n");
        flag = true;
        count = 0;
        memset(row, 0, sizeof(row));
        for(int i = 0; i < 17; i++)
            d1[i] = d2[i] = 0;
        scanf("%d%d", &ROW, &COL);
        row[ROW] = true;
        int v1 = (ROW + COL), v2 = (ROW - COL + 15) % 15;
        d1[v1] = d2[v2] = true;
        ans[COL] = ROW;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(1);
    }
    return 0;
}

void backtrack(int C)
{
    if(C == COL){
        backtrack(C + 1);
        return;
    }
    if(C == 9){
        printf("%2d      ", ++count);
        for(int i = 1; i <= 8; i++){
            if(i == 1)
                printf("%d", ans[i]);
            else
                printf(" %d", ans[i]);
        }
        printf("\n");
        return;
    }
    for(int R = 1; R <= 8; R++){
        int v1 = (R + C), v2 = (R - C + 15) % 15;
        if(!row[R] && !d1[v1] && !d2[v2]){
            row[R] = d1[v1] = d2[v2] = true;
            ans[C] = R;
            backtrack(C + 1);
            row[R] = d1[v1] = d2[v2] = false;
        }
    }
}
