#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Box{
    int id, length, prev;
    int d[10];
    bool operator<(const Box &t) const{
        for(int i = 0; i < 10; i++){
            if(d[i] == t.d[i])
                continue;
            else
                return d[i] < t.d[i];
        }
        return id < t.id;
    }
} box[35];

bool fit(Box a, Box b, int D);
void trace(int);

int main()
{
    int N, D, len, index;
    while(scanf("%d%d", &N, &D) != EOF){
        for(int i = 0; i < N; i++){
            box[i].id = i + 1;
            box[i].length = 1;
            box[i].prev = -1;
            memset(box[i].d, 0, sizeof(box[i].d));

            for(int j = 0; j < D; j++)
                scanf("%d", &box[i].d[j]);

            sort(box[i].d, box[i].d + D);
        }

        sort(box, box + N);
        for(int i = 0; i < N; i++)
            for(int j = i+1; j < N; j++)
                if(fit(box[i], box[j], D))
                    if(box[j].length < box[i].length + 1){
                        box[j].length = box[i].length + 1;
                        box[j].prev = i;
                    }

        len = index = 0;
        for(int i = 0; i < N; i++)
            if(box[i].length > len){
                len = box[i].length;
                index = i;
            }

        printf("%d\n", len);
        trace(index);
        printf("\n");
    }
    return 0;
}

bool fit(Box a, Box b, int D)
{
    for(int i = 0; i < D; i++)
        if(a.d[i] >= b.d[i])
            return false;
    return true;
}

void trace(int index)
{
    if(box[index].prev != -1){
        trace(box[index].prev);
        printf(" %d", box[index].id);
    }
    else
        printf("%d", box[index].id);
}
