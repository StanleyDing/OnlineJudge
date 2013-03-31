#include <cstdio>
#include <stack>
using namespace std;

void check();
char s[200];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            fgets(s, 150, stdin);
            if(s[0] == '\n'){
                printf("Yes\n");
                continue;
            }
            check();
        }
    }
}

void check()
{
    stack<char> stk;
    for(int i = 0; s[i] != '\n'; i++){
        if(s[i] == '(' || s[i] == '[')
            stk.push(s[i]);
        else{
            if(stk.empty() || (s[i] == ')' && stk.top() != '(') || (s[i] == ']' && stk.top() != '[' )){
                printf("No\n");
                return;
            }
            stk.pop();
        }
    }
    if(!stk.empty()){
        printf("No\n");
        return;
    }
    printf("Yes\n");
    while(!stk.empty())
        stk.pop();
}
