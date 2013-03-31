#include <cstdio>
using namespace std;

int ans[21][21][21] = {0};

int f(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return ans[0][0][0];
    if(a > 20 || b > 20 || c > 20)
        return f(20, 20, 20);
    if(ans[a][b][c])
        return ans[a][b][c];
    else if(a < b && b < c)
        return ans[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
    else
        return ans[a][b][c] = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
}

int main()
{
    int a, b, c;
    ans[0][0][0] = 1;
    while(scanf("%d%d%d", &a, &b, &c) && (a != -1 || b != -1 || c != -1))
        printf("w(%d, %d, %d) = %d\n", a, b, c, f(a, b, c));
    return 0;
}
