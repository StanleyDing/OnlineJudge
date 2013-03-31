#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#define MAX_C 25
using namespace std;

int main()
{
    char c[MAX_C], e[MAX_C], f[MAX_C];
    map<string, string> d;
    while(1){
        gets(c);
        if(c[0] == '\0')
            break;
        sscanf(c, "%s %s", e, f);
        d[f] = e;
    }
    while(gets(c)){
        if(d[c] != "\0")
            cout << d[c] << endl;
        else
            printf("eh\n");
    }
    return 0;
}
