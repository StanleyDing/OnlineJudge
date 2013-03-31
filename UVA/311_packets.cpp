#include <cstdio>

int size[6];

int count();

int main()
{
    while(1){
        for(int i = 0; i < 6; i++)
            scanf("%d", &size[i]);
        if(size[0] || size[1] || size[2] || size[3] || size[4] || size[5])
            printf("%d\n", count());
        else
            break;
    }
    return 0;
}

int count()
{
    int ans = 0, space;
    //size 36
    ans = size[5];
    //size 25
    ans += size[4];
    size[0] -= size[4] * 11;
    //size 16
    while(size[3]--){
        ans++;
        space = 36 - 16;
        if(size[1] >= 5)
            size[1] -= 5;
        else if(size[1] > 0){
            size[0] -= space - 4 * size[1];
            size[1] = 0;
        }
        else
            size[0] -= space;
    }
    //size 9
    ans += size[2] / 4;
    size[2] -= size[2] / 4 * 4;
    if(size[2]){    //size[2] = 1 or 2 or 3
        ans++;
        space = 36 - 9 * size[2];
        if(size[1] >= 7 - 2 * size[2]){
            size[1] -= 7 - 2 * size[2];
            size[0] -= space - 4 * (7 - 2 * size[2]);
        }
        else if(size[1] > 0){
            size[0] -= space - 4 * size[1];
            size[1] = 0;
        }
        else
            size[0] -= space;
    }
    //size 4
    ans += size[1] / 9;
    size[1] -= size[1] / 9 * 9;
    if(size[1]){
        ans++;
        space = 36 - 4 * size[1];
        size[0] -= space;
    }
    //size 1
    if(size[0] >= 36){
        ans += size[0] / 36;
        size[0] -= size[0] / 36 * 36;
    }
    if(size[0] > 0)
        ans++;
    return ans;
}
