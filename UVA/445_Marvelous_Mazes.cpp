#include <cstdio>
using namespace std;

int main()
{
    char c;
    int count = 0;
    while(c = getchar(), c != EOF){
        if(c >= '0' && c <= '9')
            count += c - '0';
        else if(c >= 'A' && c <= 'Z' || c == '*'){
            while(count--)
                putchar(c);
            count = 0;
        }
        else if(c == 'b'){
            while(count--)
                putchar(' ');
            count = 0;
        }
        else if(c == '\n' || c == '!')
            printf("\n");
    }
    return 0;
}
