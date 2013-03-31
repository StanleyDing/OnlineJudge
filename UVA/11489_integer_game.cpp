#include <cstdio>
#define MAX_C 1001
int main()
{
    int n, sum, mod[3], j, num_case = 0;
    char c[MAX_C];
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            num_case++;
            sum = mod[0] = mod[1] = mod[2] = j = 0;
            gets(c);
            while(c[j] != '\0'){
                sum += c[j] - '0';
                if(c[j] == '3' || c[j] == '6' || c[j] == '9')
                    mod[0]++;
                else if(c[j] == '1' || c[j] == '4' || c[j] == '7')
                    mod[1]++;
                else
                    mod[2]++;
                j++;
            }
            if(sum % 3 != 0){
                if(mod[sum%3] == 0 || mod[0] % 2 == 1)
                    printf("Case %d: T\n", num_case);
                else
                    printf("Case %d: S\n", num_case);
            }
            else{
                if(mod[0] % 2 == 0)
                    printf("Case %d: T\n", num_case);
                else
                    printf("Case %d: S\n", num_case);
            }
        }
    }
    return 0;
}
