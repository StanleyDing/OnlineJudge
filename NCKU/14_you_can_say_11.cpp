#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

char str[10000];

int main()
{
    int dif, even, odd;

    while(scanf("%s", str) && strcmp(str, "0") != 0){
        int slength = strlen(str);
        even = odd = 0;

        for(int i = 0; i < slength; i++){
            if(i % 2 == 0)
                even += str[i] - '0';
            else
                odd += str[i] - '0';
        }
        if(even > odd)
            dif = even - odd;
        else
            dif = odd - even;
        if(dif % 11 == 0)
            printf("%s is a multiple of 11.\n", str);
        else
            printf("%s is not a multiple of 11.\n", str);
    }
    return 0;
}
