#include <cstdio>
#include <cstring>
using namespace std;

int fib[5005][1500];
bool done[5005];

void Fib(int n);
void add(int a[1500], int b[1500], int c[1500]);

int main()
{
    int n, i;
    while(scanf("%d", &n) != EOF){
        printf("The Fibonacci number for %d is ", n);

        Fib(n);
        i = 1500 - 1;
        while(i >= 0 && fib[n][i] == 0)
            i--;
        if(i < 0) 
            printf("%d", 0);
        else
            while(i >= 0)
                printf("%d", fib[n][i--]);
        printf("\n");
    }
    return 0;
}

void Fib(int n)
{
    if(n == 0){
        fib[0][0] = 0;
        return;
    }
    if(n == 1){
        fib[1][0] = 1;
        return;
    }
    if(done[n])
        return;

    Fib(n-1), Fib(n-2);
    add(fib[n-1], fib[n-2], fib[n]);
    done[n] = true;
}

void add(int a[1500], int b[1500], int c[1500])
{
    for(int i = 0; i < 1500; i++)
        c[i] = a[i] + b[i];
    for(int i = 1; i < 1500; i++){
        c[i] += c[i-1] / 10;
        c[i-1] %= 10;
    }
}
