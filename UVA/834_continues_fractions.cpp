#include <iostream>
#include <cstdio>
using namespace std;

void f(int, int, bool);

int main()
{
    int a, b;
    while(cin >> a >>b){
        f(a, b, true);
    }
    return 0;
}

void f(int a, int b, bool first)
{
    int i = a / b;
    if(b == 1){
        printf("%d]\n", a);
        return;
    }
    else if(first)
        printf("[%d;", i);
    else
        printf("%d,", i);
    f(b, a - i * b, false);
}
