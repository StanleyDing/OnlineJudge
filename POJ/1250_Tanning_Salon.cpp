#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int customerState[26];  //0 = yet to come, 1 = sale, 2 = lost
    char c;
    while(scanf("%d", &n), n){
        getchar();
        memset(customerState, 0, sizeof(customerState));
        int slot = n, lost = 0;

        while(c = getchar(), c != '\n'){
            if(customerState[c-'A'] == 1)                       //tanned customer left
                slot++;
            else if(customerState[c-'A'] == 0 && slot != 0){    //slot available
                slot--;
                customerState[c-'A'] = 1;
            }
            else if(customerState[c-'A'] == 0){                 //no slot, customer left
                lost++;
                customerState[c-'A'] = 2;
            }
        }
        if(!lost)
            printf("All customers tanned successfully.\n");
        else
            printf("%d customer(s) walked away.\n", lost);
    }
    return 0;
}
