#include<cstdio>
#include<iostream>
#include<cctype>
using namespace std;

int main()
{
    bool first_quote = true;
    char c;
    while(c = getchar()){
        if(c == EOF)
            break;
        if(c == '"' && first_quote){
            putchar('`'), putchar('`');
            first_quote = false;
            continue;
        }
        else if(c == '"' && !first_quote){
            putchar('\''), putchar('\'');
            first_quote = true;
            continue;
        }
        putchar(c);
    }
    return 0;
}
