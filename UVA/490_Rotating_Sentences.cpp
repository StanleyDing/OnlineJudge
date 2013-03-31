#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char sen[105][105];
    int i = 0, length[100], maxLength = 0;
    while(fgets(sen[i], 105, stdin) != NULL){
        length[i] = strlen(sen[i]);
        maxLength = max(maxLength, length[i]);
        i++;
    }
    maxLength--;    //exclude the newline character
    for(int j = 0; j < maxLength; j++){
        for(int k = i - 1; k >= 0; k--){
            if(j >= length[k] || sen[k][j] == '\n')
                putchar(' ');
            else if(j < length[k])
                putchar(sen[k][j]);
        }
        printf("\n");
    }
    return 0;
}
