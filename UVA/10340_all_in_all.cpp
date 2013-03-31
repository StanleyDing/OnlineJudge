#include <cstdio>
#include <cstring>

char s1[100001], s2[100001];

int main()
{
    int match;
    int i1, i2;     //index1, index2
    int l1, l2;
    while(scanf("%s %s", s1, s2) != EOF){
        match = i2 = 0;
        l1 = strlen(s1);
        l2 = strlen(s2);
        for(i1 = 0; i1 < l1; i1++){
            while(i2 != l2 && s1[i1] != s2[i2++]);
            if(s2[i2-1] == s1[i1])
                match++;
            if(i2 == l2)
                break;
        }
        if(match == l1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
