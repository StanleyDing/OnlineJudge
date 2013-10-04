#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int x, out, mask = 0xFF;
    while(scanf("%d", &x) != EOF){
        out = 0;
        for(int i = 0; i <= 3; i++){
            out |= ((x >> (3-i) * 8) & mask) << i * 8;
        }
        printf("%d converts to %d\n", x, out);
    }
    return 0;
}
